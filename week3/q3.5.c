#include <stdio.h>
#include <string.h>

char* ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char* tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char* ten_one[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

char pron[256] = "";

void concat_two_digits(int num)
{
    strcat(pron, tens[num/10]);
    strcat(pron, " ");
    strcat(pron, ones[num%10]);
}

int main()
{   
    int num;
    printf("Input an integer between 0 and 999: ");
    scanf("%d", &num);

    if (num / 10 == 0) // one digit
    {
        if (num == 0)
        {
            printf("zero\n");
        }
        else
        {
            printf("%s\n", ones[num]);
        }
    }
    else if (num / 100 == 0) // two digits
    {
        if (num / 10 == 1)
        {
            printf("%s\n", ten_one[num%10]);
        }
        else
        {
            concat_two_digits(num);
            printf("%s\n", pron);
        }
    }
    else
    {
        strcat(pron, ones[num/100]);
        
        strcat(pron, " hundred");
        if ((num%100)==0)
        {
            printf("%s\n", pron);
        }
        else
        {
            strcat(pron, " and ");
            concat_two_digits(num%100);
            printf("%s\n", pron);
        }
        
    }

    return 0;
}