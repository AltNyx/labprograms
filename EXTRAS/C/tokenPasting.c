#include<stdio.h>
#define CONCAT(a, b) a##b
int main()
{
    int c, d, res;
    printf("The concatenated value is %d", CONCAT(10, 20));
    return 0;
}