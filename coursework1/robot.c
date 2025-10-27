#include "foreground.h"
#include "background.h"
#include "robot.h"

void forward(struct robot *robot)
{
    switch(robot->direction)
    {
        case LEFT: robot -> grid_coord.x -= 1; break;
        case RIGHT: robot -> grid_coord.x += 1; break;
        case UP: robot -> grid_coord.y -= 1; break;
        case DOWN: robot -> grid_coord.y += 1; break;
    }
}

void left(enum direction *direction)
{
    *direction = (*direction + 3) % 4;
}

void right(enum direction *direction)
{
    *direction = (*direction + 5) % 4;
}

int atMarker(struct robot robot, struct pair pos_marker)
{
    if ((robot.grid_coord.x == pos_marker.x) && (robot.grid_coord.y == pos_marker.y))
    {
        return 1;
    }
    return 0;
}

int canMoveForward(struct robot robot, struct arena arena)
{
    switch(robot.direction)
    {
        case LEFT: 
            if (robot.grid_coord.x == 1)
            {
                return 0;
            }
            break;
        case RIGHT:
            if (robot.grid_coord.x == arena.arena_grid_size.x)
            {
                return 0;
            }
            break;
        case UP:
            if (robot.grid_coord.y == 1)
            {
                return 0;
            }
            break;
        case DOWN:
            if (robot.grid_coord.y == arena.arena_grid_size.y)
            {
                return 0;
            }
            break;
    }
    return 1;
}

