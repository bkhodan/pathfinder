#include "libmx.h"

void mx_pop_front(t_list **head){
    t_list *flag = NULL;
    if (head == NULL || *head == NULL)
        return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        flag = (*head)->next;
        free(*head);
        *head = flag;
    }
}
