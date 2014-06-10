#include<iostream>
#define MAX_HEIGHT 1000

using namespace std;

struct Node
{
    int key;
    struct Node *left, *right;
};

struct Node *newNode(int key)
{
    Node *node = new Node;
    node->key=key;
    node->left = node->right = NULL;
    return(node);
}

void printkdistanceutil(struct Node *node, int path[], bool visited[], int pathlen, int k)
{
    if(node==NULL)
        return;
    path[pathlen]=node->key;
    visited[pathlen] = false;
    pathlen++;

    if(node->left == NULL && node->right == NULL && pathlen-k-1 >= 0 && visited[pathlen-k-1] == false)
    {
        cout<<" "<<path[pathlen-k-1] << " ";
        visited[pathlen-k-1] = true;
        return;
    }

    printkdistanceutil(node->left,path,visited,pathlen,k);
    printkdistanceutil(node->right,path,visited,pathlen,k);
}

void printkdistance(struct Node * node, int k)
{
    int path[MAX_HEIGHT];
    bool visited[MAX_HEIGHT] = {false};
    printkdistanceutil(node, path, visited,0,k);
}

void preorder(struct Node *root)
{
    if(root==NULL)
        return;
    cout<<" "<<root->key;
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    preorder(root);
    cout<<"\n";
    printkdistance(root,2);

    return 0;
}
