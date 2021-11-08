#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if (!arr) return -1;
    int counter = 0;
    int l = left;
    int r = right;
    int mass = mx_strlen(arr[(l + r) >> 1]);
    char *sw;
    while (l <= r){
        while (mx_strlen(arr[l]) < mass)
            l++;
        while (mx_strlen(arr[r]) > mass)
            r--;
        if (l <= r){
            if(mx_strlen(arr[r]) != mx_strlen(arr[l])){
                sw = arr[l];
                arr[l] = arr[r];
                arr[r] = sw;
                counter++;
            }
            l++;
            r--;
        }
    }
    if (r > left) counter += mx_quicksort(arr, left, r); 
    if (l < right) counter += mx_quicksort(arr, l, right);
    return counter;
}
