#include<stdio.h>
int add(int x, int y)
{
    while( y != 0)
    {
        int carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }
    return x;
}

int sub(int x, int y)
{
    while( y != 0)
    {
        int borrow = ~x & y;
        x = x ^ y;
        y = borrow << 1;
    }
    return x;
}

int main()
{
    int x, y;
    printf("Enter x and y:");
    scanf("%d%d", &x, &y);
    printf("The sum is %d\n", add(x, y));
    printf("The difference is %d\n", sub(x, y));
    return 0;
}