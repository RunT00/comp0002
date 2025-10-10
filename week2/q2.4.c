#include <stdio.h>

int main()
{
    for (int row = 1; row <= 4; row++)
    {
        for (int col = 1; col <= 5; col++)
        {
            if(row==1 || row==4 || col==1 || col==5)
            {
                printf("%c", '*');
            }
            else
            {
                printf("%c", ' ');
            }
        }
        printf("\n");
    }

    return 0;
}