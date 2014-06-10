#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

int identical(struct node* heada, struct node* headb)
{
    struct node* nodea = heada;
    struct node* nodeb = headb;
    
    while(nodea ==  NULL && nodeb == NULL)
    {
        return 1;
    }
    while(nodea == NULL && nodeb != NULL)
    {
        return 0;
    }
    while(nodea != NULL && nodeb == NULL)
    {
        return 0;
    }
    while(nodea != NULL && nodeb != NULL )
    {
        if(nodea->data != nodeb->data)
        {
            return 0;
        }
        nodea = nodea->next;
        nodeb = nodeb->next;
        
    }
}

void push(struct node** head_ref, int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next=*head_ref;
    *head_ref = new_node;
    
}

void printlist(struct node* head)
{
    struct node* temp = head;
    while(temp != NULL)
    {
        printf(" %d ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    struct node* head = NULL;
    struct node* heada = NULL;
    struct node* headb = NULL;
    push(&heada,3);
    push(&heada,2);
    push(&heada,1);
   
    push(&headb,3);
    push(&headb,4);
    push(&headb,1);
    
    printf("List A\n");
    printlist(heada);
    printf("\nList B\n");
    printlist(headb);
   if(identical(heada,headb) == 1)
   {
       printf("\n Identical \n");
   }
   else
   {
       printf("\n Not Identical \n");
   }
   getchar();
   return 0;
    
}
