//re-sort the sorted rotated list

#include<stdio.h>
#include<stdlib.h>

struct node{

   struct node * next;
   int val;   
};
//The above structure has already been declared, please do NOT redeclare the structure

struct node *addNode(int newval)
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->val  = newval;
    temp->next =  NULL;
 
    return temp;
}

                                               
 
/*

void max(struct node **head)
{
  struct node *temp;
  int max=0;
  temp=*head;
  while((temp->next)!=NULL)
    {
      max=temp->data;
      temp=temp->next;
      if((temp->val)>max)
        {
         max=temp->val;
        }

    }
 printf("The pivot is %d",max);  
 printf("\n");

}
*/
void sortlist(struct node **head_ref, struct node* new_node)
{
    struct node* current;
    if (*head_ref == NULL || (*head_ref)->val >= new_node->val)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        current = *head_ref;
        while (current->next!=NULL &&
               current->next->val < new_node->val)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void print(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->val);
   node = node->next;
  }
} 
int main()
{
    
    struct node* head = NULL;
    struct node *new_node = addNode(1);
    sortlist(&head, new_node);
    new_node = addNode(2);
    sortlist(&head, new_node);
    new_node = addNode(3);
    sortlist(&head, new_node);
    new_node = addNode(4);
    sortlist(&head, new_node);
    new_node = addNode(5);
    sortlist(&head, new_node);
    new_node = addNode(1);
    sortlist(&head, new_node);
    new_node = addNode(2);
    sortlist(&head, new_node);
 
    printf("sorted Linked List  \n");
    print(head);
 
    
    
    return 0;
}
