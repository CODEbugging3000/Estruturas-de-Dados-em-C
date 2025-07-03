#include <stdio.h>

int main() {
    printf("=== Arrays em C ===\n\n");

    /* ----------------------------
       Arrays Unidimensionais
       ---------------------------- */
    printf("1. Arrays Unidimensionais:\n");
    
    // Declaração de um array de 5 inteiros
    int numeros[5];
    
    // Inicialização manual
    numeros[0] = 10;
    numeros[1] = 20;
    numeros[2] = 30;
    numeros[3] = 40;
    numeros[4] = 50;
    
    // Acesso aos elementos
    printf("   - numeros[2] = %d\n", numeros[2]);
    
    // Declaração com inicialização
    int valores[5] = {1, 2, 3, 4, 5};
    
    // Iteração com for
    printf("   - Valores do array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", valores[i]);
    }
    printf("\n\n");
    
    /* ----------------------------
       Arrays Multidimensionais
       ---------------------------- */
    printf("2. Arrays Multidimensionais:\n");
    
    // Matriz 2x3 (2 linhas, 3 colunas)
    int matriz[2][3] = {
        {1, 2, 3},  // Primeira linha
        {4, 5, 6}   // Segunda linha
    };
    
    // Acesso aos elementos
    printf("   - matriz[0][1] = %d\n", matriz[0][1]);  // Segunda coluna da primeira linha
    printf("   - matriz[1][2] = %d\n\n", matriz[1][2]); // Terceira coluna da segunda linha
    
    // Iteração com for aninhado
    printf("   - Matriz completa:\n");
    for (int i = 0; i < 2; i++) {          // Loop pelas linhas
        printf("     ");
        for (int j = 0; j < 3; j++) {      // Loop pelas colunas
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    /* ----------------------------
       Arrays de Caracteres (Strings)
       ---------------------------- */
    printf("3. Arrays de Caracteres (Strings):\n");
    
    // String como array de caracteres
    char nome[10] = {'J', 'o', 'a', 'o', '\0'};  // '\0' indica fim da string
    char sobrenome[] = "Silva";  // Forma alternativa (o compilador conta os caracteres)
    
    printf("   - Nome: %s\n", nome);
    printf("   - Sobrenome: %s\n\n", sobrenome);
    
    /* ----------------------------
       Arrays e Ponteiros
       ---------------------------- */
    printf("4. Relação entre Arrays e Ponteiros:\n");
    
    int vetor[3] = {10, 20, 30};
    int *ptr = vetor;  // O nome do array é um ponteiro para o primeiro elemento
    
    printf("   - *ptr = %d (vetor[0])\n", *ptr);
    printf("   - *(ptr + 1) = %d (vetor[1])\n", *(ptr + 1));
    printf("   - ptr[2] = %d (vetor[2])\n\n", ptr[2]);
    
    /* ----------------------------
       Exemplo Prático: Matriz de Temperaturas
       ---------------------------- */
    printf("5. Exemplo Prático: Matriz de Temperaturas:\n");
    
    // Matriz para armazenar temperaturas de 3 cidades por 5 dias
    float temperaturas[3][5] = {
        {22.5, 23.0, 24.1, 21.8, 20.5},  // Cidade A
        {18.2, 17.8, 19.0, 18.5, 17.0},  // Cidade B
        {30.2, 31.5, 32.0, 29.8, 30.5}   // Cidade C
    };
    
    // Calculando a média de temperatura por cidade
    for (int cidade = 0; cidade < 3; cidade++) {
        float soma = 0;
        for (int dia = 0; dia < 5; dia++) {
            soma += temperaturas[cidade][dia];
        }
        printf("   - Cidade %d: Média = %.2f°C\n", cidade + 1, soma / 5);
    }
    
    printf("\n=== Fim da Demonstração sobre Arrays ===\n");
    
    return 0;
}