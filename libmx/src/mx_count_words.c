#include "libmx.h"

int mx_count_words(const char *str, char c){
    if (!str) return -1;
    int a = 1;
    unsigned flag = 0; 
    for (int i = 0;str[i]; i++){
        if (str[i] == c)
        a = 1;
        else if (a){
            a = 0;
            ++flag;
        }
    }
    return flag;
}
