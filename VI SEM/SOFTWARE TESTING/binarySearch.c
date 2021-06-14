#include <stdio.h>

int binarySearch(int arr[], int lo, int hi, int key)
{
    int mid;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    return -1;
}

int main()
{
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements in ascending order: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter key to be searched: ");
    scanf("%d", &key);

    int position = binarySearch(arr, 0, n - 1, key);

    if (position != -1)
        printf("Key found at position %d", position + 1);
    else
        printf("Key not found!");

    return 0;
}