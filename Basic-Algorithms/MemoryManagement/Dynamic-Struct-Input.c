#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MAX 50

void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
typedef struct 
{
    char nome[MAX];
    char produto[MAX];
    int quantidade;
} Pessoa;

int main()
{
    Pessoa* p = (Pessoa*) malloc(sizeof (Pessoa));
    if (p == NULL) return 1;

    printf("Digite o Nome: \n");
    fgets(p->nome, MAX, stdin);

    printf("Produto comprado: \n");
    fgets(p->produto, MAX, stdin);

    p->nome[strcspn (p->nome, "\n")] = '\0';
    p->produto[strcspn (p->produto, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &p->quantidade);
    limparBufferEntrada();

    printf("%s comprou %s\n", p-> nome, p->produto);
    printf("Na quantia de: %d unidades.\n", p->quantidade);

    free(p);
    return 0;
} 
