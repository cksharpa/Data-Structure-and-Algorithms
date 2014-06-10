#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d ", root->data);

    }
}

int search(int in[], int n, int item)
{
  int i;
  for(i=0;i<n;i++)
  {
      if(in[i]==item)
        return i;
  }
}

struct node* buildtree(int pre[], int in[], int min, int max)
{
    if(min>max)
        return NULL;

    static int pivot=0;
    struct node *tnode = newNode(pre[pivot++]);
    int index = search(in, max,tnode->data);
    tnode->left = buildtree(pre, in, min, index-1);
    tnode->right = buildtree(pre, in, index+1, max);

    return tnode;

}

int main()
{
    int pre[] = {4,2,1,3,5};
    int in[] = {1,2,3,4,5};
    int len = sizeof(pre)/sizeof(pre[0]);

    struct node *root = buildtree(pre,in,0,len-1);
    postorder(root);
    return 0;
}
