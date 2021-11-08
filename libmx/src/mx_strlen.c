#include "libmx.h"

int mx_strlen(const char *s){
    int obj = 0;
    while(*s != 0){
        s++; obj++;
    }
    return obj;
}
