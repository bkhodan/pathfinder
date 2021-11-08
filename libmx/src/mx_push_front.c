#include "libmx.h"

void mx_push_front(t_list **list, void *data){
    t_list *mass = mx_create_node(data);
    t_list *flag = NULL;
    if (list == NULL || *list == NULL)
        *list = mass;
    else{
        flag = *list;
        *list = mass;
        mass->next = flag;
    }
}
