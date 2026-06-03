#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int l1, c1, l2, c2;
    int ver = 1;
    
    do {
        printf("How many lines do you want in matriz 1: ");
        scanf("%d", &l1);
        printf("How many columns do you want in matriz 1: ");
        scanf("%d", &c1);

        printf("How many lines do you want in matriz 2: ");
        scanf("%d", &l2);
        printf("How many columns do you want in matriz 2: ");
        scanf("%d", &c2);

        if(l1 <= 0 || c1 <= 0 || l2 <= 0 || c2 <= 0 || l1 != l2 || c1 != c2 || l1 != c1){
            printf("Please, use only positive numbers. Remember: matrices must be equal and square to have a main diagonal!\n\n");
            continue;
        } else {
            ver = 0;
        }
    } while(ver != 0);

    int **matriz1 = (int**)malloc(l1 * sizeof(int*));
    for(int i = 0; i < l1; i++){
        matriz1[i] = (int*)calloc(c1, sizeof(int));
    }
    
    int **matriz2 = (int**)malloc(l2 * sizeof(int*));
    for(int i = 0; i < l2; i++){
        matriz2[i] = (int*)calloc(c2, sizeof(int));
    }

    printf("\n--- Filling Matriz 1 ---\n");
    for(int i = 0; i < l1; i++) {
        for(int j = 0; j < c1; j++) {
            printf("Insert value for Matriz 1 [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz1[i][j]);
        }
    }

    printf("\n--- Filling Matriz 2 ---\n");
    for(int i = 0; i < l2; i++) {
        for(int j = 0; j < c2; j++) {
            printf("Insert value for Matriz 2 [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz2[i][j]);
        }
    }
    
    printf("\nNow we will do the sum of diagonals of matrices...\n");

    int sum1 = 0;
    int sum2 = 0;

    for(int i = 0; i < l1; i++){
        sum1 += matriz1[i][i]; 
    }
    for(int i = 0; i < l2; i++){
        sum2 += matriz2[i][i]; 
    }

    printf("\n--- Matriz 1 ---\n");
    for(int i = 0; i < l1; i++){
        for(int j = 0; j < c1; j++){
            printf("%3d", matriz1[i][j]);
        }
        printf("\n");
    }
    
    printf("\n--- Matriz 2 ---\n");
    for(int i = 0; i < l2; i++){
        for(int j = 0; j < c2; j++){
            printf("%3d", matriz2[i][j]);
        }
        printf("\n");
    }
    
    printf("\nResults of main diagonals of mat 1: [%d]", sum1);
    printf("\nResults of main diagonals of mat 2: [%d]\n", sum2);

    int sum3 = 0;
    int sum4 = 0;

    for(int i = 0; i < l1; i++){
        sum3 += matriz1[i][l1 - 1 - i];
    }
    
    for(int i = 0; i < l2; i++){
        sum4 += matriz2[i][l2 - 1 - i];
    }

    printf("\nResults of secondary diagonals of mat 1: [%d]", sum3);
    printf("\nResults of secondary diagonals of mat 2: [%d]\n", sum4);

    for(int i = 0; i < l1; i++) free(matriz1[i]);
    free(matriz1);
    
    for(int i = 0; i < l2; i++) free(matriz2[i]);
    free(matriz2);

    return 0;
}
