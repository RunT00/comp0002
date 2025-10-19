#include <stdio.h>

int factorial(int digit)
{
    int fac = 1;
    for(int i=2; i<=digit; i++)
    {
        fac = fac*i;
    }
    return fac;
}

int is_strong(int num)
{   
    int digit;
    int total = 0;
    int cmp = num;
    while (num!=0)
    {
        digit = num % 10;
        total = total + factorial(digit);
        num = num / 10;
    }

    if (total == cmp)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{   
    int start, end;
    printf("Input start and end: ");
    scanf("%d %d", &start, &end);

    for (int i=start; i<=end; i++)
    {
        if (is_strong(i))
        {
            printf("%d\n", i);
        }
    }

    return 0;
}