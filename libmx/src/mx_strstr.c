#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle){
    int s1 = mx_strlen(haystack);
    int s2 = mx_strlen(needle);
    for (int symcount = 0; symcount < s1; haystack++, symcount++){
        char *flag = mx_strchr(haystack, haystack[0]);
        if(mx_strncmp(flag, needle, s2)==0) return (char*)haystack;
    }
    return NULL;
}
