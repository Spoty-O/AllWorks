#include "../inc/pathfinder.h"

void free_arr(int **arr, finder_data *finder) {
    for (int i = 0; i < finder->size; i++) {
        free(arr[i]);
    }  
    free(arr);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        error_output(argv[1], 0,  0);
    }
    finder_data *finder = (finder_data *)malloc(sizeof(finder_data));
    finder->size = find_size(argv[1]);
    islands(argv[1], finder);
    not_dijkstra(finder);
    free_arr(finder->dist, finder);
    free_arr(finder->graph, finder);
    free(finder);
    return 0;
}

