#include <stdio.h>

int main()
{
    int hours;
    char minutes[3];
    printf("Input 24 hour format (in form hh:mm): ");
    scanf("%d:%2s", &hours, minutes);

    char *suffix[] = {"am", "pm"};
    int temp = hours;
    if (hours % 12 == 0)
    {
        hours = 12;
    }
    else
    {
        hours = hours % 12;
    }
    printf("%d.%s%s\n", hours, minutes, suffix[temp/12]);
    return 0;
}