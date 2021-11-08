#include "libmx.h"

char *mx_itoa(int number){
    int num = number;
	int l = 0;
	char *rez = NULL;
    for (; num; l++){
        num /= 10;
	}
	rez = mx_strnew(l);
	if (number == 0)
	return mx_strcpy(rez, "0");
	if (number == -2147483648)
	return mx_strcpy(rez, "-2147483648");
	int tmp = number;
	for (int i = 0; i < l; i++){
		if (tmp < 0){
			rez[l] = '-';
			tmp = -tmp;
		}
		rez[i] = (tmp % 10) + '0';
		tmp /= 10;
	}
	mx_str_reverse(rez);
	return rez;
}
