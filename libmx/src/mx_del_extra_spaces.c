#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (!str)
        return NULL;
    char *mass1 = NULL;
    char *rez = NULL;
    mass1 = mx_strnew(mx_strlen(str));
    for (int i = 0, a = 0;str[i]; i++) 
    {
        if (!(mx_isspace(str[i]))) 
        {
            mass1[a] = str[i];
            a++;
        }
        if (!(mx_isspace(str[i])) && mx_isspace(str[i + 1])) 
        {
            mass1[a] = ' ';
            a++;
        }
    }
    rez = mx_strtrim(mass1);
    mx_strdel(&mass1);
    return rez;   
}
