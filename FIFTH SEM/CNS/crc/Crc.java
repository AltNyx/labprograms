package prog4;
import java.util.Scanner;

public class Crc {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the message
        System.out.print("Enter number of message bits: ");
        int n = sc.nextInt();
        int[] M = new int[n];
        System.out.print("Enter the message bits: ");
        for (int i = 0; i < n; i++) M[i] = sc.nextInt();

        // Read the genrator/divisor
        System.out.print("Enter number of generator bits: ");
        int m = sc.nextInt();
        int[] G = new int[m];
        System.out.print("Enter the generator bits: ");
        for (int i = 0; i < m; i++) G[i] = sc.nextInt();

        // Evaluate the remainder
        int[] R = generate(M, G);
        System.out.print("The remainder is: ");
        for(int i = 0; i < m-1; i++) System.out.print(R[i]);
        System.out.print("\nThe CRC code is: ");
        for(int i = 0; i < n; i++) System.out.print(M[i]);
        for(int i = 0; i < m-1; i++) System.out.print(R[i]);

        // Read thr recieved data
        int[] RD = new int[n+m-1];
        System.out.print("\nEnter the data recieved: ");
        for(int i = 0; i < n+m-1; i++) RD[i] = sc.nextInt();

        // Verify the recieved data
        verify(RD, G);
        sc.close();
    }

    static int[] generate(int[] M, int[] G) {
        int n = M.length;
        int m = G.length;
        int[] data = new int[n+m];
        System.arraycopy(M, 0, data, 0, M.length);
        int[] R = new int[m];
        System.arraycopy(data, 0, R, 0, G.length);

        for(int i = 0; i < n; i++) {
            int MSB = R[0];
            for(int j = 1; j < m; j++) {
                if(MSB==1) R[j-1] = R[j]^G[j];
                else R[j-1] = R[j]^0;
            }
            R[m-1] = data[i+m];
        }
        return R;
    }

    static void verify(int[] RD, int[] G) {
        int[] R = generate(RD, G);
        for(int i = 0; i < R.length; i++) {
            if(R[i] != 0) {
                System.out.println("The is an ERROR in the data recieved!");
                return;
            }
        }
        System.out.println("NO ERROR in recieved data!");
    }
}