//Difference between sums of odd level and even level nodes of a Binary Tree
#include<stdio.h>
#include<stdlib.h>

struct node {
   struct node *left, *right;
   int val;
};

// The structure is already declared, you can just start initializing nodes

struct node* addNode(int val)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return (temp);
}


int calcDiff(struct node *root){
    
    if(root == NULL)
        return 0;
    return root->val - calcDiff(root->left) - calcDiff(root->right);
    
}

/* Write any custom functions here */

int main()
   {
    struct node *root = addNode(1);
    root->left = addNode(2);
    root->right = addNode(3);
    root->left->left  = addNode(4);
    root->left->right = addNode(5);
    root->right->left = addNode(6);
    root->right->right = addNode(7);
    root->left->left->left = addNode(8);
    root->left->left->right = addNode(9);
    root->left->right->left = addNode(10);
    root->left->right->right = addNode(11);
    root->right->left->left = addNode(12);
    root->right->left->right = addNode(13);
    root->right->right->left = addNode(14);
    root->right->right->right = addNode(15);
    printf("%d is the required difference\n", calcDiff(root));
    return 0;

}
