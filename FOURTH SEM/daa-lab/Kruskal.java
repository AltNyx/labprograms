import java.util.Scanner;

public class Kruskal {

    static int kruskalAlgo(int[][] cost, int n) {
        int mincost = 0;
        int numEdges = 1;
        int min, u = 0, v = 0, v1 = 0, v2 = 0;
        int[] parent = new int[n+1];
        while(numEdges < n) {
            min = 999;
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    if(min > cost[i][j] && i != j) {
                        min = cost[i][j];
                        u = v1 = i;
                        v = v2 = j;
                    }
                }
            }

            while(parent[u] > 0)
                u = parent[u];
            while(parent[v] > 0)
                v = parent[v];
            
            if(u != v) {
                System.out.println("Edge selected -> (" + v1 + ", " + v2 + ") cost -> " + min);
                parent[v] = u;
                mincost += min;
                numEdges += 1;
            }
            cost[v1][v2] = cost[v2][v1] = 999;

        }
        return mincost;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of vertices: ");
        int n = sc.nextInt();
        System.out.println("Enter the adjacency matrix: ");
        int[][] cost = new int[n+1][n+1];
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                cost[i][j] = sc.nextInt();
        System.out.println();
        int mincost = kruskalAlgo(cost, n);
        System.out.println("The minumum cost of the spanning tree is: " + mincost);
        sc.close();
    }
}