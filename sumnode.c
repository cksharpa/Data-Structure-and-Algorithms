#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *newNode(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data= data;
    temp->left=NULL;
    temp->right = NULL;
    return temp;
}

int sumnode(struct node *root)
{
    if(root==NULL)
        return;
    return (root->data + sumnode(root->left) + sumnode(root->right));
}
int main()

{
    struct node *root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    printf(" total sum of node is %d ", sumnode(root));

    return 0;
}
