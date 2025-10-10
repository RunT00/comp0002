#include <stdio.h>

int main()
{   
    for(int row=1; row<=7; row++)
    {
        for(int col=1; col<=8; col++)
        {
            if(row==1 || row==7 || col==1 || col==8)
            {
                printf("%c", '*');
            }
            else
            {
                if((col>=3 && col<=6)&&(row>=3 && row<=5)&& !((row==4)&&(col>=4)&&(col<=5)))
                {
                    printf("%c", '#');
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