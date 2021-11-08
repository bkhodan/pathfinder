#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2){
    if (s1 == NULL && s2 == NULL) return NULL;
    else if (s1 == NULL) return mx_strdup(s2);
    else if (s2 == NULL) return mx_strdup(s1);
    else{
        int a = mx_strlen(s1), ns2 = mx_strlen(s2);
        char *mass = mx_strnew(a + ns2);
        mass = mx_strcpy(mass, s1);
        mass = mx_strcat(mass, s2);
        return mass;
    }
}
