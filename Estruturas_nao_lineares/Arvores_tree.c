#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da árvore binária
struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
};

// Função para criar um novo nó
struct No* criarNo(int valor) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para inserir um valor na árvore (árvore de busca binária)
struct No* inserir(struct No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    
    return raiz;
}

// Travessias em árvore
void preOrdem(struct No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void emOrdem(struct No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        emOrdem(raiz->direita);
    }
}

void posOrdem(struct No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

// Função para buscar um valor na árvore
struct No* buscar(struct No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }
    
    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    } else {
        return buscar(raiz->direita, valor);
    }
}

// Função para encontrar o nó com menor valor (mais à esquerda)
struct No* encontrarMinimo(struct No* no) {
    struct No* atual = no;
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

// Função para remover um nó
struct No* removerNo(struct No* raiz, int valor) {
    if (raiz == NULL) return raiz;
    
    if (valor < raiz->valor) {
        raiz->esquerda = removerNo(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = removerNo(raiz->direita, valor);
    } else {
        // Nó com apenas um filho ou sem filhos
        if (raiz->esquerda == NULL) {
            struct No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            struct No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        
        // Nó com dois filhos: pega o sucessor in-order (menor na subárvore direita)
        struct No* temp = encontrarMinimo(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = removerNo(raiz->direita, temp->valor);
    }
    return raiz;
}

// Função para calcular a altura da árvore
int altura(struct No* no) {
    if (no == NULL) {
        return -1;
    } else {
        int alturaEsq = altura(no->esquerda);
        int alturaDir = altura(no->direita);
        return (alturaEsq > alturaDir) ? alturaEsq + 1 : alturaDir + 1;
    }
}

// Função para liberar a memória da árvore
void liberarArvore(struct No* no) {
    if (no != NULL) {
        liberarArvore(no->esquerda);
        liberarArvore(no->direita);
        free(no);
    }
}

int main() {
    printf("=== Estruturas de Árvores em C ===\n\n");

    /* ----------------------------
       Conceitos Básicos
       ---------------------------- */
    printf("1. Conceitos Básicos:\n");
    printf("   - Árvore: estrutura hierárquica não-linear\n");
    printf("   - Nó raiz: topo da hierarquia\n");
    printf("   - Nós folha: terminais sem filhos\n");
    printf("   - Subárvores: árvores enraizadas nos filhos\n");
    printf("   - Árvore Binária: cada nó tem no máximo 2 filhos\n");
    printf("   - Árvore Binária de Busca: ordenada (esquerda < raiz < direita)\n\n");

    /* ----------------------------
       Implementação Prática
       ---------------------------- */
    printf("2. Implementação de Árvore Binária de Busca:\n");
    
    struct No* raiz = NULL;
    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 20);
    inserir(raiz, 40);
    inserir(raiz, 70);
    inserir(raiz, 60);
    inserir(raiz, 80);
    
    printf("   - Travessia em-ordem: ");
    emOrdem(raiz);
    printf("\n");
    
    printf("   - Travessia pré-ordem: ");
    preOrdem(raiz);
    printf("\n");
    
    printf("   - Travessia pós-ordem: ");
    posOrdem(raiz);
    printf("\n");
    
    /* ----------------------------
       Operações Comuns
       ---------------------------- */
    printf("\n3. Operações Comuns:\n");
    
    // Busca
    int valorBusca = 40;
    struct No* resultado = buscar(raiz, valorBusca);
    printf("   - Busca por %d: %sencontrado\n", valorBusca, resultado ? "" : "não ");
    
    // Altura
    printf("   - Altura da árvore: %d\n", altura(raiz));
    
    // Remoção
    printf("\n   - Removendo o valor 20:\n");
    raiz = removerNo(raiz, 20);
    printf("     Em-ordem após remoção: ");
    emOrdem(raiz);
    printf("\n");
    
    /* ----------------------------
       Tipos de Árvores
       ---------------------------- */
    printf("\n4. Tipos de Árvores:\n");
    printf("   - Árvore Binária Completa: todos os níveis exceto último completamente preenchidos\n");
    printf("   - Árvore Binária Perfeita: todos os níveis completamente preenchidos\n");
    printf("   - Árvore AVL: balanceada (altura das subárvores difere no máximo em 1)\n");
    printf("   - Árvore Rubro-Negra: balanceada com regras de coloração\n");
    printf("   - Heap: árvore completa com propriedade de heap\n");
    printf("   - Árvore B: generalização para sistemas de arquivos e bancos de dados\n");
    
    /* ----------------------------
       Aplicações Práticas
       ---------------------------- */
    printf("\n5. Aplicações Práticas:\n");
    printf("   - Sistemas de arquivos (diretórios)\n");
    printf("   - Banco de dados (índices)\n");
    printf("   - Compressão de dados (Huffman)\n");
    printf("   - Inteligência Artificial (árvores de decisão)\n");
    printf("   - Renderização 3D (BVH - Bounding Volume Hierarchy)\n");
    printf("   - Roteamento em redes (trie)\n");
    
    // Liberando memória
    liberarArvore(raiz);
    
    printf("\n=== Fim da Demonstração sobre Árvores ===\n");
    
    return 0;
}