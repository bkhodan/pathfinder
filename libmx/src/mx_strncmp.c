#include "libmx.h"

int mx_strncmp(const char *s1, const char *s2, int n){
    for (int i = 0; i < n; s1++, s2++, i++)
        if(*s1 != *s2) return *(unsigned const char *)s1 - *(unsigned const char *)s2;
    return 0;
}
