#include "../inc/pathfinder.h"

node **route_path(node **path, int path_size) {
	node **route_path = malloc(sizeof(node*) * path_size);
	for(int i = 0; i < path_size; i++) {
		route_path[i] = malloc(sizeof(node));
		route_path[i]->path_distance = path[i]->path_distance;
		route_path[i]->index = path[i]->index;
		route_path[i]->len = path[i]->len;
		route_path[i]->name = path[i]->name;
		route_path[i]->pointers = path[i]->pointers;
	}
	return route_path;
}
