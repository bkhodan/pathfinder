#include "libmx.h"

char *mx_file_to_str(const char *file){
    if (file == NULL) return NULL;
    int f = open(file, O_RDONLY);
    if (f < 0) return NULL;
    char a;
    int dl = 0; 
    while (read(f, &a, 1)){
        dl++;
    }
    if (close(f) < 0){
        return NULL;
    }
    if (dl == 0){
        return NULL;
    }
    f = open(file, O_RDONLY);
    if (f < 0){
        return NULL;
    }
    char *mass = mx_strnew(dl);
    read(f, mass, dl);
    if (close(f) < 0){
        return NULL;
    }
    return mass;
}
