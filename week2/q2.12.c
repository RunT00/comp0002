#include "graphics.h"
#include <math.h>
#include <stdio.h>

void main()
{
    setWindowSize(1000,1000);

    drawLine(150,300,850,300); // x length 600 mid 500
    drawLine(500,75,500,575); // y length 450 mid 300
    
    
    int origin_x = 500;
    int origin_y = 300;

    int x_label[13] = {-290,-240,-190,-140,-90,-40,10,60,110,160,210,260,310};
    for(int i=0; i<13; i++)
    {
        drawLine(origin_x+x_label[i], origin_y, origin_x+x_label[i], origin_y+10);
    }
    
    int y_label[10] = {210,160,110,60,10,-40,-90,-140,-190,-240};
    for(int i=0; i<10; i++)
    {
        drawLine(origin_x, origin_y-y_label[i], origin_x+10, origin_y-y_label[i]);
    }

    setStringTextSize(15);
    
    char* x_text[13] = {"-290","-240","-190","-140","-90","-40","10","60","110","160","210","260","310"};
    for(int i=0; i<13; i++)
    {
        drawString(x_text[i], origin_x+x_label[i]-10, origin_y+24);
    }
    
    char* y_text[10] = {"2.1","1.6","1.1","0.6","0.1","-0.4","-0.9","-1.4","-1.9","-2.4"};
    for(int i=0; i<10; i++)
    {
        drawString(y_text[i], origin_x+15, origin_y-y_label[i]+4);
    }
    
    const double pi = 3.1415926;

    // sin(x)
    setColour(red);
    int y;
    int prev_y = (int)(origin_y- sin((170-origin_x)*pi/180)*100);
    for(int i=171; i<=830; i++)
    {
        y = (int)(origin_y- sin((i-origin_x)*pi/180)*100);
        drawLine(i-1, prev_y, i, y);
        prev_y = y;
    }

    // cos(x)
    setColour(blue);
    prev_y = (int)(origin_y- cos((170-origin_x)*pi/180)*100);
    for(int i=171; i<=830; i++)
    {
        y = (int)(origin_y- cos((i-origin_x)*pi/180)*100);
        drawLine(i-1, prev_y, i, y);
        prev_y = y;
    }

    // tan(X)
    setColour(yellow);
    prev_y = (int)(origin_y- tan((170-origin_x)*pi/180)*100);
    for(int i=171; i<=830; i++)
    {
        y = (int)(origin_y- tan((i-origin_x)*pi/180)*100);
        if((y<=560)&&(y>=100)&& !((i-origin_x)%90==0))
        {
            drawLine(i-1, prev_y, i, y);
        }
        prev_y = y;
    }
}