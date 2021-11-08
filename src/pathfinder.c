#include "../inc/pathfinder.h"

node ***pathes = NULL;
int *lens = NULL;
void pathfinder(int **matrix, int size) {
	int *path_distance;
	int path_amount;
	int p_ind;
	node **path = malloc(sizeof(node*) * size);
	for (int i = 0; i < size; i++) path[i] = NULL;
	for(int i = 0; i < size; i++){
		path_distance = route_search(size, i, matrix);
		for(int j = 0; j < size; j++) list_path[j]->path_distance = path_distance[j];
		for(int j = i + 1; j < size; j++) {
			pathes = malloc(sizeof(node**) * size * size * size);
			lens = malloc(sizeof(int) * size);
			path_amount = 0; 
			p_ind = 0;
			search_path(list_path[i], list_path[j], matrix, path, size, &path_amount, &p_ind);
			output_all_paths(matrix, path_amount);
			for (int k = 0; k < size; k++) path[k] = NULL;
			get_path_visit_matrix(matrix, size);
			for(int k = 0; k < path_amount; k++) {
				free(pathes[k]);
				pathes[k] = NULL;
			}
			free(pathes);
			free(lens);
			lens = NULL;
			pathes = NULL;
		}
		free(path_distance);
		path_distance = NULL;
	}
	free(path);
	path = NULL;
}
