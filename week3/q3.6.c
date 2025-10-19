#include <stdio.h>
#include <string.h>

int main()
{
    char input[21];
    int stop = 0;

    while (!stop)
    {  
        int success = 1; 
        long num = 0;
        int negative = 0;

        printf("Input a valid integer: ");
        fgets(input, sizeof(input), stdin);
        size_t len = strlen(input);
        if (len>0 && input[len-1]=='\n')
        {
            input[len-1] = '\0';
        }

        if (strcmp(input, "stop") == 0)
        {
            break;
        }

        for (int i=0; i<strlen(input); i++)
        {   
            if (input[i] == ' ')
            {   
                continue;
            } 
            if (input[i]=='-')
            {
                if (negative == 1 || num!=0)
                {   
                    success = 0;
                    break;
                }
                else
                {
                    negative = 1;
                    continue;
                }
            }
            if ( !((input[i]>='0' && input[i]<='9') || (input[i]=='-')) )
            {   
                success = 0;
                break;
            }

            if (negative == 1)
            {
                num = num*10 - (input[i]-'0');
            }
            else
            {
                num = num*10 + (input[i]-'0');
            }
        }

        if (success)
        {
            printf("%ld\n", num);
        }
    }

    return 0;
}