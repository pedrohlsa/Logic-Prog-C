#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[30];
    int idade;
} Pessoa;

#define MAX 5

typedef struct{
    Pessoa itens[MAX];
    int inicio;
    int fim;
    int total;
} Fila;

void inicializarFila(Fila *f){
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

int filaCheia(Fila *f){
    return f->total == MAX;
}

int filaVazia(Fila* f){
    return f->total == 0;
}


// queue
void inserir(Fila *f, Pessoa p){
    if(f->total == MAX){
        printf("Fila cheia.");
        return;
    }

    f->itens[f->fim] = p; // avisa ao array onde guardar
    f->fim = (f->fim + 1) % MAX; // avisa ao array q agora o final é um dps desse
    f->total++; // avisa ao array que mais um espaco foi utilizado
} 

// dequeue
void remover(Fila *f, Pessoa *p){
    if(filaVazia(f)){
        printf("Fila vazia.");
        return;
    }

    *p = f->itens[f->inicio]; // aponta para o comeco da fila
    f->inicio = (f->inicio + 1) % MAX; // passa para o proximo
    f->total--; // diminui um
}

// peek
void mostrarFila(Fila *f){
    printf("Fila: ");
    for (int i = 0, idx = f->inicio; // inicio
        i < f->total; // enquanto for menor q o maximo
        i++, idx = (idx + 1) % MAX) /* vai fazendo a logica circular */{
        printf("[%s | %d]",f->itens[idx].nome, f->itens[idx].idade);
    }
    printf("\n");
}

int main(){
    Fila f;
    inicializarFila(&f); // inicializa a fila
    // inserindo na fila 
    Pessoa p1 = {"João, 25"};
    Pessoa p2 = {"Maria, 30"};

    inserir(&f, p1);
    inserir(&f, p2);
    mostrarFila(&f); // fila antes da remocao

    Pessoa removida; // so armazenar
    remover(&f, &removida);
    printf("Pessoa removida: %s | %d\n", removida.nome, removida.idade); // joao primeiro a ser removido
    mostrarfila(&f);
    return 0;
}
