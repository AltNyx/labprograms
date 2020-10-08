import java.util.Scanner;
/**
 * KnapsackDp
 */
public class KnapsackDp {

    static void knapsack(int num_items, int capacity, int weight_arr[], int profit_arr[], int v[][]) {
        for(int i = 0; i <= num_items; i++)
            for(int w = 0; w <= capacity; w++) {
                if(i == 0 || w == 0)
                    v[i][w] = 0;
                else if(weight_arr[i] > w)
                    v[i][w] = v[i - 1][w];
                else
                    v[i][w] = max(v[i - 1][w], v[i - 1][w - weight_arr[i]] + profit_arr[i]);
            }
    }

    private static int max(int i, int j) {
        return i < j ? j : i;
    }

    static void displayInfo(int num_items, int capacity, int w[], int p[]) {
        System.out.println("Entered information about knapsack problem are:");
        System.out.println("ITEM\tPROFIT\tWEIGHT");
        for(int i = 1; i <= num_items; i++) {
            System.out.println(i + "\t" + p[i] + "\t" + w[i]);
        }
        System.out.println("\nCAPACITY = " + capacity);
    }

    static void optimal(int num_items, int capacity, int[] weight_arr, int[][] v) {
        int[] k = new int[num_items + 1];
        int i, j;
        for(i = num_items, j = capacity; (i != 0 && j != 0); i--) {
            if(v[i][j] != v[i - 1][j]) {
                k[i] = 1;
                j = j - weight_arr[i];
            }
        }
        System.out.println("\nThe items selected are:");
        for(i = 1; i <= num_items; i++)
            System.out.println("K["+ i + "] --> " + k[i]);
        System.out.println("\nThe maximum profit is: " + v[num_items][capacity]);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("***************KNAPSACK PROBLEM***************");
        System.out.print("Enter number of items:");
        int n = sc.nextInt();
        int w[] = new int[n + 1];
        int p[] = new int[n + 1];
        System.out.println("Enter weight of each item:");
        for(int i = 1; i <= n; i++)
            w[i] = sc.nextInt();
        System.out.println("Enter profit of each item:");
        for(int i = 1; i <= n; i++)
            p[i] = sc.nextInt();
        System.out.print("Enter the knapsack capacity:");
        int m = sc.nextInt();
        int v[][] = new int[n + 1][m + 1];
        displayInfo(n, m, w, p);
        knapsack(n, m, w, p, v);
        System.out.println("\nThe contents of knapsack table are:");
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++)
                System.out.print(v[i][j] + " ");
            System.out.println();
        }
        optimal(n, m, w, v);

        sc.close();
    }
}