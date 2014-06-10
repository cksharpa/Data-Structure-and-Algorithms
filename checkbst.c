#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int isBSTutil(struct node* node, int min, int max);

int isbst(struct node* node)
{
    return(isBSTutil(node, INT_MIN, INT_MAX));
}

int isBSTutil(struct node* node, int min, int max)
{
    if(node==NULL)
        return 1;
    if(node->data < min || node->data > max)
        return 0;
    return isBSTutil(node->left, min, node->data-1) && isBSTutil(node->right, node->data+1, max);
}

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left=node->right = NULL;
    return node;
}

int main()
{
    struct node *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    if(isbst(root))
        printf("is BST");
    else
        printf("Not BST");
    getchar();
    return 0;
}
