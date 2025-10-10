#include <stdio.h>

int main()
{
    int reverse = 0;
    int length = 1;

    while (length>0)
    {
        for(int i=1; i<=length; i++)
        {
            if((i==1)||(i==length))
            {
                printf("%c", '*');
            }
            else
            {
                printf("%c",' ');
            }
        }
        
        if (length==5)
        {
            reverse = 1;
        }
        
        if (reverse == 0)
        {
            length = length + 1;
        }
        else
        {
            length = length - 1;
        }
        
        printf("\n");
    }

    return 0;
}