#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#include "linkedList.h"
#include "BST.h"
#include "stack.h"
#include "algorithms.h"

#define ARRAY_LEN 200
#define ARRAY_MAX 1000

void randomize(int* array, int len, int max) {
    int i;
    for (i=0; i < len; i++) {
        int r = rand() % ARRAY_MAX;
        array[i] = r;
    }
}

void printArray(int* array, int len) {
    int i;
    for (i=0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void testAlgorithms() {
    int i;
    // Initialize + Display random array
    int array[ARRAY_LEN];
    randomize(array, ARRAY_LEN, ARRAY_MAX);

    // Sort array + Test it
    quickSort(array, 0, ARRAY_LEN-1);
    for (i=1; i < ARRAY_LEN; i++) {
        assert(array[i-1] <= array[i]);
    }
    printf("Sorting: Success\n");

    // Test binary search
    for (i=0; i < ARRAY_LEN; i++) {
        int index = binarySearch(array, 0, ARRAY_LEN-1, array[i]);
        assert(array[index] == array[i]);
    }
    assert(binarySearch(array, 0, ARRAY_LEN-1, ARRAY_MAX+1) == -1);
    assert(binarySearch(array, 0, ARRAY_LEN-1, -10) == -1);
    printf("Searching: Success\n");
}

void testBST() {
    int array[ARRAY_LEN];
    randomize(array, ARRAY_LEN, ARRAY_MAX);
    int i;

    bstNode* head = NULL;
    for (i=0; i < ARRAY_LEN; i++) {
        insertBSTNode(&head, array[i]);
    }

    printInOrder(head);
}

void testStack() {
    // Create
    stack* my_stack = NULL;
    stack* dummy_stack = NULL;

    assert(stack_create(&my_stack) == 0); // Successfully create
    assert(stack_create(&dummy_stack) == 0); // Successfully create
    assert(stack_get_size(my_stack) == 0); // 0 size

    int a = 3;
    int b = 4;
    double c = 5.12;
    char d = 'c';
    char str[20] = "Hello World";

    // Successful pushes
    assert(stack_push(my_stack, &a, sizeof(a)) == 0);
    assert(stack_push(my_stack, &b, sizeof(b)) == 0);
    assert(stack_push(my_stack, &c, sizeof(c)) == 0);
    assert(stack_push(my_stack, &d, sizeof(d)) == 0);
    assert(stack_push(my_stack, str, strlen(str)) == 0);

    // Bad pushes:
    assert(stack_push(NULL, &a, sizeof(a)) != 0);
    assert(stack_push(my_stack, NULL, sizeof(a)) != 0);
    assert(stack_push(my_stack, &a, 0) != 0);

    assert(stack_get_size(my_stack) == 5); // 5 items

    int a2;
    int b2;
    double c2;
    char d2;
    char str2[20];

    // Bad pop:
    assert(stack_pop(NULL, &a) != 0);
    assert(stack_pop(dummy_stack, &a) != 0);
    assert(stack_pop(my_stack, NULL) != 0);

    // Successful pop:
    assert(stack_get_data_size(my_stack) <= 20);
    assert(stack_pop(my_stack, str2) == 0 && strcmp(str,str)==0);

    assert(stack_get_data_size(my_stack) == sizeof(d2));
    assert(stack_pop(my_stack, &d2) == 0 && d==d2);

    assert(stack_get_data_size(my_stack) == sizeof(c2));
    assert(stack_pop(my_stack, &c2) == 0 && c==c2);

    assert(stack_get_data_size(my_stack) == sizeof(b2));
    assert(stack_pop(my_stack, &b2) == 0 && b==b2);

    assert(stack_get_data_size(my_stack) == sizeof(a2));
    assert(stack_pop(my_stack, &a2) == 0 && a==a2);

    // Bad pop
    assert(stack_pop(my_stack, &a2) != 0);

    // Cleanup
    assert(stack_delete(my_stack) == 0); // Successfully create
    assert(stack_delete(dummy_stack) == 0); // Successfully create


    printf("Stack: Success\n");
}

void testLL() {
    node* head = NULL;
    int vals[20] = {2,2,2,4,4,2,6,2,4,4,31,37,9,6,4,5,2,2,2,4};
    // Initialize:
    int i;
    for (i=0; i < 20; i++) {
        insertNode(&head, vals[i]);
    }
    
    // Get stats
    printf("Size: %d, Index of 6: %d\n", countNodes(head), searchLL(head, 6));
    printLL(head);
    removeNode(&head, 2);
    printLL(head);
    removeNode(&head, 4);
    printLL(head);
    printf("Size: %d, Index of 6: %d\n", countNodes(head), searchLL(head, 6));
}

int main() {
    srand(time(NULL));
    //testLL();
    testBST();
    return 0;
}
