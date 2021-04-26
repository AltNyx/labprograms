class CRC:
    @staticmethod
    def xor(x: str, y: str) -> str:
        '''Compute the xor of 2 binary numbers represented as strings
        
        Example:
            
            >>> CRC.xor("1101", "0011")
            '1110'
            >>> CRC.xor("11010", "00001")
            '11011'

        '''
        return bin(int(x, base=2) ^ int(y, base=2))[2:].zfill(len(x))
    
    @staticmethod
    def generate(msg: str, gen: str) -> str:
        '''Generates the remainder
        
        Example:

            >>> CRC.generate("110011", "11001")
            '1001'
            >>> CRC.generate("1110111", "11001") 
            '1100'
        
        '''
        m = len(gen)
        data = msg + '0'*m
        rem = data[:m]
        for i in range(len(msg)):
            msb = rem[0]
            if msb == '1': rem = CRC.xor(rem, gen)
            rem = rem[1:] + data[i+m]
        
        return rem[:-1]
    
    @staticmethod
    def verify(recieved: str, gen: str) -> bool:
        '''Check is the recieved data is valid or not
        
        Example:

            >>> CRC.verify("1100111001", "11001")
            True
            >>> CRC.verify("1100111000", "11001") 
            False
            
        '''
        return '1' not in CRC.generate(recieved, gen)


if __name__ == "__main__":
    msg = input("Enter the msg: ")
    gen = '11001'

    rem = CRC.generate(msg, gen)
    print(f"Remainder is: {rem}")
    print(f"CRC Code is: {msg+rem}")

    recieved = input("Enter the recived data: ")
    print("No Error!") if CRC.verify(recieved, gen) else print("Error!")