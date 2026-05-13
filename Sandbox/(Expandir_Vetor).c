#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOME 50

typedef struct {
    int id;
    char* nome;
} Cabelo;

/**
 * Adiciona novos elementos ao array dinâmico de Cabelos.
 * Usa realloc para expandir o array e malloc para as strings internas.
 */
void inserirCabelo(Cabelo **c, int *quantidadeTotal) {
    int novos;

    printf("\nQuantos itens deseja adicionar? ");
    if (scanf("%d", &novos) != 1) return;
    getchar(); // Limpa o '\n' do buffer

    int antigoTamanho = *quantidadeTotal;
    *quantidadeTotal += novos;

    // Redimensiona o bloco de structs
    Cabelo *temp = (Cabelo*)realloc(*c, (*quantidadeTotal) * sizeof(Cabelo));
    
    if (temp == NULL) {
        printf("Erro fatal: Falha na alocacao de memoria (realloc).\n");
        exit(1);
    }
    *c = temp;

    // Preenche os novos slots
    for (int i = antigoTamanho; i < *quantidadeTotal; i++) {
        printf("\n--- Registro #%d ---\n", i + 1);
        
        printf("ID: ");
        scanf("%d", &(*c)[i].id);
        getchar(); // Limpa o buffer antes do fgets

        // Aloca memoria para a string dentro da struct
        (*c)[i].nome = (char*)malloc(MAX_NOME * sizeof(char)); 
        if ((*c)[i].nome == NULL) exit(1);

        printf("Nome do estilo: ");
        fgets((*c)[i].nome, MAX_NOME, stdin);
        
        // Remove a quebra de linha salva pelo fgets
        (*c)[i].nome[strcspn((*c)[i].nome, "\n")] = '\0';

        printf("Item cadastrado com sucesso!\n");
    }
}

/**
 * Libera toda a memoria alocada: primeiro as strings internas, 
 * depois o array de structs.
 */
void liberarMemoria(Cabelo **c, int *quantidade) {
    if (*c == NULL) return;
    
    printf("\nIniciando limpeza de memoria...\n");

    for (int i = 0; i < *quantidade; i++) {
        if ((*c)[i].nome != NULL) {
            free((*c)[i].nome);
            (*c)[i].nome = NULL;
        }
    }
    
    free(*c);
    *c = NULL;
    *quantidade = 0;

    printf("Memoria totalmente liberada. Encerrando programa.\n");
}

int main() {
    Cabelo* listaCabelos = NULL;
    int totalRegistros = 0;

    inserirCabelo(&listaCabelos, &totalRegistros);
    
    // Aqui você poderia listar os itens antes de fechar
    printf("\nTotal de itens no sistema: %d\n", totalRegistros);

    liberarMemoria(&listaCabelos, &totalRegistros);
    
    return 0;
}
