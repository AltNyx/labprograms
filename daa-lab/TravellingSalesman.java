import java.util.Scanner;

public class TravellingSalesman {

    static int minCost(int n, int[][] cost, int[] path, int start) {
        int[] minpath = new int[n+1];
        int[] temp = new int[n+1];
        int mincost = 999;
        int curcost, i, j, k;

        if(start == n-1) {
            return (cost[path[n-1]][path[n]] + cost[path[n]][1]);
        }

        for(i = start+1; i<= n; i++) {
            for(j = 1; j<=n; j++)
                temp[j] = path[j];
        
            temp[start+1] = path[i];
            temp[i] = path[start+1];

            if((cost[path[start]][path[i]] + (curcost = minCost(n, cost, temp, start + 1))) < mincost) {
                mincost = cost[path[start]][path[i]] + curcost;
                for(k = 1; k <= n; k++)
                minpath[k] = temp[k];
            }

        }

        for(i = 1; i <= n; i++)
            path[i] = minpath[i];
        return mincost;
        


    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of cities: ");
        int n = sc.nextInt();
        if(n == 1) {
            System.out.println("Only one city is present!");
            sc.close();
            return;
        }
        int[][] cost = new int[n+1][n+1];
        int[] path = new int[n+1];
        System.out.println("Enter the adjacency matrix: ");
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                cost[i][j] = sc.nextInt();
        for(int i = 1; i <= n; i++)
            path[i] = i;
        int mincost = minCost(n, cost, path, 1);
        System.out.print("The minpath is: ");
        for(int i = 1; i <= n; i++)
            System.out.print(path[i] + " -> ");
        System.out.println("1");
        System.out.println("\nThe mincost is: " + mincost);
        sc.close();
    }
}