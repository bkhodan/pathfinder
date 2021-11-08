#include "../inc/pathfinder.h"

int main(int argc, char *argv[]){
    file_validation(argc, argv[1]);
    path_fix(argv[1]);
    int lines = 0;
    int **matrix = get_adj_matrix(argv[1], &lines);
    get_list_path(matrix, lines);
    get_path_visit_matrix(matrix, lines);
    pathfinder(matrix, lines);
    matrix_close(matrix, lines);
    return 0;
}
