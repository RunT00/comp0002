#include <stdio.h>

int loop_power(int x, int y)
{   
    if (y == 0)
    {
        return 1;
    }
    int num = x;
    for (int i=0; i<y-1; i++)
    {
        x = x*num;
    }
    return x;
}

int start_recursion(int x, int y, int cur_pow)
{
    return recursive_power(x, y, cur_pow, x);
}

int recursive_power(int x, int y, int cur_pow, int num)
{   
    if (cur_pow == y)
    {
        return x;
    }
    else if (y == 0)
    {
        return 1;
    }
    recursive_power(x*num, y, cur_pow+1, num);
}

int main()
{   
    int x, y;
    printf("Input a positive integer and a power: ");
    scanf("%d %d", &x, &y);
    printf("Result by loop is %d\n", loop_power(x,y));
    printf("Result by recursion is %d\n", start_recursion(x,y,1));

    return 0;
}