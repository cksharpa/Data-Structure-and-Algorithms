#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

int isfull(struct Stack* stack)
{
    return stack->top == stack->capacity-1;

}

int isempty(struct Stack* stack)
{
    return stack->top == -1;
}

void push(struct Stack* stack, int item)
{
    if(isfull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed \n", item);
}

int pop(struct Stack* stack)
{
    if(isempty(stack))
        return INT_MIN;
     return stack->array[stack->top--];
}

int main()
{
    struct Stack* stack = createStack(100);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("%d popped from stack\n", pop(stack));

    return 0;
}
