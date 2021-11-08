#include "libmx.h"

void mx_push_back(t_list **list, void *data){
    t_list *flag = mx_create_node(data);
    t_list *mass = NULL;
    if (!list || !(*list))
        *list = flag;
    else{
        mass = *list;
        while (mass->next != NULL) mass = mass->next;
        mass->next = flag;
    }
}
