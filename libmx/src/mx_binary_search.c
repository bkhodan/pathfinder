#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count){ 
    int a = 0;
    int b = size - 1;
    int middle;
    while (a <= b) 
    { 
        middle = a + (b - a) / 2; 
        *count += 1;
        if (mx_strcmp(arr[middle], s) == 0) 
            return middle;
        (mx_strcmp(arr[middle], s) < 0) ? (a = middle + 1) : (b = middle - 1); 
    }
    *count = 0;
    return -1; 
}
