#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct No
{
    char *name;
    int id;
    struct No *next;
} No;

No *insertNode(No *list, char *text, int id)
{
    No *newNode = (No *)malloc(sizeof(No));

    newNode->name = (char *)malloc(strlen(text) + 1);
    strcpy(newNode->name, text);
    newNode->id = id;

    newNode->next = list;

    return newNode;
}

No *removeNode(No *list, char *target)
{
    No *current = list;
    No *before = NULL;

    while (current != NULL)
    {
        if (strcmp(current->name, target) == 0)
        {
            if (before == NULL)
            {
                list = current->next;
            }
            else
            {
                before->next = current->next;
            }
            free(current->name);
            free(current);
            return list;
        }
        before = current;
        current = current->next;
    }
    return list;
}

No *reverseList(No *list)
{
    No *prev = NULL;
    No *current = list;
    No *prox = NULL;

    while (current != NULL)
    {
        prox = current->next; 

        current->next = prev;

        prev = current;
        current = prox;
    }

    return prev; 
}

void peeklist(No *list)
{
    if (list == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }
    while (list != NULL)
    {
        printf("[%s | %d] -> ", list->name, list->id);
        list = list->next;
    }
    printf("NULL\n");
}

void freeTotal(No *list)
{
    while (list != NULL)
    {
        No *temp = list->next;
        free(list->name);
        free(list);
        list = temp;
    }
}

int main()
{
    No *minhaLista = NULL;

    minhaLista = insertNode(minhaLista, "Cabelo Ruivo", 1);
    minhaLista = insertNode(minhaLista, "Cabelo Preto", 2);

    printf("Lista antes de remover:\n");
    peeklist(minhaLista);

    minhaLista = reverseList(minhaLista);
    peeklist(minhaLista);

    minhaLista = removeNode(minhaLista, "Cabelo Ruivo");

    printf("\nLista depois de remover:\n");
    peeklist(minhaLista);

    freeTotal(minhaLista);
    return 0;
}
