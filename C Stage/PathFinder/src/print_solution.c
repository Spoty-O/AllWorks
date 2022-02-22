#include "../inc/pathfinder.h"

void print_path (finder_data *finder, int path[], int length) {
    int alt = 0;
    int count = 0;
    v_list *result = NULL;
    v_list **temp = NULL;
    v_list *start = NULL;
    for (int i = 1; i < length + 1; i++) {
        if (i == length) {
            mx_node_push_back(&result, 0, finder->a[path[i]]);
        }
        else {
            mx_node_push_back(&result, finder->graph[path[i]][path[i + 1]], finder->a[path[i]]);
        }
        count++;
    }
    start = result;
    temp = &result;
    mx_printstr("========================================\nPath: ");
    mx_printstr(finder->a[path[1]]);
    mx_printstr(" -> ");
    mx_printstr(finder->a[path[0]]);
    mx_printstr("\nRoute: ");
    mx_printstr(result->name);
    result = result->next;
    while(result) {
        mx_printstr(" -> ");
        mx_printstr(result->name);
        result = result->next;
    }
    mx_printstr("\nDistance: ");
    result = start;
    mx_node_pop_back(&result);
    while(result) {
        alt += result->dist;
        mx_printint(result->dist);
        if (result->next == NULL) {
            if (count > 2) {
                mx_printstr(" = ");
                mx_printint(alt);
            }
        }
        else {
            mx_printstr(" + ");
        }
        result = result->next;
    }
    mx_printstr("\n========================================\n");
    mx_clear_list(&result);
    mx_clear_list(&start);
    mx_clear_list(temp);
    count = 0;
}

void printSolution(finder_data *finder, int path[], int length) {
    int i = path[length];
    int j = path[0];
    for (int m = 0; m < finder->size; m++) {
        if (m != path[length] && finder->graph[i][m] == finder->dist[i][j] - finder->dist[m][j]) {
            length++;
            path[length] = m;
            printSolution(finder, path, length);
            length--;
        }
    }
    if (path[length] != path[0]) {
        return;
    }
    print_path(finder, path, length);
}

