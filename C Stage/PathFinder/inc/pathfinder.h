#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

typedef struct n_list {
    int dist;
    char *name;
    struct n_list *next;
}           v_list;

typedef struct n_finder {
    int size;
    int **graph;
    int **dist;
    char **a;
}           finder_data;

void error_output(char *s, int num, int line);
int mx_atoi(const char *str);
v_list *mx_new_node(int dist, char *name);
void mx_node_push_back(v_list **list, int dist, char *name);
void mx_node_pop_back(v_list **head);
void mx_clear_list(v_list **list);
int find_size(char *s);
void islands(char *s, finder_data *finder);
void not_dijkstra(finder_data *finder);
void printSolution(finder_data *finder, int path[], int length);

#endif

