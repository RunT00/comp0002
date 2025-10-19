#include "graphics.h"

const int w_width = 200;
const int w_height = 200;

const int g_width = 10;
const int g_height = 10;

int x=0, y=0;
const int x_start=0;

int colour_config[] = {1,1,1,0,1,0,0,0,1,0};

int next_grid()
{
    if (w_width - (x+g_width) >= g_width)
    {
        x = x + g_width;
    }
    else if (w_height - (y+g_height) >= g_height)
    {
        y = y + g_height;
        x = x_start;
    }
    else
    {
        return 0;
    }
    return 1;
}

void draw_grid(int is_blue)
{
    if (is_blue)
    {
        setColour(blue);
    }
    else
    {
        setColour(yellow);
    }
    fillRect(x, y, g_width, g_height);
}

void main()
{   
    setWindowSize(w_width, w_height);
    int run = 1;
    int idx = 0, total = 0, row = 0;
    while (run)
    {
        draw_grid(colour_config[idx]);
        idx = (idx + 1) % 10;
        total += 1;
        if (total % 20 == 0) 
        {   
            idx = 0;
            row += 1;
            idx = (idx + row * 3) % 10;
        }
        if (!next_grid())
        {
            break;
        }
    }
}