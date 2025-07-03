#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("=== Fundamentos da Linguagem C ===\n\n");

    /* ----------------------------
       Tipos de Dados Primitivos em C
       ---------------------------- */
    printf("1. Tipos de Dados Primitivos:\n");
    
    int inteiro = 10;                     // Inteiro (geralmente 4 bytes)
    char caractere = 'A';                 // Caractere (1 byte)
    float pontoFlutuante = 3.14159f;      // Ponto flutuante de precisão simples (4 bytes)
    double duplaPrecisao = 2.718281828;   // Ponto flutuante de dupla precisão (8 bytes)
    short int curto = 32767;              // Inteiro curto (2 bytes)
    long int longo = 2147483647L;         // Inteiro longo (4 ou 8 bytes)
    unsigned int semSinal = 40000;        // Inteiro sem sinal (só valores positivos)
    
    printf("   - int: %d, char: %c, float: %.2f, double: %.4lf\n", inteiro, caractere, pontoFlutuante, duplaPrecisao);
    printf("   - short: %hd, long: %ld, unsigned: %u\n\n", curto, longo, semSinal);

    /* ----------------------------
       Ponteiros
       ---------------------------- */
    printf("2. Ponteiros:\n");
    
    int valor = 42;
    int *ponteiro = &valor;  // Declaração e atribuição de endereço
    
    printf("   - Endereço de 'valor': %p\n", (void*)&valor);
    printf("   - Valor de 'ponteiro': %p\n", (void*)ponteiro);
    printf("   - Dereferenciamento: *ponteiro = %d\n", *ponteiro);
    
    // Aritmética de ponteiros
    int array[3] = {10, 20, 30};
    int *ptr = array;
    
    printf("\n   Aritmética de ponteiros:\n");
    printf("   - ptr[0] = %d (ou *ptr)\n", *ptr);
    ptr++;  // Avança para o próximo elemento
    printf("   - ptr[1] = %d (ou *(ptr))\n", *ptr);
    ptr++;
    printf("   - ptr[2] = %d (ou *(ptr + 1))\n\n", *ptr);

    /* ----------------------------
       Alocação de Memória
       ---------------------------- */
    printf("3. Alocação de Memória:\n");
    
    // Alocação estática vs dinâmica
    int estatico[5];  // Alocado na pilha (stack)
    
    // Alocação dinâmica (heap)
    int *dinamico = (int*)malloc(5 * sizeof(int));
    if (dinamico == NULL) {
        printf("   - Falha na alocação de memória!\n");
        return 1;
    }
    
    // Inicializa memória alocada com malloc (contém lixo)
    printf("   - Memória alocada com malloc (valores não inicializados):\n");
    for (int i = 0; i < 5; i++) {
        printf("     dinamico[%d] = %d\n", i, dinamico[i]);
    }
    
    // Alocação com calloc (inicializa com zero)
    int *inicializado = (int*)calloc(5, sizeof(int));
    printf("\n   - Memória alocada com calloc (inicializada com zero):\n");
    for (int i = 0; i < 5; i++) {
        printf("     inicializado[%d] = %d\n", i, inicializado[i]);
    }
    
    // Realocação de memória
    dinamico = (int*)realloc(dinamico, 10 * sizeof(int));
    printf("\n   - Memória realocada para 10 inteiros\n");
    
    // Liberação de memória
    free(dinamico);
    free(inicializado);
    printf("   - Memória liberada com free()\n\n");

    /* ----------------------------
       Estruturas (struct)
       ---------------------------- */
    printf("4. Estruturas (struct):\n");
    
    // Definição de uma estrutura
    struct Pessoa {
        char nome[50];
        int idade;
        float altura;
    };
    
    // Declaração e inicialização
    struct Pessoa pessoa1 = {"João Silva", 30, 1.75f};
    
    // Acesso aos membros
    printf("   - Pessoa: %s, %d anos, %.2f metros\n", pessoa1.nome, pessoa1.idade, pessoa1.altura);
    
    // Array de estruturas
    struct Pessoa equipe[3] = {
        {"Maria Souza", 28, 1.68f},
        {"Carlos Lima", 35, 1.80f},
        {"Ana Costa", 25, 1.72f}
    };
    
    printf("\n   Array de estruturas:\n");
    for (int i = 0; i < 3; i++) {
        printf("   - %s: %d anos\n", equipe[i].nome, equipe[i].idade);
    }
    
    // Estruturas com ponteiros
    struct Pessoa *ptrPessoa = &pessoa1;
    printf("\n   Acesso com ponteiro:\n");
    printf("   - Nome via ponteiro: %s\n", ptrPessoa->nome);  // Equivalente a (*ptrPessoa).nome

    /* ----------------------------
       Assuntos Extras
       ---------------------------- */
    printf("\n5. Assuntos Extras:\n");
    
    // Enumerações
    enum DiasSemana { DOM, SEG, TER, QUA, QUI, SEX, SAB };
    printf("   - Enum: Terça-feira é o dia %d\n", TER);
    
    // Typedef para criar aliases
    typedef unsigned long int ulint;
    ulint grandeNumero = 123456789012345;
    printf("   - Typedef: ulint = %lu\n", grandeNumero);
    
    printf("\n=== Preparado para aprender Algoritmos e Estruturas de Dados! ===\n");
    
    return 0;
}