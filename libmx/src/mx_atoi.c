#include "libmx.h"

int mx_atoi(const char *str){
    const char* flag;
    while(*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r'){
        str++;
    }
    int a = 0;
    int n = (str[0] == '-') ? -1 : 1;
    if (!(str[0] >= '0' && str[0] <= '9') && str[0] != '-' && str[0] != '+'){
        return 0;
    }
    if (str[0] == '-' || str[0] == '+'){
        str++;
    }
    flag = str;
    while(*flag >= '0' && *flag <= '9'){
        a *= 10;
        a += *flag - '0';
        flag++;
    }
    return a * n;
}
