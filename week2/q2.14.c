#include <stdio.h>

int main()
{   
    int row;
    int col;

    printf("Input the number of rows: ");
    scanf("%d", &row);

    printf("Input number of columns: ");
    scanf("%d", &col);

    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++)
        {
            printf("%c",'*');
        }
        printf("\n");
    }

    return 0;
}