#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void push(struct node **head_ref, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *temp = *head_ref;
    new_node->data = data;
    new_node->next = *head_ref;

    if(*head_ref != NULL)
    {
        while(temp->next != *head_ref)
            temp = temp->next;
        temp->next = new_node;
    }
    else
        new_node->next = new_node;
    *head_ref = new_node;
}

void printList(struct node *head)
{
    struct node *temp = head;
    if(head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while(temp != head);

    }
}

int main()
{
    int list_size, i;
    struct node *head =  NULL;
    push(&head, 12);
    push(&head, 34);
    push(&head,2);
    push(&head, 11);
    printf("contents of circular list\n");
    printList(head);
    return 0;
}
