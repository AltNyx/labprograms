import java.util.Scanner;

public class CRC {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Generator or divisor
        int[] GEN = { 1, 1, 0, 0, 1 };
        int m = GEN.length;

        // Read the message
        System.out.print("Enter number of message bits: ");
        int n = sc.nextInt();
        int[] MSG = new int[n];
        System.out.print("Enter the message bits: ");
        for (int i = 0; i < n; i++)
            MSG[i] = sc.nextInt();

        // Evaluate the remainder
        int[] REM = generate(MSG, GEN);

        System.out.print("The remainder is: ");
        for (int i = 0; i < m - 1; i++)
            System.out.print(REM[i]);

        System.out.print("\nThe CRC code is: ");
        for (int i = 0; i < n; i++)
            System.out.print(MSG[i]);
        for (int i = 0; i < m - 1; i++)
            System.out.print(REM[i]);

        // Read the recieved data
        int[] RD = new int[n + m - 1];
        System.out.print("\nEnter the data recieved: ");
        for (int i = 0; i < n + m - 1; i++)
            RD[i] = sc.nextInt();

        // Verify the recieved data
        verify(RD, GEN);
        sc.close();
    }

    static int[] generate(int[] MSG, int[] GEN) {
        int n = MSG.length;
        int m = GEN.length;

        int[] data = new int[n + m];
        System.arraycopy(MSG, 0, data, 0, n);
        int[] REM = new int[m];
        System.arraycopy(data, 0, REM, 0, m);

        for (int i = 0; i < n; i++) {
            int MSB = REM[0];

            if (MSB == 1) {
                for (int j = 1; j < m; j++)
                    REM[j - 1] = REM[j] ^ GEN[j];
            } else {
                for (int j = 1; j < m; j++)
                    REM[j - 1] = REM[j] ^ 0;
            }

            REM[m - 1] = data[i + m];
        }
        return REM;
    }

    static void verify(int[] RD, int[] GEN) {
        int[] REM = generate(RD, GEN);
        for (int i = 0; i < REM.length; i++) {
            if (REM[i] != 0) {
                System.out.println("There is an ERROR in the data recieved!");
                return;
            }
        }
        System.out.println("NO error in recieved data!");
    }
}