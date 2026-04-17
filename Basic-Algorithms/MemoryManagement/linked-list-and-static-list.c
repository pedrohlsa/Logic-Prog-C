#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 10 
#define TAM_STRING 50

void limpaBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


typedef struct {
    char dado[TAM_MAX][TAM_STRING];
    int quantidade;
} ListaEstatica;

void inicializarListaEstatica(ListaEstatica *lista) {
    lista->quantidade = 0;
}

void inserirListaEstatica(ListaEstatica *lista, const char* texto) {
    if (lista->quantidade >= TAM_MAX) {
        printf("Erro: Lista cheia!\n");
        return;
    }
    strncpy(lista->dado[lista->quantidade], texto, TAM_STRING - 1);
    lista->dado[lista->quantidade][TAM_STRING - 1] = '\0';
    lista->quantidade++;
}

void removerListaEstatica(ListaEstatica *lista, const char* texto) {
    int pos = -1;
    if (lista->quantidade <= 0) {
        printf("Lista vazia!\n");
        return;
    }

    for (int i = 0; i < lista->quantidade; i++) {
        if (strcmp(lista->dado[i], texto) == 0) {
            pos = i;
            break; // Achou, sai do loop
        }
    }

    if (pos != -1) {
        for (int i = pos; i < lista->quantidade - 1; i++) {
            strcpy(lista->dado[i], lista->dado[i + 1]);
        }
        lista->quantidade--;
        printf("Removido com sucesso!\n");
    } else {
        printf("Texto nao encontrado.\n");
    }
}

void listarListaEstatica(ListaEstatica *lista) {
    if (lista->quantidade == 0) printf("Lista vazia.\n");
    for (int i = 0; i < lista->quantidade; i++) {
        printf("[%d] %s\n", i, lista->dado[i]);
    }
}

typedef struct No {
    char* dado;
    struct No* proximo;
} No;

typedef No* ListaEncadeada;

void inicializarListaEncadeada(ListaEncadeada* lista) {
    *lista = NULL; // 
}

void inserirListaEncadeada(ListaEncadeada* lista, const char* texto) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (!novoNo) return;

    novoNo->dado = (char*)malloc(strlen(texto) + 1);
    strcpy(novoNo->dado, texto);

    novoNo->proximo = *lista;
    *lista = novoNo;
}

void removerListaEncadeada(ListaEncadeada* lista, const char* texto) {
    No* atual = *lista;
    No* anterior = NULL;


    while (atual != NULL && strcmp(atual->dado, texto) != 0) 
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Texto nao encontrado.\n");
        return;
    }

    if (anterior == NULL) {
        *lista = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual->dado);
    free(atual);
    printf("Removido com sucesso!\n");
}

void listarListaEncadeada(ListaEncadeada* lista) {
    No* atual = *lista;
    if (atual == NULL) printf("Lista vazia.\n");
    while (atual != NULL) {
        printf("%s -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

void liberarListaEncadeada(ListaEncadeada* lista) {
    No* atual = *lista;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual->dado);
        free(atual);
        atual = proximo;
    }
    *lista = NULL;
}

// --- MENUS ---

void menuListaEstatica() {
    ListaEstatica minhalista;
    inicializarListaEstatica(&minhalista); 
    int op;
    char buffer[TAM_STRING];

    do {
        printf("\n--- MENU ESTATICA ---\n1.Inserir\n2.Remover\n3.Listar\n0.Voltar\nEscolha: ");
        scanf("%d", &op);
        limpaBufferEntrada();

        if (op == 1) {
            printf("Texto: "); 
            fgets(buffer, TAM_STRING, stdin);
            buffer[strcspn(buffer, "\n")] = 0; 
            inserirListaEstatica(&minhalista, buffer); 
        } else if (op == 2) { 
            printf("Texto para remover: ");
            fgets(buffer, TAM_STRING, stdin);
            buffer[strcspn(buffer, "\n")] = 0;
            removerListaEstatica(&minhalista, buffer);
        } else if (op == 3) {
            listarListaEstatica(&minhalista);
        }
    } while (op != 0);
}

void menuListaEncadeada() {
    ListaEncadeada minhalista;
    inicializarListaEncadeada(&minhalista);
    int op;
    char buffer[TAM_STRING];

    do {
        printf("\n--- MENU ENCADEADA ---\n1.Inserir\n2.Remover\n3.Listar\n0.Voltar\nEscolha: ");
        scanf("%d", &op);
        limpaBufferEntrada();

        if (op == 1) {
            printf("Texto: "); 
            fgets(buffer, TAM_STRING, stdin);
            buffer[strcspn(buffer, "\n")] = 0; 
            inserirListaEncadeada(&minhalista, buffer); 
        } else if (op == 2) { 
            printf("Texto para remover: ");
            fgets(buffer, TAM_STRING, stdin);
            buffer[strcspn(buffer, "\n")] = 0;
            removerListaEncadeada(&minhalista, buffer);
        } else if (op == 3) {
            listarListaEncadeada(&minhalista);
        }
    } while (op != 0);
    
    liberarListaEncadeada(&minhalista); 
}

int main() {
    int op;
    do {
        printf("\n==== SISTEMA DE LISTAS ====\n");
        printf("1. Lista Estatica\n2. Lista Encadeada\n0. Sair\nEscolha: ");
        scanf("%d", &op);
        limpaBufferEntrada();

        switch (op) {
            case 1: menuListaEstatica(); break;
            case 2: menuListaEncadeada(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n"); break;
        }
    } while (op != 0);

    return 0;
}
