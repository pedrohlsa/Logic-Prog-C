#include <stdio.h>

int buscaBinaria(int vetor[], int tamanho, int valor)
{
    int inicio = 0;
    int fim = tamanho - 1;
    
    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] == valor)
        {
            return meio;
        } 
        else if (vetor[meio] < valor)
        {
            inicio = meio + 1;
        }
        else 
        {
            fim = meio - 1;
        }
    }
    return -1;
} 

int main()
{
    // o que é uma busca binaria ? Algoritmo de busca que funciona em dados ordenados
    // Pelo principio da divisao, comparara com o elemento do meio e descarta metade da lista a cada passo
    // ESTRITAMENTE E OBRIGATORIAMENTE necessario os dados estarem ordenados!
    // desempenho para nanos segundos
}
