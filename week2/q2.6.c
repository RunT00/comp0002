#include <stdio.h>

int main()
{   
    int reverse = 0;
    int numSpace = 0;

    while (!((reverse==1)&&(numSpace<0)))
   {
        
        for(int i=0; i<=numSpace; i++)
        {
            printf("%c", ' ');
        }
        for(int i=0; i<5; i++)
        {
            printf("%c", '*');
        }
        printf("\n");
        if(numSpace == 4)
        {
            reverse = 1;
        }
        if(reverse == 0)
        {
            numSpace = numSpace + 1;
        }
        else
        {
            numSpace = numSpace - 1;
        }
   }

    return 0;
}