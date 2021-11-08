#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2){
    int a = mx_strlen(s1);
    int b = mx_strlen(s2);
    int i = a, j = 0;
    while (i < (a + b)){
        s1[i++] = s2[j++];
    }
    s1[i++] = '\0';
    return s1;
}
