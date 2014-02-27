#include "stack.h"

int stack_create(stack** my_stack) {
    if (my_stack == NULL)
        return NULL_STACK;

    *my_stack = (stack*)malloc(sizeof(stack));

    if (*my_stack == NULL)
        return OUT_OF_MEM;
    
    (*my_stack)->head = NULL;

    return SUCCESS;
}

int stack_delete(stack* my_stack) {
    if (my_stack == NULL)
        return NULL_STACK;

    while (my_stack->head != NULL) {
        // Traverse structure
        stack_ele* temp = my_stack->head;
        my_stack->head = my_stack->head->next;
        
        // Free both data and stack element
        free(temp->value);
        free(temp);
    }

    free(my_stack);

    return SUCCESS;
}

int get_stack_size(stack* my_stack) {
    int size = 0;
    if (my_stack == NULL)
        return NULL_STACK;   

    stack_ele* head = my_stack->head;
    while (head != NULL) {
        // Traverse and count
        size++;
        head = head->next;
    }

    return size;
}

int stack_push(stack* my_stack, void* data, int size) {
    if (my_stack == NULL)
        return NULL_STACK;

    if (data == NULL)
        return UNDEF_DATA;

    if (size <= 0)
        return INVALID_SIZE;

    // Create a new stack element
    stack_ele* newItem = (stack_ele*)malloc(sizeof(stack_ele));

    if (newItem == NULL)
        return OUT_OF_MEM;

    // Initialize data elements
    newItem->size = size;
    newItem->next = my_stack->head;
    newItem->value = (void*)malloc(size);

    // Copy user data into memory
    memcpy(newItem->value, data, size);

    // Place at the top of the stack
    my_stack->head = newItem;

    return SUCCESS;
}

int stack_pop(stack* my_stack, void* data) {
    if (my_stack == NULL)
        return NULL_STACK;

    if (my_stack->head == NULL)
        return STACK_EMPTY;

    if (data == NULL)
        return UNDEF_DATA;

    // Copy element data to user data
    memcpy(data, my_stack->head->value, my_stack->head->size);

    // Remove the element from the stack, update stack to point to next element
    stack_ele* temp = my_stack->head;
    my_stack->head = my_stack->head->next;
    free(temp->value);
    free(temp);

    return SUCCESS;
}
