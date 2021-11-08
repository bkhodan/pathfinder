#include "libmx.h"

char *mx_strnew(const int size){
    char *mass = NULL;
    int i = 0;
    if (size < 0) return NULL;
    mass = (char *)malloc((size + 1) * sizeof(char));
    while (i < size){
        mass[i] = '\0';
        i++;
    }
    mass[i] = '\0';
    return mass;
}
