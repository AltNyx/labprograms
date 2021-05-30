/*
V ABHISHEK KUMAR
1CR18IS163
*/

#include <stdio.h>
#include <stdbool.h>

// Checks if the 3 sides from a triangle or not
bool isTriangle(int a, int b, int c)
{
    return (a < b + c) && (b < a + c) && (c < a + b);
}

// Returns the type of triangle
const char *triangleType(int a, int b, int c)
{
    if (!isTriangle(a, b, c))
        return "Not a Triangle";

    if (a == b && b == c)
        return "Equilateral Triangle";
    else if (a == b || b == c || a == c)
        return "Isosceles Triangle";
    else
        return "Scalene Triangle";
}

int main()
{
    int a, b, c;
    printf("Enter the three sides of the triangle: ");
    scanf("%d%d%d", &a, &b, &c);

    printf("%s\n", triangleType(a, b, c));
    return 0;
}