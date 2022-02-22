#include "../inc/pathfinder.h"

void mx_node_push_back(v_list **list, int dist, char *name) {
    if (!*list) {
        *list = mx_new_node(dist, name);
        return;
    }
    v_list *temp = *list;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = mx_new_node(dist, name);
}

