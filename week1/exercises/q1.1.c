// Written by Thomas Lin on 02/Oct/2025
// This program displays ny name.

#include<stdio.h>
#include<string.h>

int main(void)
{
    char myName[] = "Thomas Lin";
    printf("Hello, my name is %s\n", myName);
    int index = strlen(myName) - 1;
    while (index > -1)
    {
        printf("%c", myName[index]);
        index = index - 1;
    }
    printf("\n");
    return 0;
}