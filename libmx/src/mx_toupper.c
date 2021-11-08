#include "libmx.h"

int mx_toupper(int c){
    return (65 <= c && c <= 90) ? c : (c - 32);
}
