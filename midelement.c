#include<stdio.h>
#include<stdlib.h>

struct dllnode
{
    struct dllnode *prev;
    int data;
    struct dllnode *next;
};

struct mystack
{
    struct dllnode *head;
    struct dllnode *mid;
    int count;
};

struct mystack *createmystack()
{
    struct mystack *ms = (struct mystack*)malloc(sizeof(struct mystack));
    ms->count = 0;
    return ms;
};

void push(struct mystack *ms, int new_data)
{
    struct dllnode* new_dllnode = (struct dllnode*)malloc(sizeof(struct dllnode));
    new_dllnode->data = new_data;
    new_dllnode->prev = NULL;
    new_dllnode->next = ms->head;
    ms->count += 1;
    if(ms->count == 1)
    {
        ms->mid = new_dllnode;
    }
    else
    {
        ms->head->prev = new_dllnode;
        if(ms->count & 1)
            ms->mid = ms->mid->prev;
    }
    ms->head = new_dllnode;
}

int pop(struct mystack *ms)
{
    if(ms->count == 0)
    {
        printf("stack is empty\n");
        return -1;
    }
    struct dllnode *head = ms->head;
    int item = head->data;
    ms->head = head->next;

    if(ms->head != NULL)
        ms->head->prev = NULL;
    ms->count -= 1;

    if(!(ms->count) & 1)
        ms->mid = ms->mid->next;
    free(head);
    return item;
}

int findmiddle(struct mystack *ms)
{
    if(ms->count == 0)
    {
        printf("stack is empty now\n");
        return -1;
    }
    return ms->mid->data;
}

int main()
{
    struct mystack *ms = createmystack();
    push(ms,11);
    push(ms, 22);
    push(ms, 33);
    push(ms, 44);
    push(ms, 55);
    push(ms, 66);

    printf("item popped is %d\n", pop(ms));
    printf("item popped is %d\n", pop(ms));
    printf("middle element is %d\n", findmiddle(ms));
    return 0;
}
