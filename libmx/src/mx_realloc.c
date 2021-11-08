#include "libmx.h"

void *mx_realloc(void *ptr, size_t size){
    if (!size && ptr){
        free(ptr);
        return NULL;
    }
    if (!ptr && size) return malloc(size);
    size_t dl_size = malloc_size(ptr); 
    if (dl_size > size) size = dl_size;
    void *mass = (void *) malloc(size);
    if (!mass) return NULL;
    mass = mx_memmove(mass, ptr, dl_size);
    free(ptr);
    return mass;
}
