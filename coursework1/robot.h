#ifndef ROBOT_H
#define ROBOT_H
#include "background.h"
#include "foreground.h"

void forward(struct robot *robot);
void left(enum direction *direction);
void right(enum direction *direction);
int atMarker(struct robot robot, struct pair pos_marker);
int canMoveForward(struct robot robot, struct arena arena);

#endif