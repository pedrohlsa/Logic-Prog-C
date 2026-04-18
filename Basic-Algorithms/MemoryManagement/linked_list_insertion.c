#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No2
{
    char* dados;
    struct No2* proximo;
} No2;

No2* inserirnoInicio2(No2* lista,  char* texto)
{
    No2* new = (No2*)malloc(sizeof(No2));
    if (new == NULL) return lista;

    new->dados = (char*)malloc(strlen(texto) + 1);

    if (new->dados != NULL)
    {
        strcpy(new->dados, texto);
    }

    new->proximo = lista;
}
#define tam 50
int main() {
    No2* list = NULL;
    char buffer[tam];

    printf("Insira string 1: ");
    fgets(buffer, tam, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    list = inserirnoInicio2(list, buffer);

    printf("Insira string 2: ");
    fgets(buffer, tam, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    list = inserirnoInicio2(list, buffer);

    printf("Insira string 3: ");
    fgets(buffer, tam, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    list = inserirnoInicio2(list, buffer);

    if (list != NULL && list->proximo != NULL) {
        printf("\nTopo (String 3): %s", list->dados);
        printf("\nMeio (String 2): %s", list->proximo->dados);
        printf("\nBottom (String 1): %s", list->proximo->proximo->dados);
    }

    return 0;
}
