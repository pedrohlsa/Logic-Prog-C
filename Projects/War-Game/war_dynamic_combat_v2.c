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



void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Territorio* inserirTerritorio(Territorio* list, const char* nomeTer, const char* nomeTro, const char* tipoTro, int numbers)
{
    Territorio* newT = (Territorio*)malloc(sizeof(Territorio));
    if (newT == NULL) return list;

    newT->nomeTerritorio = (char*)malloc(strlen(nomeTer) + 1);
    strcpy(newT->nomeTerritorio, nomeTer);

    newT->tropas = (char*)malloc(strlen(nomeTro) + 1);
    strcpy(newT->tropas, nomeTro);

    newT->tipos = (char*)malloc(strlen(tipoTro) + 1);
    strcpy(newT->tipos, tipoTro);

    newT->quantias = numbers;
    newT->proximo = list;
    
    return newT;
}

Territorio* buscarterritorio(Territorio* list, const char* nome)
{
    Territorio* atual = list;
    while (atual != NULL)
    {
        if(strcmp(atual->nomeTerritorio, nome) == 0) return atual;
        atual = atual->proximo;
    }
    return NULL;
}

Territorio* removerTerritorio(Territorio* list, char* text)
{
    Territorio* current = list;
    Territorio* before = NULL;

    while (current != NULL && strcmp(current->nomeTerritorio, text) != 0)
    {
        before = current;
        current = current->proximo;
    }

    if (current == NULL)
    {
        printf("\nTerritorio [%s] nao encontrado!\n", text);
        return list;
    }

    if (before == NULL) list = current->proximo;
    else before->proximo = current->proximo;

    free(current->nomeTerritorio);
    free(current->tropas);
    free(current->tipos);
    free(current);
    printf("\nTerritorio removido com sucesso!\n");
    return list;
}

void listarTerritorios(Territorio* list)
{
    if (list == NULL)
    {
        printf("\nNenhum territorio cadastrado!\n");
        return;
    }

    printf("\n--- LISTA DE TERRITORIOS ---\n");
    while (list != NULL)
    {   
        printf("Territorio: %-10s | Tropa: %-10s | Tipo: %-10s | Qtd: %d\n", 
               list->nomeTerritorio, list->tropas, list->tipos, list->quantias);
        list = list->proximo;
    }
}

void freeTotal(Territorio* list)
{
    while (list != NULL)
    {   
        Territorio* prox = list->proximo;
        free(list->nomeTerritorio);
        free(list->tropas);
        free(list->tipos);
        free(list);
        list = prox;
    }
}

void realizarBatalha(Territorio* list)
{
    char nomeAtacante[BUFFER_TAM], nomeDefensor[BUFFER_TAM];

    printf("Digite o territorio atacante: ");
    fgets(nomeAtacante, BUFFER_TAM, stdin);
    nomeAtacante[strcspn(nomeAtacante, "\n")] = '\0';

    printf("Digite o territorio defensor: ");
    fgets(nomeDefensor, BUFFER_TAM, stdin);
    nomeDefensor[strcspn(nomeDefensor, "\n")] = '\0';

    Territorio* atacante = buscarterritorio(list, nomeAtacante);
    Territorio* defensor = buscarterritorio(list, nomeDefensor);

    if (atacante == NULL || defensor == NULL)
    {
        printf("\nErro: Um dos territorios nao existe!\n");
        return;
    }

    printf("\n--- CONFLITO: %s vs %s ---\n", atacante->nomeTerritorio, defensor->nomeTerritorio);
    if (atacante->quantias > defensor->quantias) {
        printf("Atancate %s venceu!\n", atacante->nomeTerritorio);
    } else if (atacante->quantias < defensor->quantias) {
        printf("Defensor %s venceu!\n", nomeDefensor);
    } else {
    printf("EMPATE: As forças se anularam!\n");
}
}

void menuJogo()
{
    Territorio* list = NULL;
    int op;
    
    do {
        printf("\n[ MENU DE GUERRA ]\n1. Inserir Territorio\n2. Remover Territorio\n3. Listar Tropas\n4. Batalhar\n0. Voltar ao Inicio\nOpcao: ");
        if (scanf("%d", &op) != 1) {
            limparBufferEntrada();
            continue;
        }
        limparBufferEntrada();
        
        switch (op)
        {
            case 1: {
                char nomeTer[BUFFER_TAM], nomeTro[BUFFER_TAM], tipoTro[BUFFER_TAM];
                int q_tropas;

                printf("\nNome do territorio: ");
                fgets(nomeTer, BUFFER_TAM, stdin);
                nomeTer[strcspn(nomeTer, "\n")] = '\0';

                printf("Nome da tropa (ex: Cavalaria): ");
                fgets(nomeTro, BUFFER_TAM, stdin);
                nomeTro[strcspn(nomeTro, "\n")] = '\0';

                printf("Tipo da tropa (ex: Terrestre): ");
                fgets(tipoTro, BUFFER_TAM, stdin);
                tipoTro[strcspn(tipoTro, "\n")] = '\0';

                printf("Quantidade: ");
                scanf("%d", &q_tropas);
                limparBufferEntrada();

                list = inserirTerritorio(list, nomeTer, nomeTro, tipoTro, q_tropas);
                printf("Territorio adicionado!\n");
                break;
            }
            case 2: {
                char buffer[BUFFER_TAM];
                printf("Qual territorio deseja remover? ");
                fgets(buffer, BUFFER_TAM, stdin);
                buffer[strcspn(buffer, "\n")] = '\0';
                list = removerTerritorio(list, buffer);
                break;
            }
            case 3:
                listarTerritorios(list);
                break;
            case 4:
                if (list == NULL || list->proximo == NULL) 
                {
                    printf("\nVoce precisa de pelo menos 2 territorios para lutar!\n");
                } else {
                    realizarBatalha(list);
                }
                break;
            case 0: 
                freeTotal(list);
                printf("Limpando memoria e voltando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        } 
    } while (op != 0); 
}

int main()
{
    int op;
    do {
        printf("\n=== WAR SYSTEM ===\n");
        printf("1. Entrar no Menu de Tropas\n0. Sair do Jogo\nOpcao: ");
        if (scanf("%d", &op) != 1) {
            limparBufferEntrada();
            continue;
        }
        limparBufferEntrada();

        if (op == 1) menuJogo();
        
    } while (op != 0);

    return 0;
}
