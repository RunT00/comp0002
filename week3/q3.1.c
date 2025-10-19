#include <stdio.h>
#include <math.h>

int main()
{   
    double a, b, c;
    printf("Input length of sides of triangle: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double s = 0.5*(a + b + c);
    double area = sqrt(s*(s-a)*(s-b)*(s-c));
    printf("The area of triangle is %lf\n", area);
    printf("The length of perimeter of triangle is %lf\n", 2.0*s);

    return 0;
}