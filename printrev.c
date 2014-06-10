#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* printrev(struct node* head, int k)
{
    struct node* current = head;
    int count = 0;
    struct node* prev = NULL;
   struct node* next;
    while(current != NULL && count < k)
    {
       next = current->next;
       current->next = prev;
       prev = current;
       current = next;
       count++;
    }
    if(next != NULL)
    {
        head->next = printrev(next,k);
    }
    return prev;
}

void push(struct node** head_ref, int data)
{

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref =  new_node;

}

void printlist(struct node* head)
{
    struct node* temp = head;
    while(temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct node* head = NULL;
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    printlist(head);
    head = printrev(head,3);
    printf("\nAfter Reversing\n");
    printlist(head);
    getchar();
    return 0;
}


