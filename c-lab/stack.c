#include<stdio.h>
#define MAX 30
int top = -1, s[MAX];
void push(int ele)
{
    if(top == MAX - 1)
        printf("Stack Overflow!\n");
    else
    {
        top++;
        s[top] = ele;
    }
}
int pop()
{
    int del;
    if(top == -1)
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    else
    {
        del = s[top];
        top--;
        return del;
    }
}
void palindrome()
{
    int p[MAX], n , i, flag = 0;
    printf("Enter the number of digits:");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
        push(p[i]);
    }
    for(i = 0; i < n/2; i++)
    {
        if(p[i] != pop())
        {
            flag = 1;
            break; 
        }
    }
    if(flag == 0)
        printf("PAlindrome!\n");
    else
        printf("Not palindrome!\n"); 
}
void display()
{
    int i;
    if(top == -1)
        printf("Stack is empty!\n");
    else
    {
        for(i = top; i >= 0; i--)
            printf("%d\t", s[i]);
    }
}
int main()
{
    int choice, ele, del;
    while(1)
    {
        printf("\nStack operations!\n\n1:Push\n2:Pop\n3:Palindrome\n4:Display\n5:Exit\n\nEnter choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter an element:");
                    scanf("%d", &ele);
                    push(ele);
                    break;
            case 2: del = pop();
                    if(del == -1)
                        printf("Nothing to delete!\n");
                    else
                        printf("The element %d was deleted", del);
                    break;
            case 3: palindrome();
                    break;
            case 4: display();
                    break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}