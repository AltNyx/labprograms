import java.io.IOException;
import java.math.BigInteger;
import java.security.SecureRandom;
import java.util.Scanner;

public class RSA {
    BigInteger one = BigInteger.ONE;
    BigInteger p, q, n, phi, e, d;
    int bitLength = 128;
    SecureRandom r;

    public RSA() {
        r = new SecureRandom();
        p = new BigInteger(bitLength / 2, 100, r); // prime p
        q = new BigInteger(bitLength / 2, 100, r); // prime q
        n = p.multiply(q); // n = p*q
        phi = p.subtract(one).multiply(q.subtract(one)); // phi = (p-1)*(q-1)
        e = new BigInteger(bitLength / 2, 100, r); // 1 < e < phi and gcd(e, phi) = 1
        d = e.modInverse(phi); // d*e = 1 mod (phi(n)) [Private key]

        // NOTE: since e is less than phi and also e is prime,
        // both the conditions (1 < e < phi) and gcd(e, phi) = 1 are satisfied
    }

    public void printValues() {
        System.out.println("Prime p: " + this.p);
        System.out.println("Prime q: " + this.q);
        System.out.println("N: " + this.n);
        System.out.println("Phi(N): " + this.phi);
        System.out.println("Public key e: " + this.e);
        System.out.println("Private key d: " + this.d);
    }

    public BigInteger encrypt(BigInteger plainText) {
        return plainText.modPow(this.e, this.n);
    }

    public BigInteger decrypt(BigInteger cipherText) {
        return cipherText.modPow(this.d, this.n);
    }

    public static void main(String[] args) throws IOException {
        RSA rsa = new RSA();
        rsa.printValues();
        Scanner sc = new Scanner(System.in);

        // Reading plain text
        System.out.print("\nEnter plain text: ");
        String plainText = sc.nextLine();

        // Encrypting plain text
        BigInteger cipherText = rsa.encrypt(new BigInteger(plainText.getBytes()));
        System.out.println("CipherText: " + cipherText);

        // Decrypting plain text
        String decryptedText = new String(rsa.decrypt(cipherText).toByteArray());
        System.out.println("Decrypted Text: " + decryptedText);

        sc.close();
    }
}