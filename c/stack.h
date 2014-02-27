#ifndef STACK_H
#define STACK_H

/*! \file stack.h
    \brief A stack implementation
    
    This is an implementation of a stack. The API provides creation,
    deletion, pushes, pops, and access of the size of the stack. The convention
    used is to return 0 on success and an error code on failure. When it comes to
    pushing data onto the stack, a memory address is given. A copy of this memory
    is made and managed by this library. On a pop, the user must allocate space
    so that the library can copy data back.
    */


// Error Handling
#define STACK_SUCCESS        0 /*!< Action performed successfully @hideinitializer*/
#define STACK_INVALID       -1 /*!< The stack argument provided was NULL @hideinitializer*/
#define STACK_UNDEF_DATA    -2 /*!< The data argument provided was NULL @hideinitializer*/
#define STACK_INVALID_SIZE  -3 /*!< The size of the data provided was 0 or less @hideinitializer*/
#define STACK_EMPTY         -4 /*!< There are no elements left on the stack @hideinitializer*/
#define STACK_OUT_OF_MEM    -5 /*!< Could not allocate data, system out of memory @hideinitializer*/

// ---------- Data Structure ----------

/**
 * The stack itself
 */
struct stack;
typedef struct stack stack;

// ---------- Creation/Deletion ----------

/**
 * Creates a new stack structure. The argument *my_stack is set to the
 * location of this structure
 * @param my_stack A pointer that store the location of the stack
 * @return 0 on success, an error code on failure
 */
int stack_create(stack** my_stack);

/**
 * Deletes a stack
 * @param my_stack The stack
 * @return 0 on success, an error code on failure
 */
int stack_delete(stack* my_stack);

// ---------- Accessors ----------
/**
 * Gets the number of elements on the stack
 * @param my_stack The stack
 * @return The size (> 0) on success, an error code on failure
 */
int stack_get_size(stack* my_stack);

// ---------- Mutators ----------
/**
 * Pushes an element on to the stack. This library makes a copy of
 * the data and manages it.
 * @param my_stack The stack
 * @param data A pointer to the data memory
 * @param size The size of the data
 * @return 0 on success, an error code on failure
 */
int stack_push(stack* my_stack, void* data, int size);

/**
 * Pops an element off the stack. The user must allocate memory for
 * the library to fill in with the data on the top of the stack.
 * @param my_stack The stack
 * @param data A pointer to a segment of memory that can hold the element
 * @return 0 on success, an error code on failure
 */
int stack_pop(stack* my_stack, void* data);

/**
 * Gets the size of the data stored at the top of the stack. This value is the amount the
 * user must allocate for the library to pop off a value.
 * @param my_stack The stack
 * @return The size (> 0) on success, an error code on failure
 */
int stack_get_data_size(stack* my_stack);

#endif /* End stack.h */
