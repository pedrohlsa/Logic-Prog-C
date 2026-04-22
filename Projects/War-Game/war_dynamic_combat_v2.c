#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_TAM 100

typedef struct Territorio
{   
    char* nomeTerritorio;
    char* tropas;
    char* tipos;
    int quantias;
    struct Territorio* proximo;
} Territorio;


Territorio* inserirTerritorio(Territorio* list, const char* nomeTer, const char* nomeTro, const char* tipoTro, int numbers)
{
    Territorio* newT = (Territorio*)malloc(sizeof(Territorio));
    if (newT == NULL) return list;

    newT->nomeTerritorio = (char*)malloc(strlen(nomeTer) + 1);
    strcpy(newT->nomeTerritorio, nomeTer);

    newT->tropas = (char*)malloc(strlen(tipoTro) + 1);
    strcpy(newT->tropas, tipoTro);

    newT->tipos = (char*)malloc(strlen(tipoTro) + 1);
    strcpy(newT->tipos, tipoTro);

    newT->quantias = numbers;
    newT->proximo = list;
    
    return newT;
}

Territorio* removerTerritorio(Territorio* list, char* text)
{
    Territorio* current = list;
    Territorio* before = NULL;

    while (current != NULL && strcmp(current->tropas, text) != 0)
    {
        before = current;
        current = current->proximo;
    }

    if (current == NULL)
    {
        printf("\nTerritorio [%s] nao encontrado!\n", text);
        return list;
    }

    if (before == NULL) 
    {
        list = current->proximo;
    } 
    else 
    {
        before->proximo = current->proximo;
    }

    free(current->nomeTerritorio);
    free(current->tropas);
    free(current->tipos);
    free(current);
    printf("\nTerritorio removido com sucesso!\n");
    return list;
}

void freeTotal(Territorio* list)
{
    Territorio* atual = list;
    while (atual != NULL)
    {   
        Territorio* prox = atual->proximo;
        free(atual->nomeTerritorio);
        free(atual->tropas);
        free(atual->tipos);
        free(atual);
        atual = prox;
    }
}

void listarTerritorios(Territorio* list)
{
    Territorio* head = list;

    if (head == NULL)
    {
        printf("\nNenhum territorio encontrado!\n");
        return;
    }

    printf("\n--- LISTA DE TERRITORIOS ---\n");
    while (head != NULL)
    {   
        printf("Nome do territorio: %s | ", head->nomeTerritorio);
        printf("Nome da tropa: %-15s | Tipo da tropa: %-15s | Quantidade: %d\n", head->tropas, head->tipos, head->quantias);
        head = head->proximo;
    }
    printf("----------------------------\n");
}


void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Territorio* buscarterritorio(Territorio* list, char* nome)
{
    Territorio* atual = list;
    while (atual != NULL)
    {
        if(strcmp(atual->nomeTerritorio,nome) == 0)
        {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void realizarBatalha(Territorio* list)
{
    char nomeAtacante[BUFFER_TAM], nomeDefensor[BUFFER_TAM];

    printf("Digite o territorio que vai atacar: ");
    fgets(nomeAtacante, BUFFER_TAM, stdin);
    nomeAtacante[strcspn(nomeAtacante, "\n")] = '\0';

    printf("Digite o territorio que vai defender: ");
    fgets(nomeDefensor, BUFFER_TAM, stdin);
    nomeDefensor[strcspn(nomeDefensor, "\n")] = '\0';

    Territorio* atacante = buscarterritorio(list, nomeAtacante);
    Territorio* defensor = buscarterritorio(list, nomeDefensor);
    
    if(atacante == NULL || defensor == NULL)
    {
        printf("Erro: Um dos territorios nao foi encontrado!");
        return;
    } 
    printf("----Conflito %s vs %s ----\n", atacante->nomeTerritorio, defensor->nomeTerritorio);

    if (atacante->quantias > defensor->quantias)
    {
        printf("O atacante %s venceu!", atacante->nomeTerritorio);
    } else 
    {
        printf("O defensor %s venceu!", defensor->nomeTerritorio);
    }
}
void menuJogo()
{
    Territorio* list = NULL;
    int op;
    
    do {
        printf("\n1. Inserir tropas\n2. Remover tropas\n3. Listar tropas\n4. Batalhar\n0. Sair do Menu\nOpcao: ");
        if (scanf("%d", &op) != 1) {
            limparBufferEntrada();
            continue;
        }
        limparBufferEntrada();
        
        switch (op)
        {
            case 1: {
                int qnt_novos;
                printf("Quantos territorios deseja criar? ");
                scanf("%d", &qnt_novos);
                limparBufferEntrada();
               
                for (int i = 0; i < qnt_novos; i++)
                {   
                    char nomeTer[BUFFER_TAM], nomeTro[BUFFER_TAM], tipoTro[BUFFER_TAM];
                    int q_tropas;
                    printf("\nNome do territorio: : ", i + 1);
                    fgets(nomeTer, BUFFER_TAM, stdin);
                    nomeTer[strcspn(nomeTer, "\n")] = '\0';

                    printf("\nNome da tropa: ", i + 1);
                    fgets(nomeTro, BUFFER_TAM, stdin);
                    nomeTro[strcspn(nomeTro, "\n")] = '\0';

                    printf("\nTipo da tropa: ", i + 1);
                    fgets(tipoTro, BUFFER_TAM, stdin);
                    tipoTro[strcspn(tipoTro, "\n")] = '\0';

                    printf("Quantidade de tropas: ");
                    scanf("%d", &q_tropas);
                    limparBufferEntrada(); 

                    list = inserirTerritorio(list, nomeTer, nomeTro, tipoTro, q_tropas);
                }
                printf("\nTerritorios inseridos!\n");
                break;
            }
            case 2:
                char buffer[BUFFER_TAM];
                printf("Nome do territorio para remover: ");
                fgets(buffer, BUFFER_TAM, stdin);
                buffer[strcspn(buffer, "\n")] = '\0';
                list = removerTerritorio(list, buffer);
                break;
            case 3:
                listarTerritorios(list);
                break;
            case 4:
                if (list == NULL) 
                {
                    printf("Adicione tropas para poder jogar!");
                }else
                {
                    realizarBatalha(list);
                }
                break;
            case 0: 
                freeTotal(list);
                printf("Limpando dados e voltando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        } 
    } while (op != 4);
}

int main()
{
    int op;

    do {
        printf("\n=== GUERRA (WAR) ===\n");
        printf("1. Gerenciar Tropas/Batalhar\n0. Sair\nOpcao: ");
        scanf("%d", &op);
        limparBufferEntrada();

        switch (op)
        {
            case 1:
                menuJogo();       
                break;
            case 0:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (op != 0);

    return 0;
}
