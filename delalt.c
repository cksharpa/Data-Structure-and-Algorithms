#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* next;
};

void delalt(struct node* head)
{
 if(head == NULL)
	return;

 struct node* temp2 = head;
 struct node* del;
 while(temp2 != NULL && temp2->next != NULL)
  {
   del = temp2->next;
   temp2->next= temp2->next->next;
   temp2 = temp2->next;
   free(del);      
   
  }  
   
}

void push(struct node** head_ref, int new_data)
{
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = new_data;
  new_node->next = *head_ref;
  *head_ref = new_node;
}

void printlist(struct node* head)
{
 struct node* temp = head;
 while(temp != NULL)
 {
   printf(" %d ", temp->data);
   temp=temp->next;
 }
}

int main()
{
 struct node* head = NULL;
 push(&head,6);
 push(&head,5);
 push(&head,4);
 push(&head,3);
 push(&head,2);
 push(&head,1);
 printlist(head);
 delalt(head);
 printf("\nalternate nodes are\n"); 
 printlist(head);
 getchar();
 return 0 ;
}
 
