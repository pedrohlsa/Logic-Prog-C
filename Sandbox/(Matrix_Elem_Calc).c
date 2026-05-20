#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cleanBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main() {
    
    // matriz 1
    int linhas1 = 0, colunas1 = 0;

    // matriz 2
    int linhas2 = 0, colunas2 = 0;
    
    printf("========================================\n");
    printf("        MATRIZ 1 - DIMENSOES\n");
    printf("========================================\n");
    
    // validação para garantir tamanho válido
    do {
        printf("Digite o numero de LINHAS (maior que 0): ");
        scanf("%d", &linhas1);
        cleanBuffer();
    } while (linhas1 <= 0);
    
    do {
        printf("Digite o numero de COLUNAS (maior que 0): ");
        scanf("%d", &colunas1);  // boa pratica para evitar colunas e linhas de 0
        cleanBuffer(); 
    } while (colunas1 <= 0);
    
    // usando calloc pra n ter q usar for
    int **matriz1 = (int**)malloc(linhas1 * sizeof(int*));
    for(int i = 0; i < linhas1; i++) {
        matriz1[i] = (int*)calloc(colunas1, sizeof(int));
    }
    
    printf("\n========================================\n");
    printf("        MATRIZ 2 - DIMENSOES\n");
    printf("========================================\n");
    
    do {
        printf("Digite o numero de LINHAS (maior que 0): ");
        scanf("%d", &linhas2);
        cleanBuffer();
    } while (linhas2 <= 0);
    
    do {
        printf("Digite o numero de COLUNAS (maior que 0): ");
        scanf("%d", &colunas2);
        cleanBuffer();
    } while (colunas2 <= 0); 
    
    int **matriz2 = (int**)malloc(linhas2 * sizeof(int*));
    for(int i = 0; i < linhas2; i++) {
        matriz2[i] = (int*)calloc(colunas2, sizeof(int));
    }
    
    int opcao;
    int linha, coluna, valor;
    
    printf("\n========================================\n");
    printf("     PREENCHENDO MATRIZ 1\n");
    printf("========================================\n");
    
    do {
        printf("\n--- MATRIZ 1 ---\n");
        printf("1 - Preencher uma posicao\n");
        printf("2 - Mostrar matriz 1 atual\n");
        printf("3 - Sair do preenchimento da matriz 1\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        cleanBuffer();
        
        switch(opcao) {
            case 1:
                printf("\nDigite a LINHA (1 a %d): ", linhas1);
                scanf("%d", &linha);
                cleanBuffer();
                
                printf("Digite a COLUNA (1 a %d): ", colunas1);
                scanf("%d", &coluna);
                cleanBuffer();
                
                if(linha > 0 && linha <= linhas1 && coluna > 0 && coluna <= colunas1) {
                    printf("Digite o VALOR: ");
                    scanf("%d", &valor);
                    cleanBuffer();
                    
                    matriz1[linha-1][coluna-1] = valor;
                    printf("Valor %d armazenado em matriz1[%d][%d]\n", valor, linha-1, coluna-1);
                } else {
                    printf("[!] Posicao invalida!\n");
                }
                break;
                
            case 2:
                printf("\n=== MATRIZ 1 ATUAL ===\n");
                for(int i = 0; i < linhas1; i++) {
                    for(int j = 0; j < colunas1; j++) {
                        printf("%3d ", matriz1[i][j]);
                    }
                    printf("\n");
                }
                break;
                
            case 3:
                printf("Saindo do preenchimento da matriz 1...\n");
                break;
                
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 3);
    
    printf("\n========================================\n");
    printf("     PREENCHENDO MATRIZ 2\n");
    printf("========================================\n");
    
    do {
        printf("\n--- MATRIZ 2 ---\n");
        printf("1 - Preencher uma posicao\n");
        printf("2 - Mostrar matriz 2 atual\n");
        printf("3 - Sair do preenchimento da matriz 2\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        cleanBuffer();
        
        switch(opcao) {
            case 1:
                printf("\nDigite a LINHA (1 a %d): ", linhas2);
                scanf("%d", &linha);
                cleanBuffer();
                
                printf("Digite a COLUNA (1 a %d): ", colunas2);
                scanf("%d", &coluna);
                cleanBuffer();
                
                if(linha > 0 && linha <= linhas2 && coluna > 0 && coluna <= colunas2) {
                    printf("Digite o VALOR: ");
                    scanf("%d", &valor);
                    cleanBuffer();
                    
                    matriz2[linha-1][coluna-1] = valor;
                    printf("Valor %d armazenado em matriz2[%d][%d]\n", valor, linha-1, coluna-1);
                } else {
                    printf("[!] Posicao invalida!\n");
                }
                break;
                
            case 2:
                printf("\n=== MATRIZ 2 ATUAL ===\n");
                for(int i = 0; i < linhas2; i++) {
                    for(int j = 0; j < colunas2; j++) {
                        printf("%3d ", matriz2[i][j]);
                    }
                    printf("\n");
                }
                break;
                
            case 3:
                printf("Saindo do preenchimento da matriz 2...\n");
                break;
                
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 3);
    
    int num1, num2;
    int encontrado1, encontrado2;
    int res1 = 0, res2 = 0;
    int pos_i1, pos_j1, pos_i2, pos_j2;
    char continuar;
    
    do {
        printf("\n========================================\n");
        printf("        BUSCAR NUMEROS NAS MATRIZES\n");
        printf("========================================\n");
        
        printf("\n--- MATRIZ 1 ---\n");
        printf("Digite o numero que voce quer encontrar: ");
        scanf("%d", &num1);
        cleanBuffer();
        
        encontrado1 = 0;
        for(int i = 0; i < linhas1 && !encontrado1; i++) {
            for(int j = 0; j < colunas1; j++) {
                if(matriz1[i][j] == num1) {
                    encontrado1 = 1;
                    res1 = matriz1[i][j];
                    pos_i1 = i;
                    pos_j1 = j;
                    break; 
                }
            }
        }
        
        if(encontrado1) {
            printf(" Numero %d encontrado na matriz1!\n", num1);
            printf("   Posicao: [%d][%d]\n", pos_i1, pos_j1);
        } else {
            printf("[!] Numero %d NAO encontrado na matriz1!\n", num1);
        }
        
        // Buscar na matriz 2
        printf("\n--- MATRIZ 2 ---\n");
        printf("Digite o numero que voce quer encontrar: ");
        scanf("%d", &num2);
        cleanBuffer();
        
        encontrado2 = 0;
        for(int i = 0; i < linhas2 && !encontrado2; i++) {
            for(int j = 0; j < colunas2; j++) {
                if(matriz2[i][j] == num2) {
                    encontrado2 = 1;
                    res2 = matriz2[i][j];
                    pos_i2 = i;
                    pos_j2 = j;
                    break;
                }
            }
        }
        
        if(encontrado2) {
            printf(" Numero %d encontrado na matriz2!\n", num2);
            printf("   Posicao: [%d][%d]\n", pos_i2, pos_j2);
        } else {
            printf("[!] Numero %d NAO encontrado na matriz2!\n", num2);
        }
        
        // se ambs foram encontrados faz operacao
        if(encontrado1 && encontrado2) {
            printf("\n========================================\n");
            printf("           CALCULANDO...\n");
            printf("========================================\n");
            printf("Numero da matriz1: %d\n", res1);
            printf("Numero da matriz2: %d\n", res2);
            
            int operacao;
            printf("\nEscolha a operacao:\n");
            printf("1 - SOMA        (%d + %d)\n", res1, res2);
            printf("2 - SUBTRACAO   (%d - %d)\n", res1, res2);
            printf("3 - MULTIPLICACAO (%d * %d)\n", res1, res2);
            printf("4 - DIVISAO     (%d / %d)\n", res1, res2);
            printf("Opcao: ");
            scanf("%d", &operacao);
            cleanBuffer();
            
            printf("\n=== RESULTADO ===\n");
            switch(operacao) {
                case 1:
                    printf("%d + %d = %d\n", res1, res2, res1 + res2);
                    break;
                case 2:
                    printf("%d - %d = %d\n", res1, res2, res1 - res2);
                    break;
                case 3:
                    printf("%d * %d = %d\n", res1, res2, res1 * res2);
                    break;
                case 4:
                    if(res2 != 0) {
                        printf("%d / %d = %.2f\n", res1, res2, (float)res1 / res2);
                    } else {
                        printf("ERRO: Divisao por zero!\n");
                    }
                    break;
                default:
                    printf("Opcao invalida!\n");
            }
        } else {
            printf("\n[!] NAO FOI POSSIVEL CALCULAR!\n");
            printf("   Um ou ambos os numeros nao foram encontrados.\n");
        }
        
        printf("\nDeseja buscar outros numeros? (s/n): ");
        scanf("%c", &continuar);
        cleanBuffer();
        
    } while(continuar == 's' || continuar == 'S');
    
    printf("\n========================================\n");
    printf("           MATRIZES FINAIS\n");
    printf("========================================\n");
    
    printf("\n=== MATRIZ 1 ===\n");
    for(int i = 0; i < linhas1; i++) {
        for(int j = 0; j < colunas1; j++) {
            printf("%3d ", matriz1[i][j]);
        }
        printf("\n");
    }
    
    printf("\n=== MATRIZ 2 ===\n");
    for(int i = 0; i < linhas2; i++) {
        for(int j = 0; j < colunas2; j++) {
            printf("%3d ", matriz2[i][j]);
        }
        printf("\n");
    }
    
    for(int i = 0; i < linhas1; i++) {
        free(matriz1[i]);
    }
    free(matriz1);
    
    for(int i = 0; i < linhas2; i++) {
        free(matriz2[i]);
    }
    free(matriz2);
    
    printf("\n Programa finalizado com sucesso!\n");
    
    return 0;
}
