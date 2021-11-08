#include "../inc/pathfinder.h"

int *route_search(int size, int begin_index, int **matrix){
	int *path_distance = malloc(sizeof(int) * size);
	int massvert[size];
	int flag, min_index, min_number;
	for (int i = 0; i < size; i++) {
		path_distance[i] = INT_MAX;
		massvert[i] = 1;
	}
	path_distance[begin_index] = 0;
	do {
		min_index = INT_MAX;
		min_number = INT_MAX;
		for (int i = 0; i < size; i++) { 
			if ((massvert[i] == 1) && (path_distance[i] < min_number)) { 
				min_number = path_distance[i];
				min_index = i;
			}
		}
		if (min_index != INT_MAX) {
			for (int i = 0; i < size; i++) {
				if (matrix[min_index][i] > 0) {
					flag = min_number + matrix[min_index][i];
					if (flag < path_distance[i]) path_distance[i] = flag;
				}
			}
			massvert[min_index] = 0;
		}
	} while (min_index < INT_MAX);
	return path_distance;
}
