#include "graphics.h"

float scale = 0.5;

#define S(x) ((int)((x) * scale))

int main(void){
    setWindowSize(S(1500), S(1100));

    // background
    // horizontal
    drawLine(S(380), S(200), S(1400), S(200));
    drawLine(S(380), S(300), S(400), S(300));
    drawLine(S(380), S(400), S(400), S(400));
    drawLine(S(380), S(500), S(400), S(500));
    drawLine(S(380), S(600), S(400), S(600));
    drawLine(S(380), S(700), S(400), S(700));
    drawLine(S(380), S(800), S(400), S(800));
    drawLine(S(380), S(900), S(400), S(900));
    drawLine(S(380), S(1000), S(1400), S(1000));

    // vertical
    drawLine(S(400), S(200), S(400), S(1020));
    drawLine(S(500), S(200), S(500), S(1020));
    drawLine(S(600), S(200), S(600), S(1020));
    drawLine(S(700), S(200), S(700), S(1020));
    drawLine(S(800), S(200), S(800), S(1020));
    drawLine(S(900), S(200), S(900), S(1020));
    drawLine(S(1000), S(200), S(1000), S(1020));
    drawLine(S(1100), S(200), S(1100), S(1020));
    drawLine(S(1200), S(200), S(1200), S(1020));
    drawLine(S(1300), S(200), S(1300), S(1020));
    drawLine(S(1400), S(200), S(1400), S(1020));

    // blue bars
    setRGBColour(152,152,255);

    fillRect(S(400), S(233), S(500), S(34));
    fillRect(S(400), S(333), S(100), S(34));
    fillRect(S(400), S(433), S(900), S(34));
    fillRect(S(400), S(533), S(400), S(34));
    fillRect(S(400), S(633), S(800), S(34));
    fillRect(S(400), S(733), S(300), S(34));
    fillRect(S(400), S(833), S(200), S(34));
    fillRect(S(400), S(933), S(500), S(34));

    setColour(black);

    drawRect(S(400), S(233), S(500), S(34));
    drawRect(S(400), S(333), S(100), S(34));
    drawRect(S(400), S(433), S(900), S(34));
    drawRect(S(400), S(533), S(400), S(34));
    drawRect(S(400), S(633), S(800), S(34));
    drawRect(S(400), S(733), S(300), S(34));
    drawRect(S(400), S(833), S(200), S(34));
    drawRect(S(400), S(933), S(500), S(34));

    // title
    setStringTextSize(30);
    drawString("Favorite Graphs",202,75);

    // labels
    // horizontal
    setStringTextSize(20);
    drawString("Scatter Graphs",50,130);
    drawString("Frequency Polygon",18,180);
    drawString("Line Graphs",80,230);
    drawString("Comp.Pie Graphs",25,280);
    drawString("Pictograms",85,330);
    drawString("Histograms",85,380);
    drawString("Pie Graphs",85,430);
    drawString("Bar Charts",87,480);

    // vertical
    drawString("0",195,535);
    drawString("1",245,535);
    drawString("2",295,535);
    drawString("3",345,535);
    drawString("4",395,535);
    drawString("5",445,535);
    drawString("6",495,535);
    drawString("7",545,535);
    drawString("8",595,535);
    drawString("9",645,535);
    drawString("10",690,535);
}