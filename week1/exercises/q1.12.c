#include"graphics.h"

int main(void)
{
    setWindowSize(1000,1000);

    drawLine(150,150,150,550);

    setColour(blue);
    fillRect(150,430,100,120);
    setColour(green);
    fillRect(250,270,100,280);
    setColour(red);
    fillRect(350,310,100,240);
    setColour(yellow);
    fillRect(450,370,100,180);
    setColour(magenta);
    fillRect(550,270,100,280);
    
    setColour(black);
    drawLine(130,550,660,550);
    drawLine(130,250,150,250);
    drawLine(130,350,150,350);
    drawLine(130,450,150,450);

    setStringTextSize(20);
    drawString("150",90,260);
    drawString("100",90,360);
    drawString("50",90,460);
    drawString("0",90,560);

    drawString("CDs",170,580);
    drawString("DVDs",270,580);
    drawString("Books",370,580);
    drawString("Clothes",460,580);
    drawString("Shoes",570,580);
}