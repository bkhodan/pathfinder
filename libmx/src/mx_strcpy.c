#include "libmx.h"

char *mx_strcpy(char *dst, const char *src){
    int leg = 0;
    int a = 0;
    while(src[leg] != '\0'){
        leg++;
    }
    for(int i = 0; i <= leg ; i++){
        dst[i] = src[i];
        a++;
    }
    dst[a] = '\0';
    return dst;
}
