#include <stdio.h>
#include "graphics.h"
#include <math.h>

void main()
{   
    setWindowSize(1000,1000);
    int origin_x = 500;
    int origin_y = 300;
    
    const double pi = 3.1415926;
    double radius = 1;
    int x;
    int y;
    int prev_x = origin_x;
    int prev_y = origin_y;

    for(int i=180+360*11; i>=0; i--)
    {
        x = (int)(origin_x + radius*cos(i*pi/180));
        y = (int)(origin_y - radius*sin(i*pi/180));

        drawLine(prev_x, prev_y, x, y);

        radius = radius + 0.2;
        prev_x = x;
        prev_y = y;
    }
}