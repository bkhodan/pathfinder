#include "libmx.h"

t_list *mx_create_node(void *data){
    t_list *mass = (t_list*)malloc(16);
    mass -> next = NULL;
    mass -> data = data;
    return mass;
}
