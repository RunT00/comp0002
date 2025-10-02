#include "graphics.h"

int main(void)
{
    setWindowSize(1000,1000);

    setColour(red);
    fillArc(100,100,500,200,10,160);
    
    setColour(orange);
    fillArc(125,120,450,170,10,160);
    
    setColour(yellow);
    fillArc(150,140,400,140,10,160);
    
    setColour(green);
    fillArc(175,160,350,110,10,160);

    setColour(cyan);
    fillArc(200,180,300,80,10,160);

    setColour(blue);
    fillArc(225,200,250,50,10,160);

    setColour(magenta);
    fillArc(250,220,200,20,10,160);

    setColour(white);
    fillArc(275,240,150,10,10,160);
}