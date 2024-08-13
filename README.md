# AVL-Tree

### O que são?
- *Árvore AVL*, ou ainda *Árvore Binária de Busca Balanceada*, é uma estrutura de dados do tipo árvore desenvolvida para contornar um problema comum nas árvores de busca tradicionais: padrão de crescimento irregular e desbalanceado. Esse problema acaba muitas vezes por tornar as operações de inserção, busca e remoção menos eficientes.
- A estratégia para evitar esse inconveniente foi adicionar ao nó da árvore um fator de balanço, definido como:  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; $x.b = h_L - h_R$, em que $h_L$ é a altura da subárvore à esquerda e $h_R$ é a altura da subárvore à direita.  
Dessa forma, uma árvore AVL é dita balanceada quando:  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; $∀ x ∈ T (x.b ∈  [-1, 0, 1])$
- Assim, deve-se checar o fator de balanço dos nós sempre após uma inserção ou remoção para, caso a árvore esteja desbalanceada, realizar rotações nos nós para garantir que esse fator esteja entre -1 e +1.

### Execução
- Esse foi um projeto para a disciplina de *Algoritmos e Estruturas de Dados II* que exigia os seguintes testes para validar seu funcionamento:  
1. Inserir as seguintes chaves (nessa ordem):  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **11, 12, 13, 14, 15, 20, 19, 18, 17, 16, 5, 4, 3, 2, 1, 6, 7, 8, 9, 10**
2. Mostrar percurso inorder (como fica a árvore após todas as rotações). Fazer um esboço de como fica a árvore após todas as inserções (e eventuais rotações).
3. Calcular fator de balanço de todos os nós.
4. Remover as chaves (nessa ordem):  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **5, 10 e 15**
6. Mostrar percurso inorder (como fica a árvore após todas as rotações).
7. Calcular fator de balanço de todos os nós.

##  Status: Finalizado
