#include "libmx.h"

char *mx_strjoin_free(char const *s1, char const *s2){
    if (!s1 && !s2)
        return NULL;
    if (!s1 && s2)
        return mx_strdup(s2);
    if (s1 && !s2)
        return mx_strdup(s1);
    char *new_stroch = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    new_stroch = mx_strcat(mx_strcpy(new_stroch, s1), s2);
    char *del = (char*)s1;
    mx_strdel(&del);
    return new_stroch;
}

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd){
    if (buf_size == 0) return -2;
    buf_size = 1;
    int rez = 0;
    int byte;
    char *flah = *lineptr;
    *lineptr = NULL;
    char *mass = mx_strnew(buf_size);
    while ((byte = read(fd, mass, buf_size)) > 0){
        if (mx_get_char_index(mass, delim) >= 0){
            mass[mx_get_char_index(mass, delim)] = '\0';
            *lineptr = mx_strjoin_free(*lineptr, mass);
            rez += mx_strlen(mass);
            free(mass);
            free(flah);
            return rez;
        }
        *lineptr = mx_strjoin_free(*lineptr, mass);
        rez += byte;
    }
    if (rez == 0){
        *lineptr = flah;
        free(mass);
        if (byte == -1)
            return -2;
        else
            return -1;
    }
    free(mass);
    return rez;
}
