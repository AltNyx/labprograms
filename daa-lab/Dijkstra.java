import java.util.Scanner;

public class Dijkstra {
    int[] distance = new int[10];
    int[] path = new int[10];
    int[] visited = new int[10];

    public void dijkAlgo(int[][] cost, int source, int n) {
        int u = -1;
        int min;
        
        //initializing distance and path vectors
        for(int v = 0; v < n; v++) {
            distance[v] = 99;
            path[v] = -1;
        }
        distance[source] = 0; //distance from source to source is 0

        for(int i = 0; i < n; i++) {
            min = 99;
            for(int j = 0; j < n; j++) {
                if(distance[j] < min && visited[j] == 0) {
                    min = distance[j];
                    u = j;
                }
            }
            visited[u] = 1;

            for(int v = 0; v < n; v++) {
                if((distance[u] + cost[u][v] < distance[v]) && (u != v) && (visited[v] == 0)) {
                    distance[v] = distance[u] + cost[u][v];
                    path[v] = u;
                }
            }
        }
    }

    //to print shortest path from source vertex to given vertex
    void printPath(int vertex, int source) {
        if(path[vertex] != -1)
            printPath(path[vertex], source);
        if(vertex != source)
            System.out.print("-> " + vertex + " ");
    }

    void display(int source, int n) {
        for(int i = 0; i < n; i++) {
            if(i != source) {
                System.out.print(source + " ");
                printPath(i, source);
                System.out.println("= " + distance[i]);
            }
        }
    }
    public static void main(String[] args) {
        int[][] cost = new int[10][10];
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of vertices: ");
        int n = sc.nextInt();
        System.out.println("Enter the weighted matrix: ");
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cost[i][j] = sc.nextInt();
        System.out.print("Enter the source vertex: ");
        int source = sc.nextInt();
        Dijkstra obj = new Dijkstra();
        obj.dijkAlgo(cost, source, n);
        System.out.println("The shortest path from source " + source + " to remaining vertices are: ");
        obj.display(source, n);
        sc.close();
    }
}