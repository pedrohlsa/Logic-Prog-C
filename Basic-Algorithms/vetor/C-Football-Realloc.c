#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_STRING 100

typedef struct{
    char CamisaFutebol[TAM_STRING];
    char NomeDaPessoa[TAM_STRING];
    int Numero;
} Vetor;

void limparBufferEntrada(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int inserirVetor(Vetor** v, int* quantidade){
    int novos;
    printf("Digite quantas pessoas deseja inserir: ");
    if(scanf("%d", &novos) != 1) {printf("Digite apenas numeros!"); return 1;}
    limparBufferEntrada();

    int tamanhoAntigo = *quantidade;
    *quantidade += novos;

    *v = (Vetor*)realloc(*v, *quantidade * sizeof(Vetor));

    for(int i = tamanhoAntigo; i < *quantidade; i++){
    printf("\n-------------------------------------------------\n");
    printf("\nCamisa #%d\n", i + 1);
    printf("Insira o nome da camisa do Time:\n");
    fgets((*v)[i].CamisaFutebol, TAM_STRING, stdin);
    (*v)[i].CamisaFutebol[strcspn((*v)[i].CamisaFutebol, "\n")] = '\0';
    
    printf("-------------------------------------------------");
    printf("\nNome #%d\n", i + 1);
    printf("Insira o nome da Pessoa:\n");
    fgets((*v)[i].NomeDaPessoa, TAM_STRING, stdin);
    (*v)[i].NomeDaPessoa[strcspn((*v)[i].NomeDaPessoa, "\n")] = '\0'; 

    printf("-------------------------------------------------");
    printf("\nNumero da Camisa #%d\n", i + 1);
    printf("Insira o numero da Camisa: ");
    scanf("%d", &(*v)[i].Numero);
    limparBufferEntrada();
    }
    printf("\n");
}

int listarVetor(Vetor* v, int quantidade){
    if (v == NULL){
        printf("Lista vazia!\n");
        return 0;
    }
    printf("\nListar Dados!\n");
    for (int i = 0; i < quantidade; i++){
        printf("\n-------------------------------------------------\n");
        printf("[%d] Camisa: %s | Nome: %s | Num: %d\n", i + 1, v[i].CamisaFutebol, v[i].NomeDaPessoa, v[i].Numero);
    }
    return 0;
}

int main(){
    Vetor* list = NULL;
    int op; 
    int t = 0;
    do{
    printf("\n1. Para Inserir.\n2. Para Listar.\n0 Para Sair.\nEscolha: ");
    if(scanf("%d", &op) != 1){
        printf("Erro! Digite um número."); 
        return 1;} 
    limparBufferEntrada();

    switch (op)
    {
    case 1:
         inserirVetor(&list, &t);
        break;
    case 2:
         listarVetor(list, t);
        break;
    case 0:
        if (list != NULL){
            free(list);
            list = NULL;
        }
        printf("Saindo!");
        break;
    }
    } while (op != 0);
}
