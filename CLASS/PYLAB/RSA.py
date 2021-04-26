from math import sqrt
import random

PRIME_LIMIT = 10**6

def isprime(n: int) -> bool:
    '''Check whether a number is prime or not

    Example:

        >>> isprime(37)
        True
        >>> isprime(201) 
        False
        >>> 

    '''
    if n <= 3:
        return n > 1
    
    if n%2 == 0 or n%3==0:
        return False
    
    for i in range(5, int(sqrt(n)) + 1, 6):
        if n%i == 0 or n%(i+2) == 0: 
            return False
    
    return True

def get_prime(limit: int = PRIME_LIMIT) -> int:
    '''Returns a prime number within the given limit

    Example:

        >>> get_prime() # default limit set to 10**6
        671939
        >>> get_prime(100) 
        5

    '''
    num = 0
    while not isprime(num):
        num = random.randint(0, limit)
    
    return num

def gcd(n: int, m: int) -> int:
    '''Compute the gcd to 2 numbers

    Example:

        >>> gcd(2, 3) 
        1
        >>> gcd(12, 18) 
        6

    '''
    while m:
        n, m = m, n%m
    
    return n

class RSA:
    def __init__(self, p: int, q: int) -> None:
        self.p = p
        self.q = q
        self.n = p*q
        self.phi = (p-1) * (q-1)
    
    def generate_public_key(self) -> int:
        '''Compute the public key e such that

        1 < e < phi // where phi = (p-1) * (q-1)
        and
        gcd(e, phi) = 1 // e and phi are coprime
        
        '''
        e = get_prime()
        while not (1 < e < self.phi or gcd(e, self.phi) == 1):
            e += 1
        return e
    
    def generate_private_key(self, e: int) -> int:
        '''Compute the private key d such that
        
        d = e^-1 mod phi
        or 
        d*e = 1 mod phi 
        
        '''
        return pow(e, -1, mod=self.phi)
    
    def encrypt(self, msg: str, e: int) -> list[int]:
        '''Encrypt the msg char by char and return it as a list of int'''
        return [pow(ord(c), e, self.n) for c in msg]
    
    def decrypt(self, cipher_text: list[int], d: int) -> str:
        '''Decrypt all the numbers one by one and join them to form a string'''
        return ''.join(chr(pow(c, d, self.n)) for c in cipher_text)



if __name__ == "__main__":
    p, q = get_prime(), get_prime()
    rsa = RSA(p, q)

    e = rsa.generate_public_key()
    d = rsa.generate_private_key(e)

    msg = input("Enter a message: ")
    cipher_text = rsa.encrypt(msg, e)

    print("Cipher text:", cipher_text)
    print("Decrypted text:", rsa.decrypt(cipher_text, d))