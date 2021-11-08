#include "libmx.h"

void mx_str_reverse(char *s){
    for (int i = 0, len = mx_strlen(s) - 1; i <= len / 2; i++)
        mx_swap_char(&s[i], &s[len - i]);
}
