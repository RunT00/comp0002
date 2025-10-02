#include <stdio.h>

int main()
{
    int counter = 0;
    while (counter<10)
    {
        printf("Hey it's me");
        printf("%i", counter);
        printf("!\n");
        counter = counter+1;
    }
    return 0;
}