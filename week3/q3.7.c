#include <stdio.h>

int is_prime(int num)
{   
    if (num < 2)
    {
        return 0;
    }
    else if (num == 2)
    {
        return 1;
    }
    else if (num % 2 == 0)
    {
        return 0;
    }
    else
    {
        for (int i=3; i< num; i+=2)
        {
            if (num % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }

}

int main()
{
    int start, end;
    int prev_p = 0;

    printf("Input start and end: ");
    scanf("%d %d", &start, &end);

    for(int i=start; i<=end; i++)
    {
        if (i%2==0 && i!=2)
        {
            continue;
        }
        if (is_prime(i))
        {
            if (prev_p == 0)
            {
                prev_p = i;
            }
            else
            {
                if (i - prev_p <= 2)
                {
                    printf("%d %d\n", prev_p, i);   
                }
                prev_p = i;
            }
        }
    }


    return 0;
}