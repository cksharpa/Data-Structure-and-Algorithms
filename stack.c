#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct stack
{
    int top;
    unsigned capacity;
    int* array;
};

struct stack* createstack(unsigned capacity)
{
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array =(int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isfull(struct stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isempty(struct stack* stack)
{
    return stack->top == -1;
}

void push(struct stack* stack, int item)
{
    if(isfull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);

}

int pop(struct stack* stack)
{
    if(isempty(stack))
        return ;
    return stack->array[stack->top--];
}

int peek(struct stack* stack)
{
    if(isempty(stack))
        return;
    return stack->array[stack->top];
}

int main()
{
    struct stack* stack = createstack(100);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("%d popped from stack\n",pop(stack));
    printf("top item is %d\n", peek(stack));

    return 0;
}
