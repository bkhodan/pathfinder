#include "libmx.h"

static int letter_count(const char *s, char c){
	int i = 0;
	while (s[i] != c && s[i]) i++;
	return i;
}

char **mx_strsplit(const char *s, char c){
    int length = 0;
    char **mass = NULL;
	int i = 0;
    if (!s) return NULL;
    mass = (char **)malloc((mx_count_words(s, c) + 1) * sizeof(char *));
    for (;(*s) && (*s != '\0'); s++){
        if (*s != c){
            length = letter_count(s, c);
            mass[i] = mx_strndup(s, length);
            s += length;
            i++;
            continue;
		}
    }
    mass[i] = NULL;
    return mass;
}
