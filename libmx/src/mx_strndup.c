#include "libmx.h"

char *mx_strndup(const char *s1, size_t n){
    char *mass = NULL;
    size_t dl = mx_strlen(s1);

    if (n < dl)
        dl = n;
    mass = mx_strnew(dl);
    mx_strncpy(mass, s1, dl);
    return mass;
}
