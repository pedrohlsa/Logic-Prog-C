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

    int ver1 = 1;
    int nl1, nc1, nl2, nc2;
    int contagem = 0;
    
    do {
        printf("\n--- Entry %d of 4 ---\n", contagem + 1);
        printf("Please insert line do you want to add ur num in matriz 1: ");
        scanf("%d", &nl1);
        printf("Please insert column do you want to add ur num in matriz 1: ");
        scanf("%d", &nc1);

        printf("Please insert line do you want to add ur num in matriz 2: ");
        scanf("%d", &nl2);
        printf("Please insert column do you want to add ur num in matriz 2: ");
        scanf("%d", &nc2);

        if(nl1 <= 0 || nl1 > l1 || nc1 <= 0 || nc1 > c1 || nl2 <= 0 || nl2 > l2 || nc2 <= 0 || nc2 > c2){
            printf("Please, insert numbers within the limits of the matrices!\n");
            continue;
        } else {
            nl1 = nl1 - 1; nc1 = nc1 - 1;
            nl2 = nl2 - 1; nc2 = nc2 - 1;

            int num1, num2;
            printf("Num to insert in m1 on REAL position: [%d][%d]: ", nl1, nc1);
            scanf("%d", &num1);
            printf("Num to insert in m2 on REAL position: [%d][%d]: ", nl2, nc2);
            scanf("%d", &num2);

            matriz1[nl1][nc1] = num1;
            matriz2[nl2][nc2] = num2;
            contagem++;

            if(contagem == 4){
                ver1 = 0;
            }
        }
    } while(ver1 != 0);
    
    printf("\nNow we will do the sum of diagonals of matrizs...\n");
    
    int sum1 = 0;
    int sum2 = 0;

    for(int i = 0; i < l1; i++){
        sum1 += matriz1[i][i]; 
    }
    for(int i = 0; i < l2; i++){
        sum2 += matriz2[i][i]; 
    }

    for(int i = 0; i < l1; i++){
        for(int j = 0; j < c1; j++){
            printf("%3d", matriz1[i][j]);
        }
        printf("\n");
    }
    
    for(int i = 0; i < l2; i++){
        for(int j = 0; j < c2; j++){
            printf("%3d", matriz2[i][j]);
        }
        printf("\n");
    }
    
    printf("\nResults diagons of mat 1: [%d]", sum1);
    printf("\nResults diagons of mat 2: [%d]\n", sum2);

    for(int i = 0; i < l1; i++) free(matriz1[i]);
    free(matriz1);
    
    for(int i = 0; i < l2; i++) free(matriz2[i]);
    free(matriz2);

    return 0;
}
