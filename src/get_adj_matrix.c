#include "../inc/pathfinder.h"

char **islands = NULL;
int **get_adj_matrix(char *path, int *lines){
    char *mass = mx_file_to_str(path);
    char *errors;
    char *a1;
    char *a2;
    int size = mx_atoi(mass), a_length = 0, a_count = 0, line, row, iterat = 2;
    long long sum_len = 0, dist = 0;
    bool a_was = false;
    if(*mass == '\n'){
        mx_printerr("error: line 1 is not valid\n");
        exit(0);
    }
    while(*mass != '\n'){ //first line check
        if(!mx_isdigit(*mass)){
            mx_printerr("error: line 1 is not valid\n");
            exit(0);
        }
        mass++;
    }
    mass++;
    *lines = size;
    int **matrix = malloc(sizeof(int*) * size);
    for(int i = 0; i < size; i++){
        matrix[i] = malloc(sizeof(int) * size);
        for(int j = 0; j < size; j++) matrix[i][j] = 0;
    }
    islands = malloc(sizeof(char*) * size);
    while(*mass != '\0'){
        while(mass[a_length] != '-'){
            if(!mx_isalpha(mass[a_length])){
                errors = mx_strjoin(mx_strjoin("error: line ", mx_itoa(iterat)), " is not valid\n");
                mx_printerr(errors);
                exit(0);
            }
            a_length++;
        }
        a1 = mx_strndup(mass, a_length);
        if(island_index(mx_strndup(mass, a_length), islands, a_count)){
            if(a_count < size) islands[a_count] = mx_strndup(mass, a_length);
            else{
                mx_printerr("error: invalid number of islands\n");
                exit(0);
            }
            a_was = true;
            line = a_count;
            a_count++;
        }
        if(!a_was && iterat != 2) line = get_touch_coord(a1, islands, a_count);
        a_was = false;
        if(mass[a_length + 1] == '-'){
            errors = mx_strjoin(mx_strjoin("error: line ", mx_itoa(iterat)), " is not valid\n");
            mx_printerr(errors);
            exit(0);
        }
        mass += (a_length + 1) * sizeof(char);
        a_length = 0;
        while(mass[a_length] != ','){ //second island
            if(!mx_isalpha(mass[a_length])){
                errors = mx_strjoin(mx_strjoin("error: line ", mx_itoa(iterat)), " is not valid\n");
                mx_printerr(errors);
                exit(0);
            }
            a_length++;
        }
        a2 = mx_strndup(mass, a_length);
        if(mx_strcmp(a1, a2) != 0){
            if(island_index(mx_strndup(mass, a_length), islands, a_count)){
                if(a_count < size)
                    islands[a_count] = mx_strndup(mass, a_length);
                else{
                    mx_printerr("error: invalid number of islands\n");
                    exit(0);
                }
                a_was = true;
                row = a_count;
                a_count++;
            }
            if(!a_was && iterat != 2) row = get_touch_coord(a2, islands, a_count);
            a_was = false;
            mass += (a_length + 1) * sizeof(char);
            a_length = 0;
        }
        else{
            errors = mx_strjoin(mx_strjoin("error: line ", mx_itoa(iterat)), " is not valid\n");
            mx_printerr(errors);
            exit(0);
        }
        dist = mx_atoi(mass);
        if(dist == 0) {
            errors = mx_strjoin(mx_strjoin("error: line ", mx_itoa(iterat)), " is not valid\n");
            mx_printerr(errors);
            exit(0);
        }
        while(*mass != '\n'){ 
            if(!mx_isdigit(*mass)){
                errors = mx_strjoin(mx_strjoin("error: line ", mx_itoa(iterat)), " is not valid\n");
                mx_printerr(errors);
                exit(0);
            }
            mass++;
        }
        mass++;
        if(matrix[line][row] != 0 && matrix[row][line] != 0){
            mx_printerr("error: duplicate bridges\n");
            exit(0);
        }
        else{
            matrix[line][row] = dist;
            matrix[row][line] = dist;
            sum_len += dist;
        }
        iterat++;
    }
    if(sum_len > INT_MAX){
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(0);
    }
    if(a_count != size) {
        mx_printerr("error: invalid number of islands\n");
        exit(0);
    }
    return matrix;
}
