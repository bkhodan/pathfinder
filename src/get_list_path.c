#include "../inc/pathfinder.h"

node **list_path;
void get_list_path(int **matrix, const int size) {
    int temp_size = 0, k = 0;
    list_path = malloc(sizeof(node*) * size);
    for (int i = 0; i < size; i++) {
        list_path[i] = malloc(sizeof(node));
        list_path[i]->name = islands[i];
        list_path[i]->index = i;
        list_path[i]->pointers = malloc(sizeof(node*) * size - 1);
    }
    for (int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(matrix[i][j] != 0) {
                list_path[i]->pointers[k] = list_path[j];
                k++; temp_size++;
            }
        }
        list_path[i]->len = temp_size;
        k = 0; temp_size = 0;
    }
}
