#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
    int itens[MAX];
    int total;
} Conjunto;

void cleanBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void insertSujo(Conjunto* s){
    int qty, num;
    printf("Quantos numeros quer inserir?");
    scanf("%d", &qty);

    for( int i = 0; i < qty; i++){
        if(s->total < MAX){
            printf("Digite o numero %d: ", i + 1);
            scanf("%d", &num);
            s->itens[s->total] = num;
            s->total++;
        } else{
            printf("[!] Limite Atingido!");
        }
    }
    cleanBuffer();
}

void limpar(Conjunto *sujo, Conjunto *limpo){
    for(int i = 0; i < sujo->total; i++){
        int repetido = 0;
        int valorAtual = sujo->itens[i];

        for(int j = 0; j < limpo->total; j++){
            if(limpo->itens[j] == valorAtual){
            repetido = 1;
            break;
            }
        }
        if(!repetido && limpo->total < MAX){
            limpo->itens[limpo->total] = valorAtual;
            limpo->total++; 
        }
    }
}

void mostrar(Conjunto c, char* nome) {
    printf("%s: ", nome);
    for (int i = 0; i < c.total; i++) {
        printf("[%d] ", c.itens[i]);
    }
    printf("\n");
}

int main() {
    Conjunto listaSuja = {.total = 0};
    Conjunto listaLimpa = {.total = 0};

    insertSujo(&listaSuja);
    
    printf("\nProcessando limpeza (removendo duplicatas)...\n");
    limpar(&listaSuja, &listaLimpa);

    mostrar(listaSuja, "Sujo (Original)");
    mostrar(listaLimpa, "Limpo (Sem repetidos)");

    return 0;
}
