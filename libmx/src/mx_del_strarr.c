#include "libmx.h"

void mx_del_strarr(char ***arr){
    for (int a = 0; (*arr)[a] != NULL; a++)
        mx_strdel(&((*arr)[a]));
    free(*arr);
    *arr = NULL;
}
