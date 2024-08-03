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
    if(root==NULL)
        return createNode(key);
    else if(key>root->key)
        root->right = insertNode(root->right, key);
    else if(key<root->key)
        root->left = insertNode(root->left, key);
    else
        return root;

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

struct Node* removeNode(struct Node *root, int key) {
    if(root == NULL)
        return root;

    if(key<root->key) {
        root->left = removeNode(root->left, key);
    } else if(key>root->key) {
        root->right = removeNode(root->right, key);
    } else{
        // nó com apenas um filho ou sem filhos
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node *temp = root->left ? root->left : root->right;

            if(temp == NULL) {
                temp = root;
                root = NULL;
            } else{
                *root = *temp; // Copiar o conteúdo do filho não vazio
            }

            free(temp);
        } else{
            // nó com dois filhos: obter o sucessor inorder (menor na subárvore direita)
            struct Node *temp = treeSucessor(root->right);

            root->key = temp->key;

            root->right = removeNode(root->right, temp->key);
        }
    }

    if(root==NULL)
        return root;

    // atualiza a altura do nó
    root->height = 1 + ( getHeight(root->left)>getHeight(root->right) ? getHeight(root->left) : getHeight(root->right) );

    // atualiza o fator de balanço e faz rotações, se necessário
    int balanceF = getBalance(root);

    // Caso Esquerda Esquerda
    if (balanceF > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Caso Esquerda Direita
    if (balanceF > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Caso Direita Direita
    if (balanceF < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Caso Direita Esquerda
    if (balanceF < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrder(struct Node *root){        // inorder
    if(root!=NULL){
        inOrder(root->left);
        printf("%d\n", root->key);
        inOrder(root->right);
    }
}

struct Node *treeSucessor(struct Node* n){      // sucessor
    struct Node *current = n;

    // encontrar a folha mais à esquerda
    while (current->left != NULL)
        current = current->left;

    return current;
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

struct Node *leftRightRotate(struct Node *n){       // rotacao_esq_dir
    n->left = leftRotate(n->left);
    return rightRotate(n);
}

struct Node *rightLeftRotate(struct Node *n){       // rotacao_dir_esq
    n->right = rightRotate(n->right);
    return leftRotate(n);
}

void printTree(struct Node *root, int depth, char prefix) {
    if (root == NULL)
        return;

    printTree(root->right, depth + 1, '/');

    for (int i = 0; i < depth; i++)
        printf("   ");
    
    printf("%c%d\n", prefix, root->key);

    printTree(root->left, depth + 1, '\\');
}

void printBalance(struct Node *root){
    if(root!=NULL){
        int balanceF = getBalance(root);
        printf("(%d) = %d\n", root->key, balanceF);
        printBalance(root->left);
        printBalance(root->right);
    }
}