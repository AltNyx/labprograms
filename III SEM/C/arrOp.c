// Array Operations
#include<stdio.h>
int n, a[20];
void create()
{
    int i;
    printf("\nEnter number of elements:");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
}
void display()
{
    int i;
    if(n == 0)
        printf("\nNo elements to display!\n");
    else 
    {
        for(i = 0; i < n; i++)
            printf("%d\t", a[i]);
    }
}
void insert()
{
    int ele, pos, i;
    printf("\nEnter the element to be inserted:");
    scanf("%d", &ele);
    printf("\nEnter the position:");
    scanf("%d", &pos);
    if(pos < 1 || pos > n)
        printf("Invalid Position!\n");
    else
    {
        for(i = n-1; i >= pos-1; i--)
            a[i+1] = a[i];
        a[pos-1] = ele;
        n++;
    }
}
void delete()
{
    int pos, i;
    printf("\nEnter the position:");
    scanf("%d", &pos);
    if(pos < 1 || pos > n)
        printf("Invalid Position!\n");
    else
    {
        printf("The element %d is deleted\n", a[pos-1]);
        for(i = pos-1; i < n-1; i++)
            a[i] = a[i+1];
        n--;
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n\nArray Operations!\n\n1:Create\n2:Insert\n3:Remove\n4:Display\n5:Exit\n\nEnter choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: create();
                    break;
            case 2: insert();
                    break;
            case 3: delete();
                    break;
            case 4: display();
                    break;
            case 5: return 0;
            default: printf("\nInvalid Choice!");
        }
    }
    return 0;
}