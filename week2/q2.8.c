#include <stdio.h>

int main()
{
    for(int row=1; row<=6; row++)
    {
        for(int col=1; col<=6; col++)
        {
            if((row+col)%2==0)
            {
                printf("%c", '*');
            }
            else
            {
                printf("%c", '#');
            }
        }
        printf("\n");
    }

    return 0;
}