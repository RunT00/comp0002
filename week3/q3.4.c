#include <stdio.h>

int main()
{   
    int start, end;
    printf("Input start and end integers: ");
    scanf("%d %d", &start, &end);

    int product = 1;
    for(int i=start; i<=end; i++)
    {
        product = product * i;
    }

    printf("Product is %d\n", product);

    return 0;
}