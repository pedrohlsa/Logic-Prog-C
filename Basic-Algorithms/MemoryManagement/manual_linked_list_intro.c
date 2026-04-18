#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
    int quantia;
    struct No* proximo;
} No;

int main()
{
    No* no1 = (No*)malloc(sizeof(No));
    No* no2 = (No*)malloc(sizeof(No));
    No* no3 = (No*)malloc(sizeof(No));

    no1->quantia = 10;
    no2->quantia = 20;
    no3->quantia = 30;

    no1->proximo = no2;
    no2->proximo = no3; 
    no3->proximo = NULL;
    

    No* atual = no1;

    while (atual != NULL)
    {
        printf("\nDado Encontrado:\n%d", atual->quantia);
        atual = atual->proximo;
    }
    free (no1); free (no2); free (no3);

}
