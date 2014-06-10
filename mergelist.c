#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node
{
 int data;
 struct node* next;
};

struct node* sortedmerge(struct node* a, struct node* b)
{
  struct node* result = NULL;
 
  /* Base cases */
  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);
 
  /* Pick either a or b, and recur */
  if (a->data <= b->data)
  {
     result = a;
     result->next = sortedmerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = sortedmerge(a, b->next);
  }
  return(result);
}

void push(struct node** head_ref, int new_data)
{
  
  struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
 
  new_node->data  = new_data;
  new_node->next = (*head_ref);    
  (*head_ref)    = new_node;
}
 
void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
} 

int main()
{
  struct node* res = NULL;
  struct node* a = NULL;
  struct node* b = NULL;

  push(&a, 15);
  push(&a, 10);
  push(&a, 5);
   
  push(&b, 20);
  push(&b, 3);
  push(&b, 2);  

  res = sortedmerge(a, b);
 
  printf("\n Merged Linked List is: \n");
  printList(res);
  getchar();
  return 0;
}
