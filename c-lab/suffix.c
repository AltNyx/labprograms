#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define MAX 30
int top = -1;
double s[MAX];
void push(double ele)
{
    if(top == MAX - 1)
        printf("Stack Overflow!\n");
    else
    {
        top++;
        s[top] = ele;
    }
}
double pop()
{
    double del;
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
double evaluate(char op, double op1, double op2)
{
    switch(op)
    {
        case '+': return (op1 + op2);
        case '-': return (op1 - op2);
        case '*': return (op1 * op2);
        case '/': return (op1 / op2);
        case '%': return (fmod(op1, op2));
        case '^': return (pow(op1, op2));
        default: printf("Invalid Operator!\n");
    }
}

int main()
{
    char su[50];
    int i;
    double res, val, op1, op2;
    printf("Enter suffix expression:");
    gets(su);
    for(i = 0; su[i] != '\0'; i++)
    {
        if(isdigit(su[i]))
            push(su[i] - '0');
        else if(isalpha(su[i]))
        {
            printf("Enter the value of %c:", su[i]);
            scanf("%lf", &val);
            push(val);
        }
        else
        {
            op2 = pop();
            op1 = pop();
            res = evaluate(su[i], op1, op2);
            push(res);
        }
    }
    res = pop();
    printf("The result is:%lf", res);
    return 0;
}
   
