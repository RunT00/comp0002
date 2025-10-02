#include "graphics.h"

int main(void){
    setWindowSize(600,350);
    drawRect(20,20,50,50);
    fillRect(100,20,50,50);
    drawOval(50,100,30,40);
    displayImage("image.png",150,150);
    return 0;
}