#include "stdio.h"
#include "stdlib.h"
#include "linkedList.h"

// Deletes all nodes with value "val"
void removeNode(node** head, int val) {
    if (head == NULL || *head == NULL) {
        // Emptry list
        return;
    }

    node* temp = *head;

    while (temp != NULL && temp->val == val) {
        // Remove head
        node* t = temp;
        temp = temp->next;
        free(t);
    }

    // Assign new head
    *head = temp;

    if (temp == NULL) {
        return;
    }

    // Now handle removing all the other elements
    node* nextPtr = temp->next;
    while (nextPtr != NULL) {
        if (nextPtr->val == val) {
            temp->next = nextPtr->next;
            free(nextPtr);
            nextPtr = temp->next;
            continue;
        }
        temp = temp->next;
        nextPtr = nextPtr->next;
    }

}

// Inserts a node to the end of the LL with value val
void insertNode(node** head, int val) {
    if (head == NULL) {
        printf("Error: NULL input\n");
    }

    node* temp = *head;

    if (temp == NULL) {
        // Empty list, create first entry and point head to it
        temp = malloc(sizeof(node));
        temp->val = val;
        temp->next = NULL;
        *head = temp;
        return;
    }

    // Find last entry
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Create new node and add to end
    node* temp2 = malloc(sizeof(node));
    temp2->val = val;
    temp2->next = NULL;
    temp->next = temp2;
}

// Counts the elements in the linked list head. 0 means it is empty.
int countNodes(node* head) {
    int c = 0;
    while (head != NULL) {
        c++;
        head = head->next;
    }
    return c;
}

// Search for an element in the linkedlist.
int searchLL(node* head, int val) {
    int c = 0;
    while (head != NULL) {
        if (head->val == val) {
            return c;
        }
        c++;
        head = head->next;
    }
    return -1;
}

// Prints the full linked list
void printLL(node* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}
