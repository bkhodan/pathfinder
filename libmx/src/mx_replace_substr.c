#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace){
    if (!str || !sub || !replace || (mx_strlen(str) <= mx_strlen(sub))) return NULL;
	int summa = mx_strlen(replace) - mx_strlen(sub);
	int len = mx_strlen(str) + mx_count_substr(str, sub) * summa;
	char *mass = mx_strnew(len);
	bool varr = false;
	for (int i = 0; i < len; i++, str++){
		varr = false;
		if (!mx_strncmp((char *)str, (char *)sub, mx_strlen(sub))){
			str += mx_strlen(sub);
			for (int j = 0; j < mx_strlen(replace); i++, j++) mass[i] = replace[j];
			varr = true;
		}
		mass[i] = *str;
		if (varr) {
			str--;
			i--;
		}
	}
	return mass;
}
