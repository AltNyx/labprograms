/*Even odd using ternary operator*/
#include<stdio.h>
void evenOdd(int num)
{
    num%2 == 0 ? printf("%d is even", num) : printf("%d is odd", num);
}

int main()
{
    int n;
    printf("Enter a number:");
    scanf("%d", &n);
    evenOdd(n);
    return 0;
}
