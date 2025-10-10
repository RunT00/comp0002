#include <stdio.h>

int main()
{
    int counter = 1;
    while (counter<10)
    {
        printf("%d * 13 = %d \n",counter,counter*13);
        counter = counter + 1;
    }
    return 0;
}