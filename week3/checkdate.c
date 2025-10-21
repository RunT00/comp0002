int check_leap(int year)
{
    if (year % 400 == 0)
    {
        return 1;
    }
    else if (year % 100 == 0)
    {
        return 0;
    }
    else if (year % 4 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int check_match_month(int date, int month, int year)
{
    if (month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        if (date > 31)
        {
            return 1;
        }
    }
    else if (month==4||month==6||month==9||month==11)
    {
        if (date > 30)
        {
            return 1;
        }
    }
    else // month==2
    {
        if (check_leap(year) == 1) // is leap year
        {
            if (date > 29)
            {
                return 1;
            }
        }
        else
        {
            if (date > 28)
            {
                return 1;
            }
        }
    }
    return 0;
}

int check_date(int date, int month, int year)
{
    if (date>31 || date < 1)
    {
        return 1;
    }
    else if (check_match_month(date, month, year))
    {
        return 1;
    }
    return 0;
}
