#include <stdio.h>
#include <string.h>

void search(int pos, int current_sum, int last_operand, char expr[], int target, char digits[])
{   
    if(pos == strlen(digits))
    {
        if(current_sum == target)
        {
            printf("%s = %d\n", expr, target);
            
        }
        return;
    }
   
    int next_digit = digits[pos] - '0';

    char new_expr[256];

    // 1 = concatenate
    sprintf(new_expr, "%s%d", expr, next_digit);
    int new_operand;
    if(last_operand >= 0)
    {
        new_operand = last_operand*10 + next_digit;
    }
    else
    {
        new_operand = last_operand*10 - next_digit;
    }
    search(pos+1, current_sum-last_operand+new_operand, new_operand, new_expr, target, digits);

    // 2 = '+'
    sprintf(new_expr, "%s+%d", expr, next_digit);
    search(pos+1, current_sum+next_digit, next_digit, new_expr, target, digits);

    // 3 = '-'
    sprintf(new_expr, "%s-%d", expr, next_digit);
    search(pos+1, current_sum-next_digit, -next_digit, new_expr, target, digits);

    // 4 = '*'
    sprintf(new_expr, "%s*%d", expr, next_digit);
    search(pos+1, current_sum-last_operand+last_operand*next_digit, last_operand*next_digit, new_expr, target, digits);

    // 5 = '/'
    if(last_operand%next_digit==0)
    {
        sprintf(new_expr, "%s/%d", expr, next_digit);
        search(pos+1, current_sum-last_operand+last_operand/next_digit, last_operand/next_digit, new_expr, target, digits);
    }
    
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char digits[], int l, int r, int target)
{
    if(l == r)
    {
        char start_expr[2] = {digits[0], '\0'};
        search(1, digits[0]-'0', 1, start_expr, target, digits);
        return;
    }

    for(int i=l; i<=r; i++)
    {
        swap(&digits[l], &digits[i]);
        permute(digits, l+1, r, target);
        swap(&digits[l], &digits[i]);
    }

}

void main()
{   
    printf("Input the target number: ");
    int target;
    scanf("%d", &target);
    char digits[] = "123456789";
    permute(digits, 0, strlen(digits)-1, target);

}