#include "libmx.h"

int mx_sqrt(int x){
    float flag = 0;
    float cor = x/2;
    if (x<=0) return 0;
    while (cor!=flag){
        flag = cor;
        cor = (x/flag+flag)/2;
    }
    return (cor-(int)cor==0?cor:0);
}
