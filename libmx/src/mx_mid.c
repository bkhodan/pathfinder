#include "libmx.h"

int mx_mid(int a, int b, int c){
    int flag;
    if ((a <= b && b <= c) || (c <= b && b <= a)) flag = b;
    if ((b <= c && c <= a) || (a <= c && c <= b)) flag = c;
    if ((b <= a && a <= c) || (c <= a && a <= b)) flag = a;
    return flag;
}
