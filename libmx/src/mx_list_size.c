#include "libmx.h"

int mx_list_size(t_list *list){
    int flag = 0;
    t_list *mass = NULL;
    if (list){
        mass = list;
        while (mass != NULL){
            flag++;
            mass = mass->next;
        }
    }
    return flag;
}
