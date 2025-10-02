// Written by Thomas Lin on 02/Oct/2025
// This program displays ny name.

#include<stdio.h>
#include<string.h>

int main(void)
{
    char myName[] = "Thomas Lin";
    char name[] = "Dept. of Computer Science";
    char address[] = "Malet Place Engineering Building";

    printf("Hello, my name is %s\n", myName);
    printf("I'm in %s\n", name);
    printf("The address is %s\n", address);

    return 0;
}