//To find factorial greater than 100
#include<stdio.h>
int multiply(int num, int arr[], int size)
{
    int i, product, carry = 0;
    for(i = 0; i < size; i++)
    {
        product = arr[i] * num + carry;
        arr[i] = product % 10;
        carry = product / 10;
    }
    while(carry != 0)
    {
        arr[size] = carry % 10;
        carry = carry / 10;
        size++;
    }
    return size;
}

int main()
{
    int arr[500], num, i, size = 1;
    arr[0] = 1;
    printf("Enter a large number:");
    scanf("%d", &num);
    for(i = 2; i <= num; i++)
    {
        size = multiply(i, arr, size);
    }
    printf("The result is:");
    for(i = size - 1; i >= 0; i--)
    {
        printf("%d", arr[i]);
    }
    return 0;
}



