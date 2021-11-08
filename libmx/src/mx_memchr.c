#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n){
	unsigned char *mass = (unsigned char *)s;
	while (n > 0){
		if (*mass == (unsigned char)c)
			return mass;
		mass++;
		n--;
	}
	return NULL;
}
