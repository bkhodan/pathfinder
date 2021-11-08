#ifndef HF
#define HF

#define INT_MAX 2147483647

#include "../libmx/inc/libmx.h"

enum vertex_status{ WHITE, GRAY, BLACK};

typedef struct s_graph{   
    char *name;
    int path_distance;
    int index;
    int len;
    struct s_graph **pointers;
}              node;     

bool island_index(const char* island, char **arr, int size);
bool main_loop(node **path1, node **path2, int coord1, int coord2, int size1, int size2);
void matrix_close(int **matrix, const int lines);
node **route_path(node **path, int path_size);
void file_validation(int amount_of_args, char *file_path);
void search_path(node* beg, node* end, int **matrix, node **path, int size, int *path_amount, int *p_ind);
int *route_search(int size, int begin_index, int **matrix);
void get_list_path(int **matrix, const int size);
int get_touch_coord(const char *island, char **arr, int size);
void get_path_visit_matrix(int **matrix, const int size);
int **get_adj_matrix(char *path, int *lines);
void path_fix(const char *file);
void pathfinder(int **matrix, int size);
void path_result(node **path, const int size, int **matrix);
void swap_elements(int *a, int *b);
void swap_pathes(node ***path1, node ***path2);
void sorting_path(int size);
void output_all_paths(int **matrix, int size_p);

extern char **islands;
extern node **list_path;
extern int **visit_matrix;
extern node ***pathes;
extern int *lens;

#endif
