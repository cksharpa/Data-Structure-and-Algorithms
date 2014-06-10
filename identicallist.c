#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *next;
};

void push(struct node **head_ref, int new_data)
{
    struct node* new_node =  (struct node*)malloc(sizeof(struct node));
    new_node->data =  new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

bool identical(struct node *head1, struct node *head2)
{
    while(1)
    {
    if(head1 == NULL && head2 == NULL)
        return true;
    else if(head1 != NULL && head2 == NULL)
        return false;
    else if(head1 == NULL && head2 != NULL)
        return false;
    else if(head1->data != head2->data)
    {
        return false;
    }
    head1 = head1->next;
    head2 = head2->next;
    }

}

void printlist(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    push(&head1, 1);
    push(&head1,2);
    push(&head1,3);
    push(&head1,4);
    printlist(head1);
    push(&head2, 1);
    push(&head2,2);
    push(&head2,3);
    push(&head2,4);
    printlist(head2);
    if(identical(head1, head2))
        printf("list are identical");
    else
        printf("they are not" );


    return 0;
    getchar();

}
