#include <stdio.h>
#include <time.h>
#include "checkdate.h"

int main()
{
    int date, month, year;
    printf("Input date in dd-mm-yyyy: ");
    scanf("%d-%d-%d", &date, &month, &year);

    if (check_date(date, month, year) == 0)
    {
        struct tm t = {0};
        t.tm_mday = date;
        t.tm_mon = month - 1;
        t.tm_year = year - 1900;
        mktime(&t);

        const char* day_name[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        printf("%s, ", day_name[t.tm_wday]);
        if (check_leap(year))
        {
            printf("is a leap year\n");
        }
        else
        {
            printf("not a leap year\n");
        }
    }
    else
    {
        printf("Invalid date\n");
    }

    return 0;
}