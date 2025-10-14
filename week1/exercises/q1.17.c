#include <stdio.h>
#include <string.h>

int modulo(const char *num, int divisor)
{
    int remainder = 0;
    for (int i=0; i<strlen(num); i++)
    {  
        // 10*a + b mod m = ((a mod m)*10 + b) mod m
        // a = qm + (a mod m)
        // 10*a + b = 10*qm + 10*(a mod m)+ b
        // qm is multiple of m, hence qm mod m = 0
        // hence 10*qm + 10*(a mod m)+ b = 10*(a mod m)+ b
        remainder = (remainder * 10 + (num[i]-'0')) % divisor;
    }
    return remainder;
}

int is_prime(const char *num)
{   
    if((strcmp(num,"0")==0) || (strcmp(num,"1")==0))
    {
        return 0;
    }

    if((num[strlen(num)-1]-'0')%2==0)
    {
        return 0;
    }

    for(int d=3; d<=10000; d+=2)
    {
        if(modulo(num,d)==0)
        {
            return 0;
        }
    }
    return 1;
    
}

int main()
{
    char num[101];
    printf("Input a positive integer (up to 100 digits long): ");
    scanf("%100s", num);

    if (is_prime(num)==1)
    {
        printf("The integer is a prime number.\n");
    }
    else
    {
        printf("The integer is not a prime number.\n");
    }

    return 0;
}