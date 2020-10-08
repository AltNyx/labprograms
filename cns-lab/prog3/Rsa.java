package prog3;

import java.io.BufferedReader;
import java.io.IOException;
import java.math.BigInteger;
import java.security.SecureRandom;
import java.io.InputStreamReader;

/**
 * Rsa
 */
public class Rsa {
    BigInteger p;
    BigInteger q;
    BigInteger N;
    BigInteger phi;
    BigInteger e;
    BigInteger d;
    int bitLength = 128;
    SecureRandom r;
    BigInteger one = BigInteger.ONE;

    public Rsa() {
        r = new SecureRandom();
        p = new BigInteger(bitLength / 2, 100, r); // prime p
        q = new BigInteger(bitLength / 2, 100, r); // prime q
        N = p.multiply(q); // N = p*q
        phi = p.subtract(one).multiply(q.subtract(one)); // phi(n) = (p-1)*(q-1)
        e = new BigInteger(bitLength / 2, 100, r); // 1 < gcd(e, phi) < phi(n) [Public key]
        while (phi.gcd(e).compareTo(one) > 0 && e.compareTo(phi) < 0) {
            e.add(one);
        }
        d = e.modInverse(phi); // d*e = 1 mod (phi(n)) [Private key]
    }

    public void printValues() {
        System.out.println("Prime p: " + this.p);
        System.out.println("Prime q: " + this.q);
        System.out.println("N: " + this.N);
        System.out.println("Phi(N): " + this.phi);
        System.out.println("Public key e: " + this.e);
        System.out.println("Private key d: " + this.d);
    }

    public BigInteger encrypt(BigInteger plainText) {
        return plainText.modPow(this.e, this.N);
    }

    public BigInteger decrypt(BigInteger cipherText) {
        return cipherText.modPow(this.d, this.N);
    }

    public static void main(String[] args) throws IOException {
        Rsa rsa = new Rsa();
        rsa.printValues();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // Reading plain text
        System.out.println("\nEnter plain text: ");
        String plainText = br.readLine();
        BigInteger plainTextBytes = new BigInteger(plainText.getBytes());

        // Encrypting plain text
        BigInteger cipherText = rsa.encrypt(plainTextBytes);
        System.out.println("CipherText: " + cipherText);

        // Decrypting plain text
        plainTextBytes = rsa.decrypt(cipherText);
        String decryptedText = new String(plainTextBytes.toByteArray());
        System.out.println("Decrypted Text: " + decryptedText);

    }
}