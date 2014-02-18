// LL Node Struct
#ifndef linkedList_h
#define linkedList_h
typedef struct node node;

struct node{
    int val;
    node* next;
};

void insertNode(node** head, int val);
void removeNode(node** head, int val);
void printLL(node* head);
int countNodes(node* head);
int searchLL(node* head, int val);
#endif
