#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n){
    const unsigned char *mass1 = s1;
    const unsigned char *mass2 = s2;
    unsigned int i = 0;
    if (n == 0) return 0;
    else{
        while (mass1[i] == mass2[i] && i != n){
            if (mass1[i] == '\0' && mass2[i] == '\0') return 0;
            i++;
        }
        return mass1[i] - mass2[i];
    }
}
