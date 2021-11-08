#include "../inc/pathfinder.h"

void matrix_close(int **matrix, const int lines){
    for(int i = 0; i < lines; i++){
        free(matrix[i]);
        free(visit_matrix[i]);
        free(islands[i]);
        free(list_path[i]);
        free(list_path[i]->pointers);
        list_path[i]->pointers = NULL;
        list_path[i] = NULL;
        islands[i] = NULL;
        matrix[i] = NULL;
        visit_matrix[i] = NULL;
    }
    free(matrix);
    matrix = NULL;
    free(visit_matrix);
    visit_matrix = NULL;
    free(islands);
    islands = NULL;
    free(list_path);
    list_path = NULL;
}
