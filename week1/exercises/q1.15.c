#include "graphics.h"
#include <math.h>

void main()
{
    const int width = 300;
    const int height = 300;
    const int max_iter = 1000;
    setWindowSize(width, height);

    const double xmin = -2.0, xmax = 1.0;
    const double ymin = -1.5, ymax = 1.5;

    for(int y=0; y< height; y++)
    {
        for(int x=0; x< width; x++)
        {
            double a = xmin + (x / (double)width) * (xmax - xmin);
            double b = ymin + (y / (double)height) * (ymax - ymin);

            double zr = 0.0, zi = 0.0;
            int iter = 0;
            
            // Zn+1  = Zn^2 + c 
            // where c = a + i*b
            // z = zr + i*zi
            // z^2 = (zr + zi*i)^2 = zr^2 + 2*i*zr*zi -zi^2 = (zr^2-zi^2) + i*(2*zr*zi)
            // z^2 + c = (zr^2-zi^2+a) + i*(2*zr*zi+b)
            while((zr*zr + zi*zi<=4.0) && (iter < max_iter)) 
            {
                double zr_new = zr*zr - zi*zi + a;
                zi = 2*zr*zi + b;
                zr = zr_new;
                iter = iter + 1;
            }

            if (iter == max_iter)
            {
                setColour(white);
            }
            else if (iter % 8 == 1)
            {
                setColour(red);
            }
            else if (iter % 8 == 2)
            {
                setColour(green);
            }
            else if (iter % 8 == 3)
            {
                setColour(blue);
            }
            else if (iter % 8 == 4)
            {
                setRGBColour(102,255,255); // skyblue
            }
            else if (iter % 8 == 5)
            {
                setRGBColour(255,102,255); // pink
            }
            else if (iter % 8 == 6)
            {
                setColour(yellow);
            }
            else if (iter % 8 == 7)
            {
                setColour(white);
            }
            else
            {
                setColour(black);
            }

            fillRect(x,y,1,1);

        }
    }
   
}