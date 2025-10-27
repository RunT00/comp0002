#ifndef FOREGROUND_H
#define FOREGROUND_H
#include "background.h"

enum direction {LEFT, UP, RIGHT, DOWN};
struct robot
{
    struct pair grid_coord;
    enum direction direction;
};

enum direction init_direction(struct robot robot, struct pair arena_grid_size);
void draw_robot(struct robot robot, struct arena arena);
void draw_foreground(struct pair window_size, struct arena arena, struct pair pos_marker);

#endif