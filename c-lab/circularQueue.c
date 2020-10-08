#include<stdio.h>
#define MAX 5
char cq[MAX];
int f = -1;
int r = -1;
void insert()
{
    char ele;
    printf("Enter an element:");
    scanf("\n%c", &ele);
    if((f == 0 && r == MAX-1) || (f == r+1))
        printf("Queue Overflow\n");
    else if(f == -1)
    {
        f = 0;
        r = 0;
        cq[r] = ele;
    }
    else
    {
        r = (r+1) % MAX;
        cq[r] = ele;
    }
}
void del()
{
    if(f == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("The deleted element is:%c", cq[f]);
    if(f == r)
    {
        f = -1;
        r = -1;
    }
    else
        f = (f+1) % MAX;
}
void display()
{
    int i;
    if(f == -1)
        printf("Queue is empty!\n");
    else
    {
        printf("The contents of queue are:");
        for(i = f; i != r; i = (i+1) % MAX)
        {
            printf("\t%c", cq[i]);
        }
        printf("\t%c", cq[i]);
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n----------------------------");
        printf("\nQueue Operations!\n\n1:Insert\n2:Delete\n3:Display\n4:Exit\n");
        printf("\n----------------------------");
        printf("\nEnter choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: insert();
                    break;
            case 2: del();
                    break;
            case 3: display();
                    break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}