#include "../inc/pathfinder.h"

void mx_node_pop_back(v_list **head) {
    v_list *temp = NULL;

    if (head == NULL || *head == NULL)
        return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    }
    else {
        temp = *head;
        while (temp && temp->next->next != NULL)
            temp = temp->next;
        free(temp->next);
        temp->next = NULL;
    }
}

