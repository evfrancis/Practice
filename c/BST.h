typedef struct bstNode bstNode;

struct bstNode {
    int val;
    bstNode* left;
    bstNode* right;
};

void printInOrder(bstNode* head);
void insertBSTNode(bstNode** head, int val);
void removeBSTNode(bstNode** head, int val);
bstNode* searchBST(bstNode* head, int val);
