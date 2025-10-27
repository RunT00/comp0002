#include "graphics.h"
#include "background.h"
#include <stdlib.h>
#include <time.h>

struct pair calc_arena_grid_size(struct pair window_size, int grid_size, int wall_width)
{
    struct pair arena_grid_size;
    arena_grid_size.x = (window_size.x - 2 * wall_width) / grid_size;
    arena_grid_size.y = (window_size.y - 2 * wall_width) / grid_size;
    return arena_grid_size;
}

struct pair calc_arena_pixel_size(struct pair arena_grid_size, int grid_size)
{
    struct pair arena_pixel_size;
    arena_pixel_size.x = grid_size * arena_grid_size.x;
    arena_pixel_size.y = grid_size * arena_grid_size.y;
    return arena_pixel_size;
}

void draw_wall(struct arena arena)
{
    setColour(red);
    fillRect(0, 0, arena.wall_width, arena.arena_pixel_size.y + 2 * arena.wall_width);
    fillRect(0, 0, arena.arena_pixel_size.x + 2 * arena.wall_width, arena.wall_width);
    fillRect(0, arena.wall_width + arena.arena_pixel_size.y, arena.arena_pixel_size.x + 2 * arena.wall_width, arena.wall_width);
    fillRect(arena.wall_width + arena.arena_pixel_size.x, 0, arena.wall_width, arena.arena_pixel_size.y + 2 * arena.wall_width);
}

void draw_lines(struct arena arena)
{   
    setColour(black);
    int x = arena.wall_width, y = arena.wall_width;
    while (x <= arena.wall_width + arena.arena_pixel_size.x)
    {
        drawLine(x, y, x, y + arena.arena_pixel_size.y);
        x += arena.grid_size;
    }
    x = arena.wall_width;
    while (y <= arena.wall_width + arena.arena_pixel_size.y)
    {
        drawLine(x, y, x + arena.arena_pixel_size.x, y);
        y += arena.grid_size;
    }
}

struct pair grid_to_pixel(struct pair grid_coord, struct arena arena)
{
    struct pair pixel_coord;
    pixel_coord.x = (grid_coord.x - 1) * arena.grid_size + arena.wall_width;
    pixel_coord.y = (grid_coord.y - 1) * arena.grid_size + arena.wall_width;
    return pixel_coord;
}

int is_near_wall(struct pair grid_coord, struct pair arena_grid_size)
{   
    if ((grid_coord.x == 1) || (grid_coord.x == arena_grid_size.x) || (grid_coord.y == 1) || (grid_coord.y == arena_grid_size.y))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct pair to_near_wall(struct pair grid_coord, struct pair arena_grid_size)
{
    int choice = rand() % 4;
    switch(choice)
    {
        case 0: grid_coord.x = 1; break;
        case 1: grid_coord.y = 1; break;
        case 2: grid_coord.x = arena_grid_size.x; break;
        case 3: grid_coord.y = arena_grid_size.y; break;
    }
    return grid_coord;
}

void reset_rand()
{
    srand(time(NULL)); // reset random sequence according to current time
}

struct pair rand_grid_coord(struct pair arena_grid_size)
{   
    struct pair grid_coord;
    grid_coord.x = rand() % arena_grid_size.x + 1;
    grid_coord.y = rand() % arena_grid_size.y + 1;
    return grid_coord;
}

struct pair draw_marker(struct arena arena)
{
    struct pair grid_coord = rand_grid_coord(arena.arena_grid_size);
    if (is_near_wall(grid_coord, arena.arena_grid_size) == 0)
    {
        grid_coord = to_near_wall(grid_coord, arena.arena_grid_size);
    }

    setColour(gray);
    struct pair pixel_coord = grid_to_pixel(grid_coord, arena);
    int interval = arena.grid_size / 10; // leave space between line and edge of marker
    fillOval(pixel_coord.x + interval, pixel_coord.y + interval, arena.grid_size - 2 * interval, arena.grid_size - 2 * interval);
    return grid_coord;
}

struct pair draw_background(struct pair window_size, struct arena arena)
{  
    background();
    clear();
    setLineWidth(1);

    draw_wall(arena);
    draw_lines(arena);
    return draw_marker(arena);
}
