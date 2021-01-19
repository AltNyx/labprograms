#include<stdio.h>
#include<stdlib.h>
struct student
{
    char usn[20];
    char name[20];
    char branch[20];
    int sem;
    long int phone;
    struct student * link;
};
typedef struct student * STUDENT;
STUDENT first = NULL;
STUDENT create()
{
    STUDENT getnode;
    getnode = (STUDENT)malloc(sizeof(struct student));
    printf("\nEnter the student detils:\n");
    printf("Enter usn:");
    scanf("%s", getnode->usn);
    printf("Enter name:");
    scanf("%s", getnode->name);
    printf("Enter branch:");
    scanf("%s", getnode->branch);
    printf("Enter sem:");
    scanf("%d", &getnode->sem);
    printf("Enter phone:");
    scanf("%ld", &getnode->phone);
    getnode->link = NULL;
    return getnode;
}

void insert_front()
{
    STUDENT gnode;
    gnode = create();
    if(first == NULL)
        first = gnode;
    else
    {
        gnode->link = first;
        first = gnode;
    }
}

void delete_front()
{
    STUDENT temp;
    if(first == NULL)
        printf("\nList is empyty!");
    else if(first->link == NULL)
    {
        temp = first;
        first = NULL;
        printf("\nThe records with usn %s has been deleted.", temp->usn);
        free(temp);
    }
    else
    {
        temp = first;
        first = first->link;
        printf("\nThe records with usn %s has been deleted.", temp->usn);
        free(temp);
    }
}

void insert_end()
{
    STUDENT gnode, temp;
    gnode = create();
    if(first == NULL)
        first = gnode;
    else
    {
        temp = first;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = gnode;
    }
}

void delete_end()
{
    STUDENT temp, prev;
    if(first == NULL)
        printf("\nList is empty!");
    else if(first->link == NULL)
    {
        temp = first;
        first = NULL;
        printf("\nThe records with usn %s has been deleted.", temp->usn);
        free(temp);
    }
    else
    {
        temp = first;
        while(temp->link != NULL)
        {
            prev = temp;
            temp = temp->link;
        }
        prev->link = NULL;
        printf("\nThe records with usn %s has been deleted.", temp->usn);
        free(temp);
    }
}

void create_list()
{
    int n, i;
    printf("\nEnter number of students:");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        insert_front();
}

void display()
{
    STUDENT temp;
    int count = 0;
    if(first == NULL)
        printf("\nList is empty");
    else
    {
        temp = first;
        printf("\nThe student details are:\n");
        while(temp != NULL)
        {
            printf("\nUsn:%s", temp->usn);
            printf("\nName:%s", temp->name);
            printf("\nBranch:%s", temp->branch);
            printf("\nSem:%d", temp->sem);
            printf("\nPhone:%ld\n", temp->phone);
            count++;
            temp = temp->link;
        }
        printf("\nThe number of student records are:%d", count);
    }
}

int stack_demo()
{
    int choice;
    while(1)
    {
        printf("\nStack Operations\n\n1:Push\n2:Pop\n3:Display\n4:Exit\n\nEnter choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: insert_end();
                    break;
            case 2: delete_end();
                    break;
            case 3: display();
                    break;
            case 4: return 0;
            default: printf("\nInvalid choice!");
        }
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("\nStudent Record\n\n1:Create list\n2:Insert front\n3:Delete front\n4:Insert end\n5:Delete end\n6:Display\n7:Stack demo\n8:Exit\n\nEnter choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: create_list();
                    break;
            case 2: insert_front();
                    break;
            case 3: delete_front();
                    break;
            case 4: insert_end();
                    break;
            case 5: delete_end();
                    break; 
            case 6: display();
                    break;
            case 7: stack_demo();
                    break;
            case 8: return 0;
            default: printf("\nInvalid choice!");
        }
    }
}