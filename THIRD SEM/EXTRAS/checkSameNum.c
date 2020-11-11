#include<stdio.h>
int checkforsame(int x, int y)
{
    if(x ^ y)
        printf("The numbers are not same!\n");
    else
        printf("The numbers are same!\n");
}

int main()
{
    int num1, num2;
    printf("Enter two numbers:");
    scanf("%d%d", &num1, &num2);
    checkforsame(num1, num2);
    return 0;
}