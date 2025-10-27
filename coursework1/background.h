#ifndef BACKGROUND_H
#define BACKGROUND_H

struct pair
{
    int x;
    int y;
};

struct arena
{
    struct pair arena_grid_size;
    struct pair arena_pixel_size;
    int grid_size;
    int wall_width;
};

struct pair calc_arena_grid_size(struct pair window_size, int grid_size, int wall_width);
struct pair calc_arena_pixel_size(struct pair arena_grid_size, int grid_size);

struct pair grid_to_pixel(struct pair grid_coord, struct arena arena);
int is_near_wall(struct pair grid_coord, struct pair arena_grid_size);
void reset_rand();
struct pair rand_grid_coord(struct pair arena_grid_size);
struct pair draw_background(struct pair window_size, struct arena arena);

#endif