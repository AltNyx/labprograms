#include<stdio.h>
void toh(int n, char src, char dest, char temp)
{
    if(n == 1)
    {
        printf("Move disk %d from %c to %c\n", n, src, dest);
        return;
    }
    toh(n-1, src, temp, dest);
    printf("Move disk %d from %c to %c\n", n, src, dest);
    toh(n-1, temp, dest, src);
}

int main()
{
    int n;
    printf("Enter number of disks:");
    scanf("%d", &n);
    toh(n, 'A', 'B', 'C');
}