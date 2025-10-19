#include <stdio.h>
#include <string.h>

int n = 5;
int m = 10;

char buffer[5][256] = {"", "", "", "", ""};
int digits[10];

void big_minus (int x)
{
    switch (x)
    {
        case 0: strcat(buffer[0], "      "); break;
        case 1: strcat(buffer[1], "      "); break;
        case 2: strcat(buffer[2], " **** "); break;
        case 3: strcat(buffer[3], "      "); break;
        case 4: strcat(buffer[4], "      "); break;
    }
}

void big0 (int x)
{   
    switch (x)
    {
        case 0: strcat(buffer[0], " **** "); break;
        case 1: strcat(buffer[1], " *  * "); break;
        case 2: strcat(buffer[2], " *  * "); break;
        case 3: strcat(buffer[3], " *  * "); break;
        case 4: strcat(buffer[4], " **** "); break;
    }
}

void big1 (int x)
{   
    switch (x)
    {
        case 0: strcat(buffer[0], "  **  "); break;
        case 1: strcat(buffer[1], " ***  "); break;
        case 2: strcat(buffer[2], "  **  "); break;
        case 3: strcat(buffer[3], "  **  "); break;
        case 4: strcat(buffer[4], "******"); break;
    }
}

void big2 (int x)
{   
    switch (x)
    {
        case 0: strcat(buffer[0], "******"); break;
        case 1: strcat(buffer[1], "     *"); break;
        case 2: strcat(buffer[2], "******"); break;
        case 3: strcat(buffer[3], "*     "); break;
        case 4: strcat(buffer[4], "******"); break;
    }
}

void big3 (int x)
{   
    switch (x)
    {
        case 0: strcat(buffer[0], "******"); break;
        case 1: strcat(buffer[1], "     *"); break;
        case 2: strcat(buffer[2], "******"); break;
        case 3: strcat(buffer[3], "     *"); break;
        case 4: strcat(buffer[4], "******"); break;
    }
}

void big4 (int x)
{   
    switch (x)
    {
        case 0: strcat(buffer[0], "*    *"); break;
        case 1: strcat(buffer[1], "*    *"); break;
        case 2: strcat(buffer[2], "******"); break;
        case 3: strcat(buffer[3], "     *"); break;
        case 4: strcat(buffer[4], "     *"); break;
    }
}

void big5 (int x)
{   
    switch (x)
    {
        case 0: strcat(buffer[0], "******"); break;
        case 1: strcat(buffer[1], "*     "); break;
        case 2: strcat(buffer[2], "******"); break;
        case 3: strcat(buffer[3], "     *"); break;
        case 4: strcat(buffer[4], "******"); break;
    }
}

void big6 (int x)
{   
    switch (x)
    {
        case 0: strcat(buffer[0], "******"); break;
        case 1: strcat(buffer[1], "*     "); break;
        case 2: strcat(buffer[2], "******"); break;
        case 3: strcat(buffer[3], "*    *"); break;
        case 4: strcat(buffer[4], "******"); break;
    }
}

void big7 (int x)
{   
    switch (x)
    {
        case 0: strcat(buffer[0], "******"); break;
        case 1: strcat(buffer[1], "     *"); break;
        case 2: strcat(buffer[2], "     *"); break;
        case 3: strcat(buffer[3], "     *"); break;
        case 4: strcat(buffer[4], "     *"); break;
    }
}

void big8 (int x)
{   
    switch (x)
    {
        case 0: strcat(buffer[0], "******"); break;
        case 1: strcat(buffer[1], "*    *"); break;
        case 2: strcat(buffer[2], "******"); break;
        case 3: strcat(buffer[3], "*    *"); break;
        case 4: strcat(buffer[4], "******"); break;
    }
}

void big9 (int x)
{
    switch (x)
    {
        case 0: strcat(buffer[0], "******"); break;
        case 1: strcat(buffer[1], "*    *"); break;
        case 2: strcat(buffer[2], "******"); break;
        case 3: strcat(buffer[3], "     *"); break;
        case 4: strcat(buffer[4], "******"); break;
    }
}

int len_num(int num)
{
    int length = 0;
    if (num == 0)
    {
        length = 1;
    }
    while (num!=0)
    {
        length += 1;
        num = num / 10;
    }

    return length;
}

void add_space ()
{
    for (int i=0; i<n; i++)
    {
        strcat(buffer[i], " ");
    }
}

void output_integer (int x)
{   for (int i=0; i<n; i++)
    {
        switch (x)
        {
            case 0: big0 (i); break;
            case 1: big1 (i); break;
            case 2: big2 (i); break;
            case 3: big3 (i); break;
            case 4: big4 (i); break;
            case 5: big5 (i); break;
            case 6: big6 (i); break;
            case 7: big7 (i); break;
            case 8: big8 (i); break;
            case 9: big9 (i); break;
            case 10: big_minus(i); break;
        }
    }
}

void output_line (int x, int i)
{   
    i = i-1;
    switch (x)
    {
        case 0: big0 (i); break;
        case 1: big1 (i); break;
        case 2: big2 (i); break;
        case 3: big3 (i); break;
        case 4: big4 (i); break;
        case 5: big5 (i); break;
        case 6: big6 (i); break;
        case 7: big7 (i); break;
        case 8: big8 (i); break;
        case 9: big9 (i); break;
    }
}

void print_screen()
{
    for (int i=0; i<n; i++)
    {
        printf("%s\n", buffer[i]);
    }
}

void insert_int (int num)
{   
    int counter = 0;
    if (num == 0)
    {
        digits[0] = 0;
        return;
    }
    while (num!=0)
    {
        digits[counter] = num % 10;
        counter += 1;
        num = num / 10;
    }
}

int main()
{   
    int num;
    printf("Input number: ");
    scanf("%d", &num);

    if (num < 0)
    {
        output_integer(10);
    }
    num = -1 * num;
    insert_int(num);

    for (int i= len_num(num)-1; i>=0; i--)
    {   
        output_integer(digits[i]);
        add_space();
    }

    print_screen();
    
    return 0;
}