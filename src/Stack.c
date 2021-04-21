#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int isFull(struct Stack* stack)
{
    return stack->currentLocation == stack->size - 1;
}

int isEmpty(struct Stack* stack)
{
    return stack->currentLocation == -1;
}

struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->currentLocation = -1;
    stack->array = (unsigned int *)malloc(sizeof(unsigned int) * size);

    return stack;        
}

unsigned int pop(struct Stack* stack)
{
    if (isEmpty(stack)){
        printf("Warning: try to pop empty stack");
        return -1;
    }
        
    return stack->array[stack->currentLocation--];
}

void push(struct Stack* stack, const unsigned int item)
{
    if (isFull(stack))  
        return;
    stack->array[++stack->currentLocation] = item;
}