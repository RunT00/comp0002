#include "graphics.h"
#include "background.h"
#include "foreground.h"

void main(void)
{   
    const struct pair WINDOW_SIZE = {520, 520};

    const int GRID_SIZE = 50;
    const int WALL_WIDTH = 5;
    struct pair arena_grid_size = calc_arena_grid_size(WINDOW_SIZE, GRID_SIZE, WALL_WIDTH);
    struct pair arena_pixel_size = calc_arena_pixel_size(arena_grid_size, GRID_SIZE);

    const struct arena ARENA =
    {   
        .grid_size = GRID_SIZE,
        .wall_width = WALL_WIDTH,
        .arena_grid_size = arena_grid_size,
        .arena_pixel_size = arena_pixel_size,
    };

    setWindowSize(WINDOW_SIZE.x, WINDOW_SIZE.y);
    reset_rand();

    struct pair pos_marker = draw_background(WINDOW_SIZE, ARENA);
    draw_foreground(WINDOW_SIZE, ARENA, pos_marker);
}