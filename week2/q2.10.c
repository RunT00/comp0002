#include <stdio.h>

int main()
{
    for(int row=1; row <= 8; row++)
    {
        for(int col=1; col <= 7; col++)
        {
            if(row == 1)
            {
                printf("%c", '*');
            }
            else if(row == 8)
            {
                printf("%c", '#');
            }
            else
            {
                if((col == 1)||(col == row-1))
                {
                    printf("%c", '#');
                }
                else if((col == row)||(col == 7))
                {
                    printf("%c", '*');
                }
                else
                {
                    printf("%c", ' ');
                }
            }

        }
        printf("\n");
    }

    return 0;
}