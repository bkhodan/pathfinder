#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
    double rez = 1;
    if (pow > 0)
        for (unsigned int i = 0; i < pow; i++)
            rez *= n;
    if (!pow)
        return rez;
    return rez;
}
