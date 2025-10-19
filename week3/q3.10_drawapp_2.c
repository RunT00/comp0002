#include <stdio.h>

FILE *fptr;

void main()
{
    fptr = fopen("q3.10.txt", "r");
    char content[100];
    while(fgets(content, 100, fptr))
    {
        printf("%s", content);
    }
    fclose(fptr);
}
