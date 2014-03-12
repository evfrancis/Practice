#include "stdio.h"
#include "stdlib.h"
#include "BST.h"

void printInOrder(bstNode* head) {
    if (head == NULL) {
        return;
    }

    printInOrder(head->left);
    printf("%d ", head->val);
    printInOrder(head->right);
}

void insertBSTNode(bstNode** head, int val) {
    if (head == NULL) {
        // Empty pointer
        return;
    }

    bstNode* temp = *head;
    if (temp == NULL) {
        // Empty BST, create one
        temp = malloc(sizeof(bstNode));
        temp->left = NULL;
        temp->right = NULL;
        temp->val = val;
        *head = temp;
        return;
    } 

    // BST exists, find where to place the new val
    if (val <= temp->val) {
        // Val is smaller than current node, traverse down the left node
        bstNode* left = temp->left;
        insertBSTNode(&left, val);
        temp->left = left;
    } else {
        // Val is larger than current node, traverse down the right node
        bstNode* right = temp->right;
        insertBSTNode(&right, val);
        temp->right = right;
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
