#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
	unsigned char *flag = NULL;
	unsigned char *mass = NULL;
	if (big_len >= little_len && big_len > 0 && little_len > 0){
		flag = (unsigned char *)big;
		mass = (unsigned char *)little;
		for (; *flag; flag++) 
			if (!mx_memcmp(flag, mass, little_len - 1)) return flag;
	}
	return NULL;
}
