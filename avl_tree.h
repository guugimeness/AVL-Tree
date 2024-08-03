#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;                // chave 
    int height;             // altura
    struct Node *left;      // referência para o filho à esquerda
    struct Node *right;     // referência para o filho à direita
};

int getHeight(struct Node *n);                              // calcular a altura de um nó
struct Node *createNode(int key);                           // criar um nó
struct Node *insertNode(struct Node *root, int key);        // inserir_chave
struct Node *searchKey(struct Node *root, int key);         // buscar_chave
struct Node* removeNode(struct Node *root, int key);        // remover_chave
void inOrder(struct Node *root);                            // inorder
struct Node *treeSucessor(struct Node* n);                  // sucessor
int getBalance(struct Node *n);                             // fator_balanco
struct Node *leftRotate(struct Node *n);                    // rotacao_esq
struct Node *rightRotate(struct Node *n);                   // rotacao_dir
struct Node *leftRightRotate(struct Node *n);               // rotacao_esq_dir
struct Node *rightLeftRotate(struct Node *n);               // rotacao_dir_esq
void printTree(struct Node *root, int depth, char prefix);  // imprimir a árvore
void printBalance(struct Node *root);                       // calcular o fator de balanço de todos os nós