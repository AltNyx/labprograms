//Binary Search Tree
#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int data;
    struct tree *left, *right;
};
typedef struct tree * TREE;

TREE create()
{
    TREE node;
    node = (TREE)malloc(sizeof(struct tree));
    if(node == NULL)
    {
        printf("No memory was allocated!\n");
        return;
    }
    return node;
}

TREE create_bst(TREE root)
{
    TREE node, prev, cur;
    node = create();
    printf("Enter an integer:");
    scanf("%d", &node->data);
    node->left = NULL;
    node->right = NULL;
    if(root == NULL)
    {
        root = node;
        return root;
    }
    prev =  NULL;
    cur = root;
    while(cur != NULL)
    {
        prev = cur;
        if(node->data < cur->data)
            cur = cur->left;
        else
            cur = cur->right;    
    }
    if(node->data < prev->data)
        prev->left = node;
    else
        prev->right = node;
    return root;
}

void inorder_traversal(TREE root)
{
    if(root == NULL)
        return;
    inorder_traversal(root->left);
    printf("%3d", root->data);
    inorder_traversal(root->right);
}

void preorder_traversal(TREE root)
{
    if(root == NULL)
        return;
    printf("%3d", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(TREE root)
{
    if(root == NULL)
        return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%3d", root->data);
}

void search_bst(TREE root)
{
    TREE temp;
    int key, flag = 0;
    printf("\nEnter key:");
    scanf("%d", &key);
    temp = root;
    while(temp != NULL)
    {
        if(key == temp->data)
        {
            flag = 1;
            break;
        }
        else if(key < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    
    if(flag == 1)
        printf("\nKey found!");
    else
        printf("\nKey not found!");
}

int main()
{
    TREE root;
    root = NULL;
    int choice, n, i;
    for(;;)
    {
        printf("\n--------------------------------");
        printf("\nBINARY SEARCH TREE OPERATIONS\n\n1:Create N integers\n2:Inorder traversal\n3:Preorder traversal\n4:Postorder traversal\n5:Search for a KEY\n6:Exit");
        printf("\n--------------------------------");
        printf("\nEnter choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("\nEnter number of integers:");
                    scanf("%d", &n);
                    for(i = 0; i < n; i++)
                    {
                        root = create_bst(root);
                    }
                    break;
            case 2: printf("\nThe inorder traversal of the given tree is:");
                    inorder_traversal(root);
                    break;

            case 3: printf("\nThe preorder traversal of the given tree is:");
                    preorder_traversal(root);
                    break;

            case 4: printf("\nThe postorder traversal of the given tree is:");
                    postorder_traversal(root);
                    break;
            
            case 5: search_bst(root);
                    break;

            case 6: return 0;

            default: printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}