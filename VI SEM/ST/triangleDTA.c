/*
V ABHISHEK KUMAR
1CR18IS163
*/

#include <stdio.h>
#include <stdbool.h>

bool isTriangle(int a, int b, int c)
{
    return (a < b + c) && (b < a + c) && (c < a + b);
}

int main()
{
    int a, b, c;
    printf("Enter the three sides of the triangle: ");
    scanf("%d%d%d", &a, &b, &c);

    if (!isTriangle(a, b, c))
    {
        printf("Not a triangle");
        return 0;
    }

    if (a == b && b == c)
        printf("It is an equilateral triangle");
    else if (a == b || b == c || a == c)
        printf("It is an isosceles triangle");
    else
        printf("It is a scalene triangle");

    return 0;
}