#include <stdio.h>


void trocar(int* a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                trocar(&vetor[j], &vetor[j + 1]);
            }
        }
    }
} 



// bubble sort 
/*maiores elementos flutuam pro final da lista
Dificilmente utilizado
Lacos aninhados
Comparacoes entre vizinhos
Trocas graduais
*/

