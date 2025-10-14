#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include <time.h>

void main()
{   
    srand(time(NULL));
    int window_width = 1000;
    int window_height = 1000;
    setWindowSize(window_width, window_height);

    setRGBColour(0,0,153);
    fillRect(0,0,1000,1000);

    int num_star = rand()%11;
    int star_x, star_y, star_width, star_height;

    for (int i=0; i<num_star; i++)
    {
        star_x = rand()%901;
        star_y = rand()%301;
        star_width = rand()%71;
        if (star_width < 20)
        {
            star_width = 20;
        }
        star_height = star_width;
        setColour(black);
        drawOval(star_x, star_y, star_width, star_height);
        setRGBColour(224,224,224);
        fillOval(star_x, star_y, star_width, star_height);
    }

    int is_moon = rand()%2;

    if (is_moon)
    {
        int moon_x = rand()%801;
        int moon_y = rand()%201;
        int moon_width = rand()%201;
        if (moon_width < 100)
        {
            moon_width = 100;
        }
        int moon_height = moon_width;

        setColour(black);
        drawOval(moon_x, moon_y, moon_width, moon_height);
        setColour(yellow);
        fillOval(moon_x, moon_y, moon_width, moon_height);
    }

    int num_building = rand()%11;

    int x, y, width, height;
    int num_window, x_offset, y_offset, is_lit;
    for (int i=0; i<num_building; i++)
    {
        x = rand()%801;
        y = rand()%401;
        width = rand()%301;
        height = window_height - y;

        setColour(black);
        drawRect(x, y, width, height);
        setRGBColour(rand()%256, rand()%256, rand()%256);
        fillRect(x, y, width, height);
        
        x_offset = 10;
        y_offset = 15;

        while (height-y_offset>=40)
        {
            while(width-x_offset>=30)
            {
                drawRect(x+x_offset, y+y_offset, 20, 30);
                is_lit = rand()%2;
                if (is_lit)
                {
                    setColour(yellow);
                    fillRect(x+x_offset, y+y_offset, 20, 30);
                }
                else
                {
                    setColour(darkgray);
                    fillRect(x+x_offset, y+y_offset, 20, 30);
                }
                drawLine(x+x_offset, y+y_offset+10, x+x_offset+20, y+y_offset+10);
                drawLine(x+x_offset+10, y+y_offset, x+x_offset, y+y_offset+30);
                x_offset = x_offset + 30;
            }
            
            y_offset = y_offset + 40;
            x_offset = 10;
        }
        
    }
}