#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)){
    if (lst && cmp)
        for (t_list *mass1 = lst; mass1; mass1 = mass1->next)
            for (t_list *mass2 = lst; mass2->next; mass2 = mass2->next)
                if (cmp(mass2->data, mass2->next->data)){
                    void *flag = mass2->data;
                    mass2->data = mass2->next->data;
                    mass2->next->data = flag;
                }
    return lst;
}
