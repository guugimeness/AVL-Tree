#include "avl_tree.c"

int main(){
    Node *root = NULL;

    printf("1) Inserindo as chaves na árvore...\n");
    root = insertNode(root, 11);
    root = insertNode(root, 12);
    root = insertNode(root, 13);
    root = insertNode(root, 14);
    root = insertNode(root, 15);
    root = insertNode(root, 20);
    root = insertNode(root, 19);
    root = insertNode(root, 18);
    root = insertNode(root, 17);
    root = insertNode(root, 16);
    root = insertNode(root, 5);
    root = insertNode(root, 4);
    root = insertNode(root, 3);
    root = insertNode(root, 2);
    root = insertNode(root, 1);
    root = insertNode(root, 6);
    root = insertNode(root, 7);
    root = insertNode(root, 8);
    root = insertNode(root, 9);
    root = insertNode(root, 10);
    printf("\n");

    printf("2) Percurso inorder após inserções + esboço da árvore:\n");
    inOrder(root);
    printf("\n");

    printTree(root, 0, ' ');
    printf("---------------------->\n");
    printf("\n");

    printf("3) Calcular fator de balanço de todos os nós: \n");
    printBalance(root);
    printf("\n");

    printf("4) Removendo as chaves na árvore...\n");
    root = removeNode(root, 5);
    root = removeNode(root, 10);
    root = removeNode(root, 15);
    printf("\n");

    printf("5) Percurso inorder após remoções + esboço da árvore:\n");
    inOrder(root);
    printf("\n");

    printTree(root, 0, ' ');
    printf("---------------------->\n");
    printf("\n");

    printf("6) Calcular fator de balanço de todos os nós: \n");
    printBalance(root);
    printf("\n");

    // liberando a memória alocada
    freeTree(root);

    return 0;
};