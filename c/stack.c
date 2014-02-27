#include "stack.h"

int stack_create(stack** my_stack) {
    if (my_stack == NULL)
        return NULL_STACK;

    *my_stack = malloc(sizeof(stack));

    if (*my_stack == NULL)
        return OUT_OF_MEM;
    
    (*my_stack)->head = NULL;

    return SUCCESS;
}

int stack_delete(stack* my_stack) {
    if (my_stack == NULL)
        return NULL_STACK;

    while (my_stack->head != NULL) {
        stack_ele* temp = my_stack->head;
        my_stack->head = my_stack->head->next;
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

    stack_ele* newItem = malloc(sizeof(stack_ele));

    if (newItem == NULL)
        return OUT_OF_MEM;

    newItem->size = size;
    newItem->next = my_stack->head;
    newItem->value = malloc(size);

    memcpy(newItem->value, data, size);

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

    memcpy(data, my_stack->head->value, my_stack->head->size);

    stack_ele* temp = my_stack->head;
    my_stack->head = my_stack->head->next;
    free(temp->value);
    free(temp);

    return SUCCESS;
}
