#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FREE(ptr) do { free(ptr); ptr = NULL; } while(0)

struct stack {
    struct stack_ele* head;    /**< Pointer to the stack */
    int size;                  /**< The number of elements on the stack*/
};

struct stack_ele {
    void* value;            /**< A pointer to the data */
    int size;               /**< The size of the data */
    struct stack_ele* next; /**< The next element on the stack */
};

int stack_create(stack** my_stack) {
    if (my_stack == NULL)
        return STACK_INVALID;

    *my_stack = malloc(sizeof(*my_stack));

    if (*my_stack == NULL)
        return STACK_OUT_OF_MEM;
    
    (*my_stack)->head = NULL;
    (*my_stack)->size = 0;

    return STACK_SUCCESS;
}

int stack_delete(stack* my_stack) {
    if (my_stack == NULL)
        return STACK_INVALID;

    while (my_stack->head != NULL) {
        // Traverse structure
        struct stack_ele* temp = my_stack->head;
        my_stack->head = my_stack->head->next;

        // Free both data and stack element
        FREE(temp->value);
        FREE(temp);
    }

    FREE(my_stack);

    return STACK_SUCCESS;
}

int stack_get_size(stack* my_stack) {
    if (my_stack == NULL)
        return STACK_INVALID;   

    return my_stack->size;
}

int stack_push(stack* my_stack, void* data, int size) {
    if (my_stack == NULL)
        return STACK_INVALID;

    if (data == NULL)
        return STACK_UNDEF_DATA;

    if (size <= 0)
        return STACK_INVALID_SIZE;

    // Create a new stack element
    struct stack_ele* newItem = malloc(sizeof(*newItem));

    if (newItem == NULL)
        return STACK_OUT_OF_MEM;

    // Initialize data elements
    newItem->size = size;
    newItem->next = my_stack->head;
    newItem->value = malloc(size);

    if (newItem->value == NULL) {
        // Cleanup and return
        FREE(newItem);
        return STACK_OUT_OF_MEM;
    }

    // Copy user data into memory
    memcpy(newItem->value, data, size);

    // Place at the top of the stack
    my_stack->head = newItem;
    my_stack->size++;

    return STACK_SUCCESS;
}

int stack_pop(stack* my_stack, void* data) {
    if (my_stack == NULL)
        return STACK_INVALID;

    if (my_stack->head == NULL)
        return STACK_EMPTY;

    if (data == NULL)
        return STACK_UNDEF_DATA;

    // Copy element data to user data
    memcpy(data, my_stack->head->value, my_stack->head->size);

    // Remove the element from the stack, update stack to point to next element
    struct stack_ele* temp = my_stack->head;
    my_stack->head = my_stack->head->next;

    FREE(temp->value);
    FREE(temp);

    my_stack->size--;

    return STACK_SUCCESS;
}

int stack_get_data_size(stack* my_stack) {
    if (my_stack == NULL)
        return STACK_INVALID;

    if (my_stack->head == NULL)
        return STACK_EMPTY;

    return my_stack->head->size;
}
