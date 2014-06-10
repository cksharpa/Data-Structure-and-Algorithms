#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int getwidth(struct node* root, int level);
int height(struct node* node);
struct node* newnode(int data);

int getmaxwidth(struct node* root)
{
    int maxwidth = 0;
    int width;
    int h = height(root);
    int i;

    for(i=1; i<=h; i++)
    {
        width = getwidth(root,i);
        if(width > maxwidth)
            maxwidth = width;
    }
    return maxwidth;
}

int getwidth(struct node* root, int level)
{
    if(root == NULL)
        return 0;
    if(level == 1)
        return 1;
    else if(level > 1)
        return getwidth(root->left, level-1) + getwidth(root->right, level-1);
}

int height(struct node* node)
{
    if(node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);

        return (lheight > rheight)? (lheight+1) : (rheight+1);
    }
}

struct node* newnode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int main()
{
  struct node *root = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);
  root->right->right = newnode(8);
  root->right->right->left  = newnode(6);
  root->right->right->right  = newnode(7);
  printf("Maximum width is %d \n", getmaxwidth(root));
  getchar();
  return 0;
}
