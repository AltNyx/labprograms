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

POLY sum_polynomial(POLY head1, POLY head2, POLY head3)
{
    POLY p1, p2;
    int c, c1, c2, x1, y1, z1, x2, y2, z2, flag;
    p1 = head1->link;
    while(p1 != head1)
    {
        c1 = p1->coeff;
        x1 = p1->powx;
        y1 = p1->powy;
        z1 = p1->powz;

        p2 = head2->link;
        flag = 0;
        while(p2 != head2)
        {
            c2 = p2->coeff;
            x2 = p2->powx;
            y2 = p2->powy;
            z2 = p2->powz;

            if((x1 == x2) && (y1 == y2) && (z1 == z2))
            {
                head3 = insert(head3, c1 + c2, x1, y1, z1);
                p2->coeff = 0;
                flag = 1;
                break;
            }
            else
                p2 = p2->link;
        }
        if(flag == 0)
            head3 = insert(head3, c1, x1, y1, z1);
        p1 = p1->link;
    }
    p2 = head2->link;
    while(p2 != head2)
    {
        if(p2->coeff != 0)
            head3 = insert(head3, p2->coeff, p2->powx, p2->powy, p2->powz);
        p2 = p2->link;
    }
    return head3;
}

int main()
{
    POLY head1, head2, head3;
    head1 = create();
    head1->link = head1;
    head2 = create();
    head2->link = head2;
    head3 = create();
    head3->link = head3;
    printf("\nEnter the first polynomial:");
    head1 = input_polynomial(head1);
    display(head1);
    printf("\nEnter the second polynomial:");
    head2 = input_polynomial(head2);
    display(head2);
    head3 = sum_polynomial(head1, head2, head3);
    printf("\nThe sum of two polynomials is:");
    display(head3);
    return 0; 
}