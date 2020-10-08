import java.util.Scanner;

/**
 * Floyd
 */
public class Floyd {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("------------FLOYD'S ALGORITHM-------------");
        System.out.print("Enter number of vertices: ");
        int n = sc.nextInt();
        int[][] adj = new int[n][n];
        System.out.println("Enter adjacency matrix: ");

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                adj[i][j] = sc.nextInt();
            System.out.println();
        }
        
        System.out.println("\nEntered adjacency matrix is: ");

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                System.out.print(adj[i][j] + "\t");
            }
            System.out.println();
        }

        floydalgo(adj, n);
        System.out.println("\nAll pair shortest path matrix is: ");
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                System.out.print(adj[i][j] + "\t");
            }
            System.out.println();
        }
        sc.close();
    }

    static void floydalgo(int[][] arr, int n) {
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
    }

    static int min(int num1, int num2) {
        return num1 < num2 ? num1 : num2;
    }
}