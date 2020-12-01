//Take arr as input, return an array with product of all elements except the number at that index
#include<stdio.h>
#include<stdlib.h>
int * prod(int arr[], int n)
{
    int i;
    int * left = (int *)malloc(sizeof(int) * n);
    int * right = (int *)malloc(sizeof(int) * n);
    int * product = (int *)malloc(sizeof(int) * n);
    left[0] = 1;
    right[n - 1] = 1;
    for(i = 1; i < n; i++)
    {
        left[i] = arr[i - 1] * left[i - 1];
    }
    for(i = n - 2; i >= 0; i--)
    {
        right[i] = arr[i + 1] * right[i + 1];
    }
    for(i = 0; i < n; i++)
    {
        product[i] = left[i] * right[i];
    }
    return product;
}

int main()
{
    int n, i;
    printf("Enter number of elements:");
    scanf("%d", &n);
    int *arr, *res;
    arr = (int *)malloc(sizeof(int) * n);
    res = (int *)malloc(sizeof(int) * n);
    printf("Enter the elements:");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    res = prod(arr, n);
    printf("The result is:");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", res[i]);
    }
    return 0;
}