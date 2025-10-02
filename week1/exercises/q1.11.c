#include "graphics.h"

int main()
{   
    setWindowSize(1920,1080);
    setStringTextSize(30);
    drawString("Main Buildings",50,50);

    setStringTextSize(25);
    drawString("UCL Computer Science",50,100);
    drawString("UCL Computer Science",350,100);
    drawString("UCL Computer Science",650,100);

    setStringTextSize(20);
    drawString("66-72 Gower Street",50,140);
    drawString("London",50,180);
    drawString("WC1E 6EA",50,220);

    drawString("169 Euston Road",350,140);
    drawString("London",350,180);
    drawString("NW1 2AE",350,220);

    drawString("90 High Holborn",650,140);
    drawString("London",650,180);
    drawString("WC1V 6LJ",650,220);

    setStringTextSize(30);
    drawString("Bloomsbury Campus",50,300);

    setStringTextSize(25);
    drawString("UCL Computer Sciencee",50,350);
    drawString("UCL Computer Science",600,350);

    setStringTextSize(20);
    drawString("Malet Place Engineering Building (MPEB) Floors 4 and 6",50,390);
    drawString("London",50,430);
    drawString("WC1E 7JE",50,470);
    drawString("Engineering Front Building (EFB)",600,390);
    drawString("Floors 3",600,430);
    drawString("London",600,470);
    drawString("WC1E 7JE",600,510);

    setStringTextSize(30);
    drawString("UCL EAST",50,550);
    
    setStringTextSize(25);
    drawString("UCL Computer Science",50,600);
    drawString("UCL Computer Science",350,600);
    drawString("UCL Computer Science",650,600);

    setStringTextSize(20);
    drawString("1 Pool Street",50,640);
    drawString("London",50,680);
    drawString("E20 2AF",50,720);
    drawString("Marshgate",350,640);
    drawString("London",350,680);
    drawString("E20 2AE",350,720);
    drawString("Here East",650,640);
    drawString("London",650,680);
    drawString("E20 3BS",650,720);
}