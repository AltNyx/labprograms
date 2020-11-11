#include<stdio.h>
int minof(int num1, int num2)
{
    return num1 * (num1 < num2) + num2 * (num2 < num1);
}
int max0f(int num1, int num2)
{
    return num1 * (num1 > num2) + num2 * (num2 > num1);
}

int main()
{
    int num1, num2, min , max;
    printf("Enter two numbers:");
    scanf("%d%d", &num1, &num2);
    min = minof(num1, num2);
    max = max0f(num1, num2);
    printf("The num %d is smaller\n", min);
    printf("The num %d is larger", max);
    return 0;
}