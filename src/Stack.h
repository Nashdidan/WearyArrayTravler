#ifndef STACK_H
#define STACK_H

struct Stack {
    unsigned int currentLocation;
    int size;
    unsigned int* array;
};

struct Stack* createStack(int size);
void push(struct Stack* stack, const unsigned int item);
unsigned int pop(struct Stack* stack);
int isEmpty(struct Stack* stack);
int isFull(struct Stack* stack);

#endif