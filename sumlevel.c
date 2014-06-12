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

void printorder(struct node* node)
{
    if(node ==NULL)
        return;
    printorder(node->left);
    printf("%d ",node->data);
    printorder(node->right);
}

int sumlevel(struct node *root)
{
    if(root==NULL)
        return;
    int val = root->data;
    root->data = sumlevel(root->left) + sumlevel(root->right);
    return root->data + val;
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
    sumlevel(root);
    printf(" inoder traversal is \n");
    printorder(root);

    return 0;
}
