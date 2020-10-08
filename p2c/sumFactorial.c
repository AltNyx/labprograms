//The sum of factorial of digits of a number equal to the number itself 
//Eg: 145 = 1! + 4! + 5!
#include<stdio.h>
int fact(int n)
{
    if(n == 0 || n == 1)
        return 1;
    else 
        return (n * fact(n - 1));
}

void sumFac(int limit)
{
    int i, temp, rem, sum;
    for(i = 0; i < limit; i++)
    {
        sum = 0;
        temp = i;
        while(temp != 0)
        {
            rem = temp % 10;
            sum = sum + fact(rem);
            temp = temp / 10;
        }
        if(sum == i)
            printf("%d\n", i);
    }
}

int main()
{
    int limit = 2000000;
    sumFac(limit);
    return 0;
}