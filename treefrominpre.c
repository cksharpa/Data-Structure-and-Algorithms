#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node* left;
    struct node* right;
};
int search(char arr[], int strt, int end, char value);
struct node* newNode(char data);

struct node* buildTree(char in[], char pre[], int instrt, int inend)
{
    static int preindex = 0;
    if(instrt > inend)
        return NULL;
    struct node *tNode = newNode(pre[preindex++]);
    if(instrt == inend)
        return tNode;
    int inindex = search(in, instrt, inend, tNode->data);

    tNode->left = buildTree(in, pre, instrt, inindex-1);
    tNode->right = buildTree(in, pre, inindex+1, inend);

    return tNode;
}

int search(char arr[], int strt, int end, char value)
{
    int i;
    for(i=strt; i<= end; i++)
    {
        if(arr[i] == value)
            return i;
    }
}

struct node* newNode(char data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

void printinorder(struct node* root)
{
    if(root == NULL)
        return;
    printinorder(root->left);
    printf(" %c ", root->data);
    printinorder(root->right);
}

int main()
{
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in)/sizeof(in[0]);
  struct node *root = buildTree(in, pre, 0, len - 1);

  /* Let us test the built tree by printing Insorder traversal */
  printf("\n Inorder traversal of the constructed tree is \n");
  printinorder(root);
  getchar();
}
