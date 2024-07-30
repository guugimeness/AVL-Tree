#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    int height;      // altura do nó
    struct Node *left;      // referência para o filho à esquerda
    struct Node *right;     // referência para o filho à direita
};

int getHeight(struct Node *n);
struct Node *createNode(int key);
struct Node *insertNode(struct Node *root, int key);
struct Node *searchKey(struct Node *root, int key);
int getBalance(struct Node *n);
struct Node *leftRotate(struct Node *n);
struct Node *rightRotate(struct Node *n);
struct Node *leftRightRotate(struct Node *n);
struct Node *rightLeftRotate(struct Node *n);
void inOrder(struct Node *root);