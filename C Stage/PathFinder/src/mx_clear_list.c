#include "../inc/pathfinder.h"

void mx_clear_list(v_list **list) {
    if (!*list) return; 
    v_list *temp;
    while (*list) {
        temp = (*list) -> next;
        (*list) -> next = NULL;
        free(*list);
        *list = temp;
    }
    list = NULL;
}

