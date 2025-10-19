#include <stdio.h>

int main()
{   
    long a;
    printf("Input a long integer: ");
    scanf("%ld", &a);

    long temp = a;
    long b = 0;
    
    while(temp != 0)
    {
        b = b*10 + temp % 10;
        temp = temp / 10;
    }
    
    if (a == b)
    {
        printf("It is a palindrome.\n");
    }
    else
    {
        printf("It is not a palindrome.\n");
    }

    return 0;
}