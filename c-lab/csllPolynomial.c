// Represent, evaluate, and sum polynomials using circular singly linked list
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct polynomial
{
    int coeff, powx, powy, powz;
    struct polynomial * link;
};
typedef struct polynomial * POLY; 
POLY create()
{
    POLY node;
    node = (POLY)malloc(sizeof(struct polynomial));
    if(node == NULL)
    {
        printf("No memeory was allocated!\n");
        return;
    }
    return node;
}

POLY insert(POLY head, int cf, int px, int py, int pz)
{
        POLY node, temp;
        node = create();
        node->coeff = cf;
        node->powx = px;
        node->powy = py;
        node->powz = pz;
        temp = head->link;
        while(temp->link != head)
        {
            temp = temp->link;
        }
        temp->link = node;
        node->link = head;
        return head;
}

POLY input_polynomial(POLY head)
{
    int cf, px, py, pz, i = 1;
    printf("\nEnter 999 to end the polynomial\n");
    while(1)
    {
        printf("Enter the %d coefficient:", i);
        scanf("%d", &cf);
        if(cf == 999)
        {
            break;
        }
        printf("Enter power of x:");
        scanf("%d", &px);
        printf("Enter power of y:");
        scanf("%d", &py);
        printf("Enter power of z:");
        scanf("%d", &pz);
        head = insert(head, cf, px, py, pz);
        i++;
    }
    return head;
}

void display(POLY head)
{
    POLY temp;
    if(head->link == head)
    {
        printf("No polynomial exists!\n");
    }
    else
    {
        temp = head->link;
        while(temp != head)
        {
            printf("%dX^%dY^%dZ^%d + ", temp->coeff, temp->powx, temp->powy, temp->powz);
            temp = temp->link;
        }
        printf("999");
    }
}

int evaluate_polynomial(POLY head)
{
    int vx, vy, vz, sum = 0;
    POLY temp;
    if(head->link == head)
    {
        printf("No polynomial exists!\n");
        return;
    }
    printf("Enter the value of x, y, z:");
    scanf("%d%d%d", &vx, &vy, &vz);
    temp = head->link;
    while(temp != head)
    {
        sum = sum + (temp->coeff * pow(vx, temp->powx) * pow(vy, temp->powy) * pow(vz, temp->powz));
        temp = temp->link;
    }
    return (sum);
}

int main()
{
    POLY head;
    int res;
    head = create();
    head->link = head;
    printf("\nEnter the polynomial to be evaluated:");
    head = input_polynomial(head);
    printf("The given ployniomial is:");
    display(head);
    printf("\n");
    res = evaluate_polynomial(head);
    printf("\nThe result after evaluation is:%d", res);
    return 0;
}