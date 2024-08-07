#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;                // chave 
    int height;             // altura
    struct Node *left;      // referência para o filho à esquerda
    struct Node *right;     // referência para o filho à direita
} Node;

int getHeight(struct Node *n);                              // calcular a altura de um nó
Node *createNode(int key);                           // criar um nó
Node *insertNode(struct Node *root, int key);        // inserir_chave
Node *searchKey(struct Node *root, int key);         // buscar_chave
Node* removeNode(struct Node *root, int key);        // remover_chave
void inOrder(struct Node *root);                            // inorder
Node *treeSucessor(struct Node* n);                  // sucessor
int getBalance(struct Node *n);                             // fator_balanco
Node *leftRotate(struct Node *n);                    // rotacao_esq
Node *rightRotate(struct Node *n);                   // rotacao_dir
Node *leftRightRotate(struct Node *n);               // rotacao_esq_dir
Node *rightLeftRotate(struct Node *n);               // rotacao_dir_esq
void printTree(struct Node *root, int depth, char prefix);  // imprimir a árvore
void printBalance(struct Node *root);                       // calcular o fator de balanço de todos os nós
void freeTree(Node* root);                           // liberar memória alocada