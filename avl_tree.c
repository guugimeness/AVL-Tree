#include "avl_tree.h"

int getHeight(struct Node *n){
    if(n==NULL)
        return 0;
    return n->height;
}

struct Node *createNode(int key){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

struct Node *insertNode(struct Node *root, int key){        // inserir_chave

    // encontra a posição correta e insere o nó
    if(root==NULL){
        return createNode(key);
    } else if(key>root->key){
        root->right = insertNode(root->right, key);
    } else{
        root->left = insertNode(root->left, key);
    }

    // atualiza a altura do nó
    root->height = 1 + ( getHeight(root->left)>getHeight(root->right) ? getHeight(root->left) : getHeight(root->right) );

    // atualiza o fator de balanço e faz rotações, se necessário
    int balanceF = getBalance(root);
    if(balanceF>1){
        if(key<root->left->key)
            return rightRotate(root);
        else
            return leftRightRotate(root);
    } else if(balanceF<-1){
        if(key>root->right->key)
            return leftRotate(root);
        else
            return rightLeftRotate(root);
    }

    return root;
}

struct Node *searchKey(struct Node *root, int key){     // buscar_chave
    if(root==NULL | key==root->key)
        return root;
    if(key<root->key)
        return searchKey(root->left, key);
    else
        return searchKey(root->right, key);
}

int getBalance(struct Node *n){     // fator_balanco
    if(n==NULL)
        return 0;

    int h_left = getHeight(n->left);
    int h_right = getHeight(n->right);
    return h_left-h_right;      
}

struct Node *leftRotate(struct Node *n){        // rotacao_esq
    struct Node *y = n->right;
    n->right = y->left;
    y->left = n;

    // atualizar a altura dos nós
    n->height = 1 + (getHeight(n->left)>getHeight(n->right)?getHeight(n->left):getHeight(n->right));
    y->height = 1 + (getHeight(y->left)>getHeight(y->right)?getHeight(y->left):getHeight(y->right));

    return y;
}

struct Node *rightRotate(struct Node *n){       // rotacao_dir
    struct Node *x = n->left;
    n->left = x->right;
    x->right = n;

    // atualizar a altura dos nós
    n->height = 1 + (getHeight(n->left)>getHeight(n->right)?getHeight(n->left):getHeight(n->right));
    x->height = 1 + (getHeight(x->left)>getHeight(x->right)?getHeight(x->left):getHeight(x->right));

    return x;
}

void inOrder(struct Node *root){
    if(root==NULL)
        return
    inOrder(root->left);
    printf("%d\n", root->key);
    inOrder(root->right);
}
