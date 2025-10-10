#include <stdio.h>
#include "graphics.h"

void main()
{
    FILE *fptr = fopen("q2.15.txt","r");

    char content[100];
    while(fgets(content, 100, fptr))
    {
        printf("%s", content);
    }
    fclose(fptr);
}