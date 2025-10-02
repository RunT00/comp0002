# include "graphics.h"
# include <stdio.h>
# include <math.h>

int main(void)
{   
    double pi = 3.1415926;
    double centre_x = 150;
    double centre_y = 150;
    double radius = 150;
    double angle = 0;
    double x_list[7];
    double y_list[7];
    for (int i=0; i<7; i++)
    {
        x_list[i] = centre_x+radius*cos(angle);
        y_list[i] = centre_y+radius*sin(angle);
        angle = angle+2*pi/7;
    }
    for (int i=0; i<7; i++)
    {
        drawLine(x_list[i],y_list[i],x_list[(i+1)%7],y_list[(i+1)%7]);
    }
    return 0;
}