#include <stdio.h>

#define INF 999

int main()
{
    int cost[20][20];
    int visited[20] = {0};
    int n, i, j;
    int edges = 0;
    int min, a = 0, b = 0;
    int totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    printf("Enter 0 if there is no edge:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    /* Start from first vertex */
    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n - 1)
    {
        min = INF;

        for (i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        printf("%d -> %d  Cost = %d\n", a + 1, b + 1, min);

        totalCost += min;
        visited[b] = 1;
        edges++;
    }

    printf("\nMinimum Cost of Spanning Tree = %d\n", totalCost);

    return 0;
}