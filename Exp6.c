#include <stdio.h>
#include <limits.h>   // For INT_MAX

int main() {
    int V, E;   // Number of vertices and edges

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Arrays to store edges
    int u[E], v[E], w[E];

    printf("Enter each edge in the format: u v weight\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Step 1: Initialize distances
    int dist[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    // Step 2: Relax edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            if (dist[u[j]] != INT_MAX &&
                dist[u[j]] + w[j] < dist[v[j]]) {
                dist[v[j]] = dist[u[j]] + w[j];
            }
        }
    }

    // Step 3: Check for negative weight cycles
    int negative_cycle = 0;   // Flag to indicate if a negative cycle exists
    for (int j = 0; j < E; j++) {
        if (dist[u[j]] != INT_MAX &&
            dist[u[j]] + w[j] < dist[v[j]]) {
            negative_cycle = 1;
            break;
        }
    }

    // Step 4: Print result
    if (negative_cycle) {
        printf("Graph contains a negative weight cycle\n");
    } else {
        printf("No negative weight cycle found.\n");
        printf("Vertex\tDistance from Source\n");

        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX)
                printf("%d\tInfinity\n", i);
            else
                printf("%d\t%d\n", i, dist[i]);
        }
    }

    return 0;
}