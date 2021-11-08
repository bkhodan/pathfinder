#include "libmx.h"

int mx_bubble_sort(char **arr, int size){
    char *flag; 
    int counter = 0;
    for (int j=0; j<size-1; j++){ 
        for (int i=j+1; i<size; i++){ 
            if (mx_strcmp(arr[j], arr[i]) > 0){ 
                flag = arr[j]; 
                arr[j] =arr[i]; 
                arr[i] = flag; 
                counter++;
            } 
        } 
    } 
    return counter;
}
