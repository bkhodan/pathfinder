#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr){
    if (nbr < 1) return 0;
    unsigned long a = 0;
    unsigned long b = nbr;
    while (b){
        unsigned long ab = (b % 16);
        if (ab > 9)
        ab += (unsigned long)'a' - 10;
        else 
        ab+=(unsigned long)'0';
        a++;
        b /= 16;
    }
    if (a < 0) return NULL;
    char *mass = (char *)malloc(a + 1);
    for (unsigned long i = 0; i <= a; i++) mass[i] = '\0';
    while (nbr){
        unsigned long ab = (nbr % 16);
        if (ab > 9)
            ab += (unsigned long)'a' - 10;
        else 
            ab+=(unsigned long)'0';
        mass[--a] = (char)ab;
        nbr /= 16;
    }
    return mass;
}
