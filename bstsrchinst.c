#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node* left;
    struct node* right;
};

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

struct node* search(struct node* root, int key)
{
    if(root == NULL || root->key == key)
        return root;
    if(root->key <key)
        return search(root->right,key);
    return search(root->left,key);
}
struct node* insert(struct node* node, int key)
{
    if(node == NULL) return newNode(key);

    if(key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right,key);
    return node;
}

int main()
{
    struct node *root = NULL;
    root = insert(root,50);
    insert(root, 30);
    insert(root,20);
    insert(root,60);
    inorder(root);
    int find = search(root,40);
    if(find)
        printf("true");
    else
        printf("false");
    return 0;
}
