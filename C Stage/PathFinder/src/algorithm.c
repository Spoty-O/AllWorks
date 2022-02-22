#include "../inc/pathfinder.h"

void not_dijkstra(finder_data *finder) {
    for (int v = 0; v < finder->size; v++) {
        for (int u = 0; u < finder->size; u++) {
            finder->dist[v][u] = finder->graph[v][u];
        }
    }
    for (int k = 0; k < finder->size; k++) {
        for (int i = 0; i < finder->size; i++) {
            for (int j = i + 1; j < finder->size; j++) {
                if (finder->dist[k][j] != INT_MAX && finder->dist[i][k] != INT_MAX
                    && finder->dist[i][k] + finder->dist[k][j] < finder->dist[i][j]) {
                    finder->dist[i][j] = finder->dist[i][k] + finder->dist[k][j];
                    finder->dist[j][i] = finder->dist[i][k] + finder->dist[k][j];
                }
            }
        }
    }
    int path[finder->size];
    int length = 1;
    for (int start = 0; start < finder->size; start++) {
        for (int end = start + 1; end < finder->size; end++) {
            length = 1;
            path[0] = end;
            path[1] = start;
            printSolution(finder, path, length);
        }
    }
}

