#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<stack>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);

}

void iterpreorder(node *root)
{
    if(root == NULL)
        return;
    stack<node *> nodestack;
    nodestack.push(root);

    while(nodestack.empty() == false)
    {
        if(node->right)
            nodestack.push(node->right);
        if(node->left)
            nodestack.push(node->left);
        struct node *node = nodestack.top();
        printf("%d ", node->data);
        nodestack.pop();
    }
}

int main()
{

    struct node *root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);
    iterpreorder(root);
    return 0;
}
