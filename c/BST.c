#include "stdio.h"
#include "stdlib.h"
#include "BST.h"

void insertBSTNode(bstNode** head, int val) {
    if (head == NULL) {
        // Empty pointer
        return;
    }

    bstNode* temp = *head;
    if (temp == NULL) {
        temp = malloc(sizeof(bstNode));
        temp->left = NULL;
        temp->right = NULL;
        temp->val = val;
        *head = temp;
        return;
    } 

}

void removeBSTNode(bstNode** head, int val) {

}

bstNode* searchBST(bstNode* head, int val) {
    if (head == NULL) {
        // Emptry BST
        return NULL;
    }

    if (head->val < val) {
        return searchBST(head->left, val);
    } else if (head->val > val) {
        return searchBST(head->right, val);
    } else {
        return head;
    }
}
