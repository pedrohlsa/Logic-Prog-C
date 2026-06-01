#include <stdio.h>
#include <stdlib.h> 

void encontrar(int array[], int tamanho, int* maior, int* menor) {
    *maior = array[0];
    *menor = array[0];
    
    for (int i = 1; i < tamanho; i++) {
        if (array[i] > *maior) 
            *maior = array[i];
        if (array[i] < *menor) 
            *menor = array[i];
    }
}

int main() {
    int qtd;
    
    printf("Quantos numeros voce quer inserir? ");
    scanf("%d", &qtd);

    int *array = (int *) malloc(qtd * sizeof(int));

    if (array == NULL) {
        printf("Erro: Memoria cheia!\n");
        return 1; 
    }

    for (int i = 0; i < qtd; i++) {
        printf("Insira o num #%d: ", i + 1);
        scanf("%d", &array[i]);
    }

    int maior, menor;
    encontrar(array, qtd, &maior, &menor);

    printf("\n=========================================\n");
    printf("O MAIOR numero é: %d\n", maior);
    printf("O MENOR numero é: %d\n", menor);
    printf("=========================================\n");

    free(array); 

    return 0;
}
