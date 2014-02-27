#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Error Handling
#define SUCCESS          0
#define NULL_STACK      -1
#define UNDEF_DATA      -2 
#define INVALID_SIZE    -3
#define STACK_EMPTY     -4
#define OUT_OF_MEM      -5

// Data Structure
typedef struct stack_ele stack_ele;
typedef struct stack stack;

struct stack_ele {
    void* value;
    int size;
    stack_ele* next;
};

struct stack {
    stack_ele* head;
};

// Creation/Deletion
int stack_create(stack** my_stack);
int stack_delete(stack* my_stack);

// Accessors
int get_stack_size(stack* my_stack);

// Mutators
int stack_push(stack* my_stack, void* data, int size);
int stack_pop(stack* my_stack, void* data);

#endif /* End stack.h */
