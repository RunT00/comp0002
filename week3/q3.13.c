#include "graphics.h"
#include <math.h>
#define PI 3.1415946

void main()
{
    setWindowSize(1000, 1000);
    setColour(black);
    setLineWidth(2);

    int side = 200;
    int start_x = 200;
    int start_y = 200;
    double angle = PI/6;
    
    // left
    int upper_x1 = start_x;
    int upper_y1 = start_y;
    int lower_x1 = start_x;
    int lower_y1 = start_y + 150; 

    // mid upper
    int upper_x2 = upper_x1+(int)(sin(angle)*side);
    int upper_y2 = upper_y1-(int)(cos(angle)*side);
    int lower_x2 = lower_x1+(int)(sin(angle)*side);
    int lower_y2 = lower_y1-(int)(cos(angle)*side);

    // mid lower
    int upper_x3 = upper_x1+(int)(cos(angle)*side);
    int upper_y3 = upper_y1+(int)(sin(angle)*side);
    int lower_x3 = lower_x1+(int)(cos(angle)*side);
    int lower_y3 = lower_y1+(int)(sin(angle)*side);

    // right
    int upper_x4 = upper_x3+(int)(sin(angle)*side);
    int upper_y4 = upper_y3-(int)(cos(angle)*side);
    int lower_x4 = lower_x3+(int)(sin(angle)*side);
    int lower_y4 = lower_y3-(int)(cos(angle)*side);

    drawRectRotated(upper_x1, upper_y1, side, side, 300);
    drawRectRotated(lower_x1, lower_y1, side, side, 300);

    drawLine(upper_x1, upper_y1, lower_x1, lower_y1);
    drawLine(upper_x2, upper_y2, lower_x2, lower_y2);
    drawLine(upper_x3, upper_y3, lower_x3, lower_y3); 
    drawLine(upper_x4, upper_y4, lower_x4, lower_y4);

    setColour(red);
    fillRectRotated(upper_x1, upper_y1, side, side, 300);

    int left_x[4] = {upper_x1, upper_x3, lower_x3, lower_x1};
    int left_y[4] = {upper_y1, upper_y3, lower_y3, lower_y1};
    setColour(blue);
    fillPolygon(4, left_x, left_y);

    int right_x[4] = {upper_x3, upper_x4, lower_x4, lower_x3};
    int right_y[4] = {upper_y3, upper_y4, lower_y4, lower_y3};
    setColour(green);
    fillPolygon(4, right_x, right_y);
}