#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int newdata)
{
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->data = newdata;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void storeinorder(struct node *root, int arr[], int *index)
{
    if(root == NULL)
        return;
    storeinorder(root->left,arr,index);
    arr[*index] = root->data;
    (*index)++;
    storeinorder(root->right, arr, index);
}

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b );
}

void arraytobst(int arr[], struct node *root, int *index)
{
    if(root == NULL)
        return;
    arraytobst(arr,root->left, index);
    root->data = arr[*index];
    (*index)++;
    arraytobst(arr,root->right, index);
}

int countnode(struct node *root)
{

    if(root == NULL)
        return 0;
    return countnode(root->left) +countnode(root->right) + 1;
}
void binarytreetobst(struct node *root)
{
    if(root == NULL)
        return;
    int n = countnode(root);

    int *arr = new int[n];
    int i = 0;
    storeinorder(root,arr,&i);

    qsort( arr, n, sizeof(arr[0]), compare);

    i=0;
    arraytobst(arr,root,&i);

    delete [] arr;
}

void printinorder(struct node* node)
{
    if (node == NULL)
        return;
    printinorder(node->left);
    printf("%d ", node->data);
    printinorder(node->right);
}

int main()
{
    struct node *root = NULL;
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);

    binarytreetobst(root);
    printf("following in inorder traversal\n");

    printinorder(root);
    return 0;
}
