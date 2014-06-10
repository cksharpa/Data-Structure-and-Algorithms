#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* right;
    struct node* left;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left= NULL;
    node->right = NULL;
    return (node);
}

void inorder(struct node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf(" %d ",root->data);
    inorder(root->right);
}

int depth(struct node* root)
{
    if(root ==  NULL)
        return;
    int ldepth = depth(root->left);
    int rdepth = depth(root->right);

    if(ldepth > rdepth)
        return (ldepth+1);
    else
        return (rdepth+1);
}

int totalnode(struct node* root)
{
    if(root ==  NULL)
        return;
    int ldepth = totalnode(root->left);
    int rdepth = totalnode(root->right);

    return (ldepth + rdepth +1);
}


int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
     inorder(root);
    //printf("%d", root->data);
    printf("\n depth is %d", depth(root));
    printf("\n total node is %d", totalnode(root));
    getchar();
    return 0;
}
