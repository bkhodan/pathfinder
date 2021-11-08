#include "libmx.h"

void mx_pop_back(t_list **head){
    if(!head || !(*head)) return;
    if ((*head)->next == NULL){
        free(*head);
        *head = NULL;
    } 
    else{
        t_list *flag = NULL;
        flag = *head;
        while (flag && flag->next->next != NULL) flag = flag->next;
        free(flag->next);
        flag->next = NULL;
    }
}
