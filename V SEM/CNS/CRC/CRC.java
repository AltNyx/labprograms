import java.util.Scanner;

public class CRC {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] divisor = { 1, 1, 0, 0, 1 };
        int m = divisor.length;

        System.out.print("Enter number of message bits: ");
        int n = sc.nextInt();
        int[] message = new int[n];

        System.out.print("Enter the message bits: ");
        for (int i = 0; i < n; i++)
            message[i] = sc.nextInt();

        int[] remainder = generate(message, divisor);

        System.out.print("The remainder is: ");
        for (int i = 0; i < m - 1; i++)
            System.out.print(remainder[i]);

        System.out.print("\nThe CRC code is: ");
        for (int i = 0; i < n; i++)
            System.out.print(message[i]);
        for (int i = 0; i < m - 1; i++)
            System.out.print(remainder[i]);

        int[] recievedData = new int[n + m - 1];
        System.out.print("\nEnter the recieved data: ");
        for (int i = 0; i < n + m - 1; i++)
            recievedData[i] = sc.nextInt();

        if (verify(recievedData, divisor)) {
            System.out.println("No error in recieved data!");
        } else {
            System.out.println("ERROR in recived data!");
        }

        sc.close();

    }

    static int[] generate(int[] message, int[] divisor) {
        int n = message.length;
        int m = divisor.length;

        int[] divident = new int[n + m];
        System.arraycopy(message, 0, divident, 0, n);
        // divident -> message appended with m-1 zeroes

        int[] remainder = new int[m];
        System.arraycopy(divident, 0, remainder, 0, m);

        for (int i = 0; i < n; i++) {
            int msb = remainder[0];
            if (msb == 0) {
                for (int j = 1; j < m; j++)
                    remainder[j - 1] = remainder[j];
            } else {
                for (int j = 1; j < m; j++)
                    remainder[j - 1] = remainder[j] ^ divisor[j];
            }

            remainder[m - 1] = divident[i + m];
        }

        return remainder;
    }

    static boolean verify(int[] recievedData, int[] divisor) {
        int[] remainder = generate(recievedData, divisor);
        for (int i = 0; i < remainder.length - 1; i++) {
            if (remainder[i] == 1)
                return false;
        }
        return true;
    }
}