#include <stdio.h>
#define INF 999
#define N 3  // Number of routers

void dijkstra(int graph[N][N], int src) {
    int dist[N], visited[N] = {0}, i, j, min, u;

    for (i = 0; i < N; i++)
        dist[i] = INF;  // Initialize distances

    dist[src] = 0;  // Source node distance is 0

    for (i = 0; i < N - 1; i++) {
        min = INF;

        for (j = 0; j < N; j++)
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }

        visited[u] = 1;

        for (j = 0; j < N; j++)
            if (!visited[j] && graph[u][j] && dist[u] + graph[u][j] < dist[j])
                dist[j] = dist[u] + graph[u][j];
    }

    printf("Router Distance Table:\n");
    for (i = 0; i < N; i++)
        printf("To %d: %d\n", i, dist[i]);
}

int main() {
    int graph[N][N] = { {0, 2, INF}, {2, 0, 3}, {INF, 3, 0} };

    dijkstra(graph, 0);  // Start from router 0

    return 0;
}
