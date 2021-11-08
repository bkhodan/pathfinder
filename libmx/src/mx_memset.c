#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char *mass = (unsigned char *)b;
    for (size_t i = 0; i < len; i++)
        mass[i] = (unsigned char)c;
    return b;
}
