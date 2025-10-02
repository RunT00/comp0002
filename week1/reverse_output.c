#include <stdio.h>

void doSomething(int number){
    int rightDigit;
    do{
        rightDigit = number%10;
        printf("%i", rightDigit);
        number = number/10;
    }while(number!=0);
}

int enterNumber(){
    int number;
    printf("Enter your number: ");
    scanf("%i", &number);
    return number;
}

int main(){
    int number = enterNumber();
    doSomething(number);
    printf("\n");
    return 0;
}