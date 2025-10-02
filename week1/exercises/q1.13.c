#include"graphics.h"
#include<math.h>

int main(void)
{   
    setWindowSize(1000,1000);
    double delta_y;
    int y;
    int prev_y=0;
    double pi = 3.1415926;
    for(int i=1; i<900;i++)
    {
        delta_y = sin(i*pi/180)*200;
        y = (int)(300-delta_y); // + goes down, - goes up
        drawLine(i-1,prev_y,i,y);
        prev_y = y;
    }
}