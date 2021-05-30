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
    bool check1, check2, check3;

    do
    {
        printf("Enter sides of triangle (a, b, c): ");
        scanf("%d%d%d", &a, &b, &c);
        printf("a=%d, b=%d, c=%d\n", a, b, c);

        check1 = a >= 1 && a <= 10;
        check2 = b >= 1 && b <= 10;
        check3 = c >= 1 && c <= 10;

        if (!check1)
            printf("The value of a=%d not in range [1, 10]\n", a);
        if (!check2)
            printf("The value of b=%d not in range [1, 10]\n", b);
        if (!check3)
            printf("The value of c=%d not in range [1, 10]\n", c);

    } while (!(check1 && check2 && check3));

    printf("%s\n", triangleType(a, b, c));
    return 0;
}