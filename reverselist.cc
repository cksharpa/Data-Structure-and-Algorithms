#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void printReverse(struct node* head)
{
    if(head == NULL)
    return;

    //print the list after head node
    printReverse(head->next);

    //print head at last
    printf("%d  ",head->data);

}

//push a node to linked list

void push(struct node** head_ref, char new_data)
{

    //allocate node
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    // put in the data
    new_node->data = new_data;

    //link the old list of the new node
    new_node->next = (*head_ref);

    //move the  head
    (*head_ref) = new_node;
}

int main()
{

    struct node* head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    printReverse(head);
    getchar();

}
