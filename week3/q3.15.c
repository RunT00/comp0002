#include <stdio.h>
#include <time.h>
#include "checkdate.h"

int min(int x, int y)
{
    if (x > y)
    {
        return y;
    }
    else
    {
        return x;
    }
}

int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int main()
{
    int date[2]={0}, month[2]={0}, year[2]={0};
    for (size_t i=0; i<2; i++)
    {
        printf("Input a date in dd-mm-yyyy: ");
        scanf("%d-%d-%d", &date[i], &month[i], &year[i]);
        if (check_date(date[i], month[i], year[i]))
        {
            printf("Invalid date\n");
            return 0;
        }
    }

    struct tm t0={0}, t1={0};
    struct tm *t[] = {&t0, &t1};
    for (size_t i=0; i<2; i++)
    {
        t[i]->tm_mday = date[i];
        t[i]->tm_mon = month[i] - 1;
        t[i]->tm_year = year[i];
        mktime(t[i]);
    }

    if (year[0] == year[1])
    {
        printf("%d days\n", max(t[0]->tm_yday, t[1]->tm_yday) - min(t[0]->tm_yday, t[1]->tm_yday));
    }
    else 
    {   
        size_t total = 0;
        size_t num_day[2] = {365,366};
        for (size_t i=min(year[0],year[1]); i<=max(year[0],year[1]); i++)
        {
            if (i == year[0])
            {
                total += num_day[check_leap(i)] - (t[0]->tm_yday + 1); // tm_yday from 0 to 365
            }
            else if (i == year[1])
            {
                total += (t[1]->tm_yday + 1);
            }
            else
            {
                total += num_day[check_leap(i)];
            }
        }
        printf("%zu days\n", total);
    }
    
    

    return 0;
}
