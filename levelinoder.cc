#include<iostream>

using namespace std;

struct Node
{
    int key;
    struct Node* left, *right;
};

int search(int arr[], int strt, int end, int value)
{
    for(int i=strt; i<=end;i++)
        if(arr[i] == value)
            return i;
    return -1;
}

int *extractkeys(int in[], int level[], int m, int n)
{
    int *newlevel = new int[m], j=0;
    for(int i=0;i<n;i++)
        if(search(in,0,m-1, level[i]) != -1)
            newlevel[j] = level[i], j++;
    return newlevel;
}

struct Node* newNode(int key)
{
    struct Node *node = new Node;
    node->key = key;
    node->left = node->left = NULL;
    return(node);
}

struct Node* buildtree(int in[], int level[], int instrt,int inend, int n)
{
if(instrt > inend)
    return NULL;
Node *root = newNode(level[0]);

if(instrt == inend)
    return root;
int inindex = search(in, instrt, inend, root->key);

int *llevel = extractkeys(in, level, inindex,n);

int *rlevel = extractkeys(in+inindex +1, level, n-inindex-1,n);

root->left = buildtree(in, llevel, instrt, inindex-1,n);
root->right = buildtree(in, rlevel, inindex+1, inend,n);

delete [] llevel;
delete [] rlevel;
return root;

}

void printpreorder(struct Node *node)
{
    if(node == NULL)
        return;
    cout<<node->key<< " ";
    printpreorder(node->left);
    printpreorder(node->right);
}

int main()
{
    int in[] = {4,8,10,12,14,20,22};
    int level[] = {20,8,22,4,12,10,14};
    int n = sizeof(in)/sizeof(in[0]);
    Node *root = buildtree(in, level, 0, n-1,n);


    cout<<"inorder traversal of tree is \n";
    printpreorder(root);
    return 0;

}
