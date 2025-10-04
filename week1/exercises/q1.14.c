#include "graphics.h"
#include <math.h>

void calNewVer(double x1, double y1, double x2, double y2, int ttl)
{   
    if (ttl==0)
    {
        drawLine((int)x1,(int)y1,(int)x2,(int)y2);
    }
    else
    {
        double p1_x = x1+(1.0/3.0)*(x2-x1);
        double p1_y = y1+(1.0/3.0)*(y2-y1);
        calNewVer(x1,y1,p1_x,p1_y,ttl-1);
        
        double p2_x = x1+(2.0/3.0)*(x2-x1);
        double p2_y = y1+(2.0/3.0)*(y2-y1);
        
        double dx = (x2-x1)/3.0;
        double dy = (y2-y1)/3.0;

        double p3_x = p1_x + dx*0.5 + dy*sqrt(3.0)/2.0;
        double p3_y = p1_y - dx*sqrt(3.0)/2.0 + dy*0.5;
        // rotation matrix R
        // { cosx, -sinx
        //   sinx,  cosx }
        // to anticlockwisely rotate radian x
        // where v' = R*v
        
        // so the clockwise rotation matrix is
        // { cosx, sinx
        //  -sinx, cosx }
        
        // note that in computer coordinates, increasing x goes right and increasing y goes downward
        // so an anticlockwise rotation matrix actually looks like clockwise rotation in drawing
        // so for anticlockwise rotation in drawing, a clockwise rotation matrix has to be applied

        calNewVer(p1_x,p1_y,p3_x,p3_y,ttl-1);
        
        calNewVer(p3_x,p3_y,p2_x,p2_y,ttl-1);

        calNewVer(p2_x,p2_y,x2,y2,ttl-1);
    }
    
}   

int main()
{
    setWindowSize(1000,1000);

    double x1 = 200;
    double x2 = 400;
    double x3 = 600;

    double y1 = 400;
    double y2 = 400 - (200*sqrt(3.0));
    double y3 = 400;

    int ttl = 4;
    calNewVer(x1,y1,x2,y2,ttl);
    calNewVer(x2,y2,x3,y3,ttl);
    calNewVer(x3,y3,x1,y1,ttl);

}