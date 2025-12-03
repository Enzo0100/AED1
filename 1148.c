#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF 1000000
#define MAX_N 501 

int adj[MAX_N][MAX_N];
int dist[MAX_N];
int visitado[MAX_N];

int min(int a, int b) {
    return (a < b) ? a : b;
}

void dijkstra(int N, int start_node) {
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
        visitado[i] = 0;
    }
    
    dist[start_node] = 0;

    for (int count = 1; count <= N; count++) {
        
        int u = -1;
        int min_dist = INF;

        for (int v = 1; v <= N; v++) {
            if (!visitado[v] && dist[v] <= min_dist) {
                min_dist = dist[v];
                u = v;
            }
        }
        
        if (u == -1 || min_dist == INF) {
            break; 
        }

        visitado[u] = 1;

        for (int v = 1; v <= N; v++) {
            if (!visitado[v] && adj[u][v] != INF && dist[u] != INF && 
                dist[u] + adj[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
}

int main() {
    int N, E;

    while (scanf("%d %d", &N, &E) && (N != 0 || E != 0)) {
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                adj[i][j] = INF;
            }
        }
        
        int temp_cost[MAX_N][MAX_N];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                temp_cost[i][j] = INF;
            }
        }

        for (int k = 0; k < E; k++) {
            int U, V, C; // U: origem, V: destino, C: custo
            scanf("%d %d %d", &U, &V, &C);
            
            temp_cost[U][V] = C;

            if (temp_cost[V][U] != INF && temp_cost[V][U] == temp_cost[U][V]) {
                adj[U][V] = 0;
                adj[V][U] = 0;
            } 
            else {
                if (adj[U][V] != 0) {
                    adj[U][V] = min(adj[U][V], C);
                }
            }
        }

        int K;
        scanf("%d", &K);

        for (int i = 0; i < K; i++) {
            int O, D;
            scanf("%d %d", &O, &D);

            dijkstra(N, O); 

            int resultado = dist[D];

            if (resultado == INF) {
                printf("Nao e possivel ir de %d para %d.\n", O, D);
            } else {
                printf("%d\n", resultado);
            }
        }
        
        if (N != 0 || E != 0) {
             printf("\n");
        }
    }

    return 0;
}