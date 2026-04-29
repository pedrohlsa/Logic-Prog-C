#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamanho 10000

void gerarListaOrdenada(int lista[], int n);
void gerarListaInversa(int lista[], int n);
void gerarListaAleatoria(int lista[], int n);
void bubbleSort(int lista[], int n);
void insertionSort(int lista[], int n);
void selectionSort(int lista[], int n);
void copiarLista(int destino[], const int origem[], int n);

int main(){
    srand(time(NULL));
    clock_t t;

    int *listaOrdenada = malloc(tamanho * sizeof(int));
    int *listaInversa = malloc(tamanho * sizeof(int));
    int *listaAleatoria = malloc(tamanho * sizeof(int));
    int *listaTemp = malloc(tamanho * sizeof(int));

    printf("--- Gerando listas de entrada (%d elementos) ---\n", tamanho);
    gerarListaOrdenada(listaOrdenada, tamanho);
    gerarListaInversa(listaInversa, tamanho);
    gerarListaAleatoria(listaAleatoria, tamanho);
    printf("------------------------------------------------\n\n");

    printf("======== 1. Bubble Sort ========\n");
    
    copiarLista(listaTemp, listaOrdenada, tamanho);
    t = clock();
    bubbleSort(listaTemp, tamanho);
    printf("Melhor caso: %f s\n", (double)(clock() - t) / CLOCKS_PER_SEC);

    copiarLista(listaTemp, listaInversa, tamanho);
    t = clock();
    bubbleSort(listaTemp, tamanho);
    printf("Pior Caso:   %f s\n", (double)(clock() - t) / CLOCKS_PER_SEC);

    copiarLista(listaTemp, listaAleatoria, tamanho);
    t = clock();
    bubbleSort(listaTemp, tamanho);
    printf("Caso medio:  %f s\n\n", (double)(clock() - t) / CLOCKS_PER_SEC);

    printf("======== 2. Insertion Sort ========\n");
    
    copiarLista(listaTemp, listaOrdenada, tamanho);
    t = clock();
    insertionSort(listaTemp, tamanho);
    printf("Melhor caso: %f s\n", (double)(clock() - t) / CLOCKS_PER_SEC);

    copiarLista(listaTemp, listaInversa, tamanho);
    t = clock();
    insertionSort(listaTemp, tamanho);
    printf("Pior Caso:   %f s\n", (double)(clock() - t) / CLOCKS_PER_SEC);

    copiarLista(listaTemp, listaAleatoria, tamanho);
    t = clock();
    insertionSort(listaTemp, tamanho);
    printf("Caso medio:  %f s\n\n", (double)(clock() - t) / CLOCKS_PER_SEC);

    printf("======== 3. Selection Sort ========\n");
    
    copiarLista(listaTemp, listaOrdenada, tamanho);
    t = clock();
    selectionSort(listaTemp, tamanho);
    printf("Melhor caso: %f s\n", (double)(clock() - t) / CLOCKS_PER_SEC);

    copiarLista(listaTemp, listaInversa, tamanho);
    t = clock();
    selectionSort(listaTemp, tamanho);
    printf("Pior Caso:   %f s\n", (double)(clock() - t) / CLOCKS_PER_SEC);

    copiarLista(listaTemp, listaAleatoria, tamanho);
    t = clock();
    selectionSort(listaTemp, tamanho);
    printf("Caso medio:  %f s\n", (double)(clock() - t) / CLOCKS_PER_SEC);

    free(listaOrdenada);
    free(listaInversa);
    free(listaAleatoria);
    free(listaTemp);

    return 0;
}


void copiarLista(int destino[], const int origem[], int n){
    for (int i = 0; i < n; i++) destino[i] = origem[i];
}

void gerarListaOrdenada(int lista[], int n){
    for (int i = 0; i < n; i++) lista[i] = i;
}

void gerarListaInversa(int lista[], int n){
    for (int i = 0; i < n; i++) lista[i] = n - i;
}

void gerarListaAleatoria(int lista[], int n){
    for (int i = 0; i < n; i++) lista[i] = rand() % 10000;
}

void bubbleSort(int lista[], int n){
    int i, j, temp, trocou;
    for(i = 0; i < n - 1; i++){
        trocou = 0;
        for(j = 0; j < n - i - 1; j++){
            if (lista[j] > lista[j + 1]){
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
                trocou = 1;
            }
        }
        if (trocou == 0) break;
    }
}

void insertionSort(int lista[], int n){
    int i, chave, j;
    for (i = 1; i < n; i++){
        chave = lista[i];
        j = i - 1;
        while (j >= 0 && lista[j] > chave){
            lista[j + 1] = lista[j];
            j = j - 1;
        }
        lista[j + 1] = chave;
    }
}

void selectionSort(int lista[], int n){
    int i, j, indice_min, temp;
    for(i = 0; i < n - 1; i++){
        indice_min = i;
        for (j = i + 1; j < n; j++){
            if(lista[j] < lista[indice_min]) indice_min = j;
        }
        if (indice_min != i){
            temp = lista[i];
            lista[i] = lista[indice_min];
            lista[indice_min] = temp;
        }
    }
}
