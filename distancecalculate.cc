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

void printkdistance(struct Node *node, int key1, int key2)
{


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
    printkdistance(root,4,5);

    return 0;
}
