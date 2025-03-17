
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 4

void BFS(int G[V][V], int start) {
    #define WHITE 0
    #define GRAY 1
    #define BLACK 2

    int color[V];
    int prev[V];
    int d[V];

    for (int u = 0; u < V; u++) {
        color[u] = WHITE;
        prev[u] = -1;
        d[u] = INT_MAX;
    }

    int Q[V];
    int front = 0, rear = 0;

    int s = start;

    color[s] = GRAY;
    d[s] = 0;
    prev[s] = -1;

    Q[rear++] = s;

    while (front < rear) {
        int u = Q[front++];

        for (int v = 0; v < V; v++) {
            if (G[u][v] == 1 && color[v] == WHITE) {
                color[v] = GRAY;
                d[v] = d[u] + 1;
                prev[v] = u;
                Q[rear++] = v;
            }
        }

        color[u] = BLACK;
        printf("Visited: %c\n", 'a' + u);
    }
}

int main() {
    int G[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 0}
    };

    int startVertex = 0;
    BFS(G, startVertex);

    return 0;
}