#include "avl_tree.h"

int getHeight(Node *n){
    if(n==NULL)
        return 0;
    return n->height;
}

Node *createNode(int key){
    Node* node = (Node*)malloc(sizeof(Node));

    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

Node *insertNode(Node *root, int key){        // inserir_chave

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

Node *searchKey(Node *root, int key){     // buscar_chave
    if(root==NULL | key==root->key)
        return root;
    if(key<root->key)   // buscar na sub-árvore à esquerda
        return searchKey(root->left, key);
    else    // buscar na sub-árvore à esquerda
        return searchKey(root->right, key);
}

Node* removeNode(Node *root, int key){        // remover_chave
    if(root == NULL)
        return root;

    if(key<root->key){
        root->left = removeNode(root->left, key);
    } else if(key>root->key){
        root->right = removeNode(root->right, key);
    } else{     // achei o nó a ser removido

        // nó com apenas um filho ou sem filhos
        if ((root->left == NULL) || (root->right == NULL)){
            Node *temp = root->left ? root->left : root->right;

            if(temp == NULL){
                temp = root;
                root = NULL;
            } else{
                *root = *temp; // copiar o conteúdo do filho não vazio
            }

            free(temp);
        } else{

            // nó com dois filhos: obter o sucessor inorder (menor nó da sub-árvore à direita)
            Node *temp = treeSucessor(root->right);

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

    // esquerda-esquerda
    if (balanceF > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // esquerda-direita
    if (balanceF > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // direita-direita
    if (balanceF < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // direita-esquerda
    if (balanceF < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrder(Node *root){        // inorder
    if(root!=NULL){
        inOrder(root->left);
        printf("%d\n", root->key);
        inOrder(root->right);
    }
}

Node *treeSucessor(Node* n){      // sucessor
     Node *current = n;

    // encontrar a folha mais à esquerda (menor nó da sub-árvore)
    while (current->left != NULL)
        current = current->left;

    return current;
}

int getBalance(Node *n){     // fator_balanco
    if(n==NULL)
        return 0;

    int h_left = getHeight(n->left);
    int h_right = getHeight(n->right);
    return h_left-h_right;      
}

Node *leftRotate(Node *n){        // rotacao_esq
     Node *y = n->right;
    n->right = y->left;
    y->left = n;

    // atualizar a altura dos nós
    n->height = 1 + (getHeight(n->left)>getHeight(n->right)?getHeight(n->left):getHeight(n->right));
    y->height = 1 + (getHeight(y->left)>getHeight(y->right)?getHeight(y->left):getHeight(y->right));

    return y;
}

Node *rightRotate(Node *n){       // rotacao_dir
     Node *x = n->left;
    n->left = x->right;
    x->right = n;

    // atualizar a altura dos nós
    n->height = 1 + (getHeight(n->left)>getHeight(n->right)?getHeight(n->left):getHeight(n->right));
    x->height = 1 + (getHeight(x->left)>getHeight(x->right)?getHeight(x->left):getHeight(x->right));

    return x;
}

Node *leftRightRotate(Node *n){       // rotacao_esq_dir
    n->left = leftRotate(n->left);
    return rightRotate(n);
}

Node *rightLeftRotate(Node *n){       // rotacao_dir_esq
    n->right = rightRotate(n->right);
    return leftRotate(n);
}

void printTree(Node *root, int depth, char prefix) {     // função para imprimir a árvore
    if (root == NULL)
        return;

    printTree(root->right, depth + 1, '/');

    for (int i = 0; i < depth; i++)
        printf("   ");
    
    printf("%c%d\n", prefix, root->key);

    printTree(root->left, depth + 1, '\\');
}

void printBalance(Node *root){       // calcular o fator de balanço de todos os nós
    if(root!=NULL){
        int balanceF = getBalance(root);
        printBalance(root->left);
        printf("(%d) = %d\n", root->key, balanceF);
        printBalance(root->right);
    }
}

void freeTree(Node* root){
    if (root!=NULL){
        freeTree(root->left);  // libera a memória da subárvore esquerda
        freeTree(root->right); // libera a memória da subárvore direita
        free(root);            // libera a memória do nó atual
    }
}