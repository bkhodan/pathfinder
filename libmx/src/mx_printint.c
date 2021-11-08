#include "libmx.h"

void mx_printint(int n){
    char mass[12];
    int a = 0;
    if (n == 0){
        mx_printchar('0');
    }else if (n < 0){
        if (n == -2147483648){
            mx_printint(-214748364);
            mx_printint(8);
        }else{
            mx_printchar('-');
            mx_printint(-n);
        }
    }else{
        while (n != 0){
            mass[a++] = '0' + n % 10;
            n /= 10;
        }
        for (int j = a - 1; j >= 0; j--) mx_printchar(mass[j]);
    }
}
