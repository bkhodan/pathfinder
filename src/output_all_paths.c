#include "../inc/pathfinder.h"

void output_all_paths(int **matrix, int size_p) {
	sorting_path(size_p);
	for(int i = 0; i < size_p; i++) {
		path_result(pathes[i], lens[i], matrix);
	}
}
