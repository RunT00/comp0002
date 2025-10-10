#include <stdio.h>

int main()
{
    printf("a)\n");
    for(int i=1; i<=100; i++)
    {
        printf("%d ", i*i);
    }
    printf("\n\n");

    printf("b)\n");
    for(int i=1; i<=101; i++)
    {
        if(i%2==0)
        {
            printf("%d ", i*i);
        }
    }
    printf("\n\n");

    printf("c)\n");
    int prime[100];
    prime[0] = 2;
    int idx = 1;
    int output;
    printf("2 ");
    
    for(int i=3; i<=100; i++)
    {
        output = 1;
        for(int j=0; j<idx; j++)
        {
            if(i%prime[j]==0)
            {
                output = 0;
                break;
            }
        }   
        if(output==1)
        {   
            prime[idx] = i;
            idx = idx + 1;
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}