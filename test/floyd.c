/*图的最短路径——Floyd算法*/
#include <stdio.h>
#include <limits.h>

#define V 4

void printSolution(int dist[V][V]) {
    printf("顶点间的最短距离矩阵为：\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

void floyd(int graph[V][V]) {
    int dist[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX
                    && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {0, 5, INT_MAX, 10},
        {INT_MAX, 0, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, 1},
        {INT_MAX, INT_MAX, INT_MAX, 0}
    };

    printf("测试邻接矩阵为：\n");
    for (int i = 0; i < V; i++) {
        printf("{ ");
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%d ", graph[i][j]);
            }
        }
        printf("}\n");
    }

    floyd(graph);

    return 0;
}
