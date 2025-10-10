#include <stdio.h>

int main()
{   
    int numSpace;
    for (int row = 0; row < 6; row++)
    {
        numSpace = row;
        for (int col = 1; col <= 6; col++)
        {
            if (numSpace > 0)
            {
                printf("%c", ' ');
                numSpace = numSpace - 1;
            }
            else
            {
                printf("%c", '*');
            }
        }
        printf("\n");
    }

    return 0;
}