#include<stdio.h>
#include<ctype.h>
#define MAX 30
int top = -1;
char s[MAX];
void push(char ele)
{
    if(top == MAX - 1)
        printf("Stack Overflow!\n");
    else
    {
        top++;
        s[top] = ele;
    }
}
char pop()
{
    char del;
    if(top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        del = s[top];
        top--;
        return del;
    }
}
int priority(char c)
{
    if(c == '(')
        return 1;
    else if(c == '+' || c == '-')
        return 2;
    else if(c == '*' || c == '/' || c == '%')
        return 3;
    else if(c == '^')
        return 4;
    else
        return 0;
}
int main()
{
    char in[50], po[50];
    int i, j = 0;
    printf("Enter infix expression:");
    gets(in);
    for(i = 0; in[i] != '\0'; i++)
    {
        if(isalnum(in[i]))
            po[j++] = in[i];
        else if(in[i] == '(')
            push(in[i]);
        else if(in[i] == ')')
        {
            while(s[top] != '(')
                po[j++] = pop();
            top--;
        }
        else
        {
            while(priority(s[top]) >= priority(in[i]))
                po[j++] = pop();
            push(in[i]);
        }
    }
    while(top != -1)
        po[j++] = pop();
    po[j++] = '\0';
    printf("The postfix expression is:%s", po);
    return 0;
}   
