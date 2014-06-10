#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left, *right;

};

struct node * newNode(int data)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = new_node->right= NULL;
    return (new_node);
}

int deepodd(struct node *root)
{
   if(root==NULL)
        return 0 ;
    else
    {
   int llevel= deepodd(root->left);
   int rlevel= deepodd(root->right);
   if(llevel > rlevel)
   {
       return(llevel+1);
       /*
       int level = llevel+1;
       printf(" llevel %d ", level);
       if(level%2==0)
            return(level-1);
        else
            return(level); */
   }
   else
   {
       return(rlevel+1);
       /*
       int level = rlevel+1;
       printf(" rlevel %d ", level);
       if(level%2==0)
            return(level-1);
        else
            return(level);*/

   }
    }


}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left= newNode(4);
    root->left->right=newNode(5);
    root->left->right->right=newNode(6);
    root->left->right->right->right = newNode(7);
    root->left->right->right->right->right = newNode(8);
    int level = deepodd(root);
    if(level%2 == 0)
        printf(" deep odd level is %d ",level-1);
    else
        printf(" deep odd level is %d ",level);
   return 0;

}
