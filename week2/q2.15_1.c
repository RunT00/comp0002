#include <stdio.h>
#include "graphics.h"

void main()
{
    FILE *fptr = fopen("q2.15.txt","w");
    fclose(fptr);
    fptr = fopen("q2.15.txt","a");

    int canvas_width = 1000;
    int canvas_height = 1000;
    fprintf(fptr, "SW %i %i\n", canvas_width, canvas_height);

    int choice;
    int x, y, width, height;
    int x1,x2,x3,y1,y2,y3;

    printf("Input 1 for rectangle, 2 for triangle: ");
    scanf("%d", &choice);

    if(choice==1)
    {   
        printf("Input x, y, width, height (separate by space): ");
        scanf("%d %d %d %d", &x, &y, &width, &height);
        fprintf(fptr, "DR %i %i %i %i\n", x, y, width, height);
    }        
    else
    {
        printf("Input x1, y1, x2, y2, x3, y3 (separate by space): ");
        scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
        fprintf(fptr, "DL %i %i %i %i\n", x1, y1, x2, y2);
        fprintf(fptr, "DL %i %i %i %i\n", x2, y2, x3, y3);
        fprintf(fptr,"DL %i %i %i %i\n", x1, y1, x3, y3);
    }
    
    fclose(fptr);

}