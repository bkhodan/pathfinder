#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
	unsigned char *mass = (unsigned char *)s + mx_strlen(s);
	while (n--){
		if (*mass == (unsigned char)c)
			return mass;
		mass--;
	}
	return NULL;
}
