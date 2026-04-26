#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Ranking{
    char* nomeRanking;
    struct Ranking* next;
}Ranking;

Ranking* insertRanking(Ranking* list, const char* nome){
    Ranking* noq = (Ranking*)malloc(sizeof(Ranking));
    if (noq == NULL) return list;

    noq->nomeRanking = (char*)malloc(strlen(nome) + 1);
    strcpy(noq->nomeRanking, nome);

    noq->next = list;
    return noq;
}

int search(Ranking* list, char* alvo){
    int pos = 0;
    while (list){
        if(strcmp(list->nomeRanking, alvo) == 0) return pos;
        list = list->next;
        pos++;
    }
    return - 1;
}

#define nj 100
typedef struct{
    char nome[nj];
}ElementoVetor;

int buscaBinariaIterativa(ElementoVetor* v, int n, char* alvo){
    int inicio = 0, fim = n -1;
    while (inicio <= fim){
        int meio = (inicio + fim) / 2;
        int comp = strcmp(alvo, v[meio].nome);
        if (comp == 0) return meio;
        if (comp > 0) inicio = meio + 1;
        else fim = meio - 1;
    }   
 return -1;
}

int buscaBinariaRecursiva(ElementoVetor* v, int inicio, int fim, char* alvo){
    if (inicio > fim) return - 1; 
    
    int meio = (inicio + fim) / 2;
    int comp = strcmp(alvo, v[meio].nome);
    if (comp == 0) return meio;
    if (comp > 0) return buscaBinariaRecursiva (v, meio + 1, fim, alvo);
    else return buscaBinariaRecursiva (v, inicio, meio - 1, alvo);
}

int comparar(const void* a, const void* b){
    ElementoVetor* R1 = (ElementoVetor*)a;
    ElementoVetor* R2 = (ElementoVetor*)b;

    return strcmp(R1->nome, R2->nome);
}

void liberar(Ranking* list){
    Ranking* atual = list;
    while (atual != NULL){
        Ranking* proximo = atual->next;
        free(atual->nomeRanking);
        free(atual);
        atual = proximo;
    }
}

int main(){
    Ranking* meuRanking = NULL;
    char alvo[nj] = "Pimbada";
    clock_t t;

    meuRanking = insertRanking(meuRanking, "Jambres");
    meuRanking = insertRanking(meuRanking, "Snow");
    meuRanking = insertRanking(meuRanking, "Chair");
    meuRanking = insertRanking(meuRanking, "Camiseta");
    meuRanking = insertRanking(meuRanking, "Pimbada");

    int n = 0;
    Ranking* temp = meuRanking;
    while (temp != NULL){
        n++; temp = temp->next;
    }

    ElementoVetor* v = (ElementoVetor*)malloc(n * sizeof(ElementoVetor));

    temp = meuRanking;
    for(int i = 0; i < n; i++){
        strcpy(v[i].nome, temp->nomeRanking);
        temp = temp->next; // esqueci disso aq
    }

    qsort(v, n, sizeof(*v), comparar); 

    t = clock();
    search(meuRanking, alvo);
    t = clock() - t;
    printf("Search tempo: %f s\n", (double)t/CLOCKS_PER_SEC);

    t = clock();
    buscaBinariaIterativa(v, n, alvo);
    t = clock() - t;
    printf("BuscaBinariaIterativa: %f s\n", (double)t/CLOCKS_PER_SEC);

    t = clock();
    buscaBinariaRecursiva(v, 0, n - 1, alvo);
    t = clock() - t;
    printf("BuscaBinariaRecursiva: %f s\n", (double)t/CLOCKS_PER_SEC);
    
    liberar(meuRanking);
    free(v);
    return 0;
}
