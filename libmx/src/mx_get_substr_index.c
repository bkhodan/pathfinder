#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    int a = 0;
    int b = 0;
    if (sub && str) {
        b = mx_strlen(sub);
        while (*str) {
            if (mx_strncmp(str, sub, b) == 0)
                return a;
            a++;
            str++;
        }
        return -1;
    }
    return -2;
}
