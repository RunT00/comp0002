#include "graphics.h"
#include "background.h"
#include "foreground.h"
#include "robot.h"
#include <stdlib.h>

/* intialize 8 points in a grid like
    * - * - *
    - - - - -
    * - - - *
    - - - - -
    S - * - *
    and choose 3 points for each direction of robot,
    starting from S clockwisely,
    there will be interval outside these 5x5 points in a grid
*/

int dots_x[8], dots_y[8];
int temp_grids_x[3], temp_grids_y[3];

void init_grids(int grid_size)
{   
    int interval = (int)(grid_size / 10.0);
    int offset = (int)((grid_size - 2 * interval) / 2.0);

    dots_x[0] = dots_x[1] = dots_x[2] = interval;
    dots_x[3] = dots_x[7] = interval + offset;
    dots_x[4] = dots_x[5] = dots_x[6] =  interval + 2 * offset;

    dots_y[2] = dots_y[3] = dots_y[4] = interval;
    dots_y[1] = dots_y[5] = interval + offset;
    dots_y[0] = dots_y[6] = dots_y[7] =  interval + 2 * offset;
}

int rand_choose(int x, int y)
{
    if (rand()%2 == 1)
    {
        return x;
    }
    return y;
}

int rand_choose_tri(int x, int y, int z)
{
    int choice = rand() % 3;
    if (choice == 0)
    {
        return x;
    }
    else if (choice == 1)
    {
        return y;
    }
    return z;
}

enum direction init_direction(struct robot robot, struct pair arena_grid_size) // x increases when goes right, y increases when goes down
{   
    if ((robot.grid_coord.y < arena_grid_size.y / 2) || ((robot.grid_coord.y == arena_grid_size.y / 2) && (arena_grid_size.y % 2 == 0))) // upper / upper for even y-size
    {
        if ((robot.grid_coord.x > arena_grid_size.x / 2) && (robot.direction == UP || robot.direction == RIGHT)) // top right
        {
            robot.direction = rand_choose(DOWN, LEFT);
        }
        else if ((robot.grid_coord.x < arena_grid_size.x / 2) && (robot.direction == UP || robot.direction == LEFT)) // top left
        {
            robot.direction = rand_choose(DOWN, RIGHT);
        }
        else if (robot.grid_coord.x == arena_grid_size.x / 2) 
        {   
            if ((arena_grid_size.x % 2 == 0) && (robot.direction == UP || robot.direction == LEFT))  // top left for even x-size
            {
                robot.direction = rand_choose(DOWN, RIGHT);
            }
            else if ((arena_grid_size.x % 2 == 1) && (robot.direction == UP)) // top mid for odd x-size
            {
                robot.direction = rand_choose_tri(DOWN, LEFT, RIGHT);
            }
        }
    }
    else if (robot.grid_coord.y > arena_grid_size.y / 2) // lower
    {
        if ((robot.grid_coord.x > arena_grid_size.x / 2) && (robot.direction == DOWN || robot.direction == RIGHT)) // bottom right
        {
            robot.direction = rand_choose(UP, LEFT);
        }
        else if ((robot.grid_coord.x < arena_grid_size.x / 2) && (robot.direction == DOWN || robot.direction == LEFT)) // bottom left
        {
            robot.direction = rand_choose(UP, RIGHT);
        }
        else if (robot.grid_coord.x == arena_grid_size.x / 2) 
        {   
            if ((arena_grid_size.x % 2 == 0) && (robot.direction == DOWN || robot.direction == LEFT)) // bottom left for even x-size
            {
                robot.direction = rand_choose(UP, RIGHT);
            }
            else if ((arena_grid_size.x % 2 == 1) && (robot.direction == DOWN)) // bottom mid for odd x-size
            {
                robot.direction = rand_choose_tri(UP, LEFT, RIGHT);
            }
        }
    }
    else // horizontal mid line
    {
        if ((robot.grid_coord.x > arena_grid_size.x / 2) && (robot.direction == RIGHT)) // horizontal right
        {
            robot.direction = rand_choose_tri(UP, DOWN, LEFT);
        }
        else if ((robot.grid_coord.x < arena_grid_size.x / 2) && (robot.direction == LEFT)) // horizontal left
        {
            robot.direction = rand_choose_tri(UP, DOWN, RIGHT);
        }
        else
        {
            if ((arena_grid_size.x % 2 == 0) && (robot.direction == LEFT)) // mid left for even x-size
            {
                robot.direction = rand_choose_tri(UP, DOWN, RIGHT);
            }
        }
    }
    return robot.direction;
}

void load_temp(struct pair pixel_coord, enum direction direction) // 0 = left, 1 = up, 2 = right, 3 = down
{   
    int positions[3];
    switch (direction)
    {
        case LEFT: positions[0] = 1; positions[1] = 4; positions[2] = 6; break; // positions[1] and positions[2] can be connected in a line as the bottom side
        case UP: positions[0] = 3; positions[1] = 6; positions[2] = 0; break;
        case RIGHT: positions[0] = 5; positions[1] = 0; positions[2] = 2; break;
        case DOWN: positions[0] = 7; positions[1] = 2; positions[2] = 4; break;
    }
   
    for (int i = 0; i < 3; i++)
    {
        temp_grids_x[i] = pixel_coord.x + dots_x[positions[i]];
        temp_grids_y[i] = pixel_coord.y + dots_y[positions[i]];
    }
}

void draw_robot(struct robot robot, struct arena arena)
{
    int interval = arena.grid_size / 10; // leave space between line and edge of marker
    struct pair pixel_coord = grid_to_pixel(robot.grid_coord, arena);
    load_temp(pixel_coord, robot.direction);

    setColour(blue);
    fillPolygon(3, temp_grids_x, temp_grids_y);

    setColour(red);
    drawLine(temp_grids_x[1], temp_grids_y[1], temp_grids_x[2], temp_grids_y[2]);
}

void draw_foreground(struct pair window_size, struct arena arena, struct pair pos_marker)
{
    foreground();
    clear();
    setLineWidth(1);
    init_grids(arena.grid_size);

    struct pair grid_coord = rand_grid_coord(arena.arena_grid_size);
    enum direction direction = rand() % 4;
    struct robot robot = {grid_coord, direction};
    robot.direction = init_direction(robot, arena.arena_grid_size);

    draw_robot(robot, arena);
    sleep(500);

    while (!(atMarker(robot, pos_marker)) && canMoveForward(robot, arena))
    {   
        clear();
        
        forward(&robot);

        draw_robot(robot, arena);
        sleep(500);
    }
    

}