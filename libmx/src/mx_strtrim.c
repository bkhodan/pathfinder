#include "libmx.h"

char *mx_strtrim(const char *str){
    if (!str) return NULL;
    while (mx_isspace(*str)) str++;
    int leng = mx_strlen(str);
    while (mx_isspace(str[leng - 1])) leng--;
    return mx_strndup(str, leng);
}
