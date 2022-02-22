#include "../inc/pathfinder.h"

v_list *mx_new_node(int dist, char *name) {
    v_list *node = malloc(sizeof(v_list));
    node->dist = dist;
    node->name = name;
    node->next = NULL;
    return node;
}

