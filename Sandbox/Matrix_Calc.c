#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linhas1 = 0, colunas1 = 0;
    int linhas2 = 0, colunas2 = 0;

    printf("=== MATRIZ 1 ===\n");
    printf("Linhas: ");
    scanf("%d", &linhas1);
    printf("Colunas: ");
    scanf("%d", &colunas1);

    printf("\n=== MATRIZ 2 ===\n");
    printf("Linhas: ");
    scanf("%d", &linhas2);
    printf("Colunas: ");
    scanf("%d", &colunas2);

    // Alocação da Matriz 1
    int **matriz1 = (int **)malloc(linhas1 * sizeof(int *));
    for (int i = 0; i < linhas1; i++)
        matriz1[i] = (int *)calloc(colunas1, sizeof(int));

    // Alocação da Matriz 2
    int **matriz2 = (int **)malloc(linhas2 * sizeof(int *));
    for (int i = 0; i < linhas2; i++)
        matriz2[i] = (int *)calloc(colunas2, sizeof(int));

    printf("\n=== PREENCHER MATRIZ 1 ===\n");
    for (int i = 0; i < linhas1; i++)
    {
        for (int j = 0; j < colunas1; j++)
        {
            printf("matriz1[%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }

    printf("\n=== PREENCHER MATRIZ 2 ===\n");
    for (int i = 0; i < linhas2; i++)
    {
        for (int j = 0; j < colunas2; j++)
        {
            printf("matriz2[%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }

    int total1 = 0;
    for (int i = 0; i < linhas1; i++)
    {
        for (int j = 0; j < colunas1; j++)
        {
            total1 += matriz1[i][j]; // Acumula cada número da matriz 1
        }
    }
    printf("\nTotal da Matriz 1: %d\n", total1);

    int total2 = 0;
    for (int i = 0; i < linhas2; i++)
    {
        for (int j = 0; j < colunas2; j++)
        {
            total2 += matriz2[i][j]; // Acumula cada número da matriz 2
        }
    }
    printf("Total da Matriz 2: %d\n", total2);

    int op;
    do{
    printf("\n1. + | 2. - | 3. * | 4. / | 0. Sair\nEscolha: ");
    scanf("%d", &op);

    if (op == 1)
        printf("Resultado: %d\n", total1 + total2);
    else if (op == 2)
        printf("Resultado: %d\n", total1 - total2);
    else if (op == 3)
        printf("Resultado: %d\n", total1 * total2);
    else if (op == 4)
    {
        if (total2 != 0)
            printf("Resultado: %.2f\n", (float)total1 / total2);
        else
            printf("Erro: Divisao por zero!\n");
    }
    } while(op != 0);
    
    // Limpeza da memória
    for (int i = 0; i < linhas1; i++)
        free(matriz1[i]);
    for (int i = 0; i < linhas2; i++)
        free(matriz2[i]);
    
    free(matriz1);
    free(matriz2);

    return 0;

}
