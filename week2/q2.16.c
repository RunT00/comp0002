#include <stdio.h>
#include <string.h>

const int target = 100;

const char digits[] = "123456789";

void search(int pos, int current_sum, int last_operand, char expr[])
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
    search(pos+1, current_sum-last_operand+new_operand, new_operand, new_expr);

    // 2 = '+'
    sprintf(new_expr, "%s+%d", expr, next_digit);
    search(pos+1, current_sum+next_digit, next_digit, new_expr);

    // 3 = '-'
    sprintf(new_expr, "%s-%d", expr, next_digit);
    search(pos+1, current_sum-next_digit, -next_digit, new_expr);


}

int main()
{   
    search(1, 1, 1, "1");
}