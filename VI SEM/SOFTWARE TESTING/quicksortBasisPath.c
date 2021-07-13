#include <stdio.h>

void swap(int *num1, int *num2);
int partition(int arr[], int lo, int hi);
void quicksort(int arr[], int lo, int hi);

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Number of elements should be greater than 0");
        return 0;
    }

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quicksort(arr, 0, n - 1);
    printf("The sorted elements are: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partition(int arr[], int lo, int hi)
{
    int pivot = arr[hi];
    int i = (lo - 1);

    for (int j = lo; j <= hi - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    i++;
    swap(&arr[i], &arr[hi]);
    return i;
}

void quicksort(int arr[], int lo, int hi)
{
    if (lo < hi)
    {
        int p = partition(arr, lo, hi);
        quicksort(arr, lo, p - 1);
        quicksort(arr, p + 1, hi);
    }
}