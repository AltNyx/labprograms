import java.util.Scanner;

public class Prims {

    static int primAlgo(int[][] cost, int n) {
        int mincost = 0;
        int min;
        int u = 0, v = 0;
        int numEdges = 1;
        int[] visited = new int[n];
        visited[0] = 1;
        while(numEdges < n) {
            min = 999;
            for(int i = 0; i < n; i++) {
                if(visited[i] == 1) {
                    for(int j = 0; j < n; j++) {
                        if(min > cost[i][j] && cost[i][j] != 0 && visited[j] == 0) {
                            min = cost[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }

            numEdges += 1;
            mincost += min;
            visited[v] = 1;
            System.out.println("Edge selected -> (" + u + ", " + v + ") cost -> " + min);
            cost[u][v] = cost[v][u] = 999;
        }
        return mincost;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();
        int[][] cost = new int[n][n];
        System.out.println("Enter the adjacency matrix: ");
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cost[i][j] = sc.nextInt();
        int mincost = primAlgo(cost, n);
        System.out.println("The minimum cost of spanning tree is: " + mincost);
        sc.close();
    }
}