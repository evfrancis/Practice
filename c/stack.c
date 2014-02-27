#include "stack.h"

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

    *my_stack = (stack*)malloc(sizeof(*my_stack));

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
        free(temp->value);
        temp->value = NULL;
        free(temp);
        temp = NULL;
    }

    free(my_stack);
    my_stack = NULL;

    return STACK_SUCCESS;
}

int stack_get_size(stack* my_stack) {
    if (my_stack == NULL)
        return STACK_INVALID;   

    stack_ele* head = my_stack->head;
    while (head != NULL) {
        // Traverse and count
        size++;
        head = head->next;
    }

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
    struct stack_ele* newItem = (struct stack_ele*)malloc(sizeof(*newItem));

    if (newItem == NULL)
        return STACK_OUT_OF_MEM;

    // Initialize data elements
    newItem->size = size;
    newItem->next = my_stack->head;
    newItem->value = (void*)malloc(size);

    if (newItem->value == NULL) {
        // Cleanup and return
        free(newItem);
        newItem = NULL;
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

    struct stack_ele* temp = my_stack->head;

    // Remove the element from the stack, update stack to point to next element
    stack_ele* temp = my_stack->head;
    my_stack->head = my_stack->head->next;

    free(temp->value);
    temp->value = NULL;
    free(temp);
    temp = NULL;

    my_stack->size--;

    return STACK_SUCCESS;
}
