#include "stdio.h"
#include "time.h"
#include "assert.h"
#include "linkedList.h"
#include "BST.h"
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
    testAlgorithms();
    return 0;
}
