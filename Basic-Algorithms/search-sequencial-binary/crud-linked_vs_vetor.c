#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Ranking{
    char* meuRanking;
    struct Ranking* next;
}Ranking;

Ranking* inserirRank(Ranking* list, const char* text){
    Ranking*r = (Ranking*)malloc(sizeof(Ranking));
    
    r->meuRanking = strdup(text);

    r->next = list;
    return r;
}

int search(Ranking* list, const char* alvo){
    if (list == NULL){
        printf("Lista vazia!\n");
        return -1;
    }
    while(list){
        if(strcmp(list->meuRanking, alvo) == 0){
            printf("%s", list->meuRanking);
        }
        list = list->next;
    }
}

void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

#define TAM_STRING 100

typedef struct{
    char Nome[TAM_STRING];
} Vetor;

int inserirVetor(Vetor **v, int* quantidade);

int buscaBinariaIterativa(Vetor* v, int n, char* alvo){
    int inicio = 0, fim = n -1;

    while(inicio <= fim){
        int meio = (inicio + fim) / 2;
        int comp = strcmp(v[meio].Nome, alvo);
        if (comp == 0) return meio;
        if (comp > 0) fim = meio - 1;
        else inicio = meio + 1;
    }
    return - 1;
}

int buscaBinariaRecursiva(Vetor* v, int inicio, int fim, char* alvo){
    if (inicio > fim){printf("Alvo não encontrado!\n"); return -1;};
    int meio = (inicio + fim) / 2;
    int comp = strcmp(v[meio].Nome, alvo);
    if (comp == 0) return meio;
    if (comp > 0) return buscaBinariaRecursiva(v, inicio, meio - 1, alvo);
    else return buscaBinariaRecursiva(v, meio + 1, fim, alvo);
}

int comparar(const void* a, const void* b){
    Vetor* R1 = (Vetor*)a;
    Vetor* R2 = (Vetor*)b;

    return strcmp(R1->Nome, R2->Nome);
}

Ranking* menuListLinked(Ranking* list){
    int op;
    char buffer[TAM_STRING];
    printf("----------------\n");
    printf("Bem vindo a parte de insercao da lista encadeada!\n");
    printf("Digite quantos nomes deseja inserir: ");
    if(scanf("%d", &op) != 1){printf("Erro! Digite um número válido!\n"); return list;} limparBufferEntrada();
    
    for(int i = 0; i < op; i++){
        printf("\n#%d ", i + 1);
        printf("Nome:\n");
        fgets(buffer, TAM_STRING, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        list = inserirRank(list, buffer);
    }

    return list;
}

int buscarLinked(Ranking* list){
    if(list == NULL){
        printf("Lista vazia!\n");
    }
    char alvo[TAM_STRING];
    clock_t t;

    printf("Digite o alvo que deseja buscar!\n");
    fgets(alvo, TAM_STRING, stdin);
    alvo[strcspn(alvo, "\n")] = '\0';
    
    t = clock();
    search(list, alvo);
    t = clock() - t;
    printf("Lista encadeada demorou: %f s\n", (double)t/CLOCKS_PER_SEC);
}

int inserirVetor(Vetor **v, int* quantidade){
    int novo;
    printf("Vamos inserir o vetor!\n");
    printf("Digite quantos vetores deseja inserir! ");
    if(scanf("%d", &novo) != 1){printf("Erro! Digite um texto!\n"); return 1;}
    limparBufferEntrada();

    int tamanhoAntigo = *quantidade;
    *quantidade += novo;

    *v = (Vetor*)realloc(*v, *quantidade * sizeof(Vetor));

    for (int i = 0; i < *quantidade; i++){
        printf("\n------------\n");
        printf("Vetor: #%d", i + 1);
        printf("Digite oq quer inserir no vetor!\n");
        fgets((*v)[i].Nome, TAM_STRING, stdin);
        (*v)[i].Nome[strcspn((*v)[i].Nome, "\n")] = '\0';
    }

    qsort(*v, *quantidade, sizeof(Vetor), comparar);
}

int buscarVetor(Vetor* v, int quantidade){
    char bufferVetor[TAM_STRING];
    clock_t t;
    printf("Digite o alvo que deseja buscar!\n");
    fgets(bufferVetor, TAM_STRING, stdin);
    bufferVetor[strcspn(bufferVetor, "\n")] = '\0';
    
    int op3;
    printf("Vamos buscar!\n");
    printf("1. Para Binaria Iterativa.\n2. Para Binaria Recursiva!\n");
    if(scanf("%d", &op3) != 1){printf("Erro. Use apenas números porfavor!\n"); return 1;}
    if (op3 == 1){
        t = clock();
        buscaBinariaIterativa(v, quantidade, bufferVetor);
        t = clock() - t;
        printf("Busca Binaria Iterativa demorou: %f s\n", (double)t/CLOCKS_PER_SEC);
    }
    if (op3 == 2){
        t = clock();
        buscaBinariaRecursiva(v, 0, quantidade, bufferVetor);
        t = clock() - t;
        printf("BuscaBinaria Recursiva demorou: %f s\n", (double)t/CLOCKS_PER_SEC);
    }
}

void freeLinked(Ranking* list){
    Ranking* temp = list;
    while(temp != NULL){
        Ranking* proximo = temp->next;
        free(temp->meuRanking);
        free(temp);
        temp = proximo;
    }
}

int main(){ 
    Vetor* v = NULL;
    Ranking* r = NULL;
    int op, op1, op2;
    int t = 0;
    printf("Bem vindo ao T4!\n");
    printf("-------------------------------\n");
    do{
    printf("1. Para Listas Encadeadas!\n2. Para Vetores.\n0. Para Sair!\nEscolha: ");
    if(scanf("%d", &op) != 1){printf("Erro! Digite um número.");return 1;} limparBufferEntrada();
    
    switch (op)
    {
    case 1:
        printf("----------------\n");
        printf("Lista Encadeada.\n");
        printf("1. Para Inserir.\n2. Para buscar o alvo!\nEscolha: ");
        if(scanf("%d", &op1) != 1){printf("Erro! Digite um número."); return 1;} limparBufferEntrada();
        if(op1 == 1){
            r = menuListLinked(r);
        }
        if(op1 == 2){
            buscarLinked(r);
        }
        break;
    case 2:
        printf("----------------\n");
        printf("Vetores.\n");
        printf("1. Para inserir os Vetores!\n2. Para buscar o alvo!");
        if(scanf("%d", &op2) != 1){printf("Erro! Digite um número."); return 1;} limparBufferEntrada();
        
        if(op2 == 1){
            inserirVetor(&v, &t);
        }
        if(op2 == 2){
            buscarVetor(v, t);
        }
        break;
    }
    } while (op != 0);
    
    free(v);
    v = NULL;
    freeLinked(r);
}
