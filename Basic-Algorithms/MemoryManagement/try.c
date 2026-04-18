#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 50

typedef struct No {
    char* dados;
    struct No* proximo;
} No;

No* inserirNo(No* list, char* texto) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dados = (char*)malloc(strlen(texto) + 1);

    if (novo->dados != NULL) {
        strcpy(novo->dados, texto);
    }
    novo->proximo = list;
    return novo;
}

void listarNo(No* list) {
    No* atual = list;
    while (atual != NULL) {
        printf("\nTexto: %s", atual->dados);
        atual = atual->proximo;
    }
    printf("\n");
}


No* limparNo(No* list, char* text) {
    No* anterior = NULL;
    No* atual = list;

   
    while (atual != NULL && strcmp(atual->dados, text) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }


    if (atual == NULL) {
        printf("Dado nao encontrado!\n");
        return list;
    }


    if (anterior == NULL) {
        list = atual->proximo;
    } else {
      
        anterior->proximo = atual->proximo;
    }

    free(atual->dados);
    free(atual);
    printf("No Removido com sucesso!\n");

    return list;
}

int main() {
    No* list = NULL;
    char buffer[tam];

    for (int i = 0; i < 2; i++) {
        printf("Insira sua string: ");
        fgets(buffer, tam, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        list = inserirNo(list, buffer);
    }

    printf("\nLista antes da exclusao:");
    listarNo(list);

    printf("\nEscreva qual dado voce quer excluir: ");
    fgets(buffer, tam, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    
    list = limparNo(list, buffer);

    printf("\nLista depois da exclusao:");
    listarNo(list);

    
    return 0;
}
