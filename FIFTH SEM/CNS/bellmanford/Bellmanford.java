package prog6;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Creating a custom class for edges
class Edge {
    int src;
    int dest;
    int weight;

    Edge(int src, int dest, int weight) {
        this.src = src;
        this.dest = dest;
        this.weight = weight;
    }
}

public class Bellmanford {
    static int V, E, source;
    static List<Edge> edges = new ArrayList<>();
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter number of vertices: ");
        V = sc.nextInt();

        System.out.print("Enter number of edges: ");
        E = sc.nextInt();

        // Read all edges
        System.out.println("Enter source, destination, weight of every edge: ");
        for (int i = 0; i < E; i++) {
            int src = sc.nextInt();
            int dest = sc.nextInt();
            int weight = sc.nextInt();
            edges.add(new Edge(src, dest, weight));
        }

        // Read source vertex
        System.out.print("Enter source vertex: ");
        source = sc.nextInt();

        System.out.println();
        bellmanford();
    }

    static void printPath(int parent[], int vertex) {
        if (vertex < 0)
            return;

        printPath(parent, parent[vertex]);
        System.out.print(vertex + " ");
    }

    static void bellmanford() {
        // Initialise
        int[] distance = new int[V];
        int[] parent = new int[V];
        Arrays.fill(distance, Integer.MAX_VALUE); // Set all to INF
        distance[source] = 0; // Set source to 0
        Arrays.fill(parent, -1); // Set all to -1

        // Relax V-1 times
        for (int i = 0; i < V - 1; i++) {
            for (Edge edge : edges) {
                int u = edge.src;
                int v = edge.dest;
                int w = edge.weight;

                if (distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w; // Update distance
                    parent[v] = u; // Set v's parent to u
                }
            }
        }

        // Relax one more time to find negative edge cycle
        for (Edge edge : edges) {
            if (distance[edge.src] + edge.weight < distance[edge.dest]) {
                System.out.println("Negative Weight Cycle Found!");
                return;
            }
        }

        // Print Distance
        for (int i = 0; i < V; i++) {
            String dist = String.format("Distance from %d to %d is %d.", source, i, distance[i]);
            System.out.print(dist + " It's path is [ ");
            printPath(parent, i);
            System.out.println("]");
        }
    }
}