#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    int ver = 1;
    int l, c;
    
    do {
        printf("Lines for m1: ");
        scanf("%d", &l);

        printf("Columns for m1: ");
        scanf("%d", &c);

        if(c == l){
            printf("Please, use non-square matrices to better see the transposition.\n\n");
            continue;
        } else {
            ver = 0;
        }
    } while(ver != 0);

    int **m1 = (int**)malloc(l * sizeof(int*));
    for(int i = 0; i < l; i++){
        m1[i] = (int*)calloc(c, sizeof(int));
    }

    int **m2 = (int**)malloc(c * sizeof(int*));
    for(int i = 0; i < c; i++){
        m2[i] = (int*)calloc(l, sizeof(int));
    }

    printf("\n--- Complete Matriz 1 ---\n");
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            printf("Insert value for m1 [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m1[i][j]);
        }
    }   

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            m2[j][i] = m1[i][j]; 
        }
    }

    printf("\n--- Normal Matriz (m1: %dx%d) ---\n", l, c);
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            printf("%3d", m1[i][j]);
        }
        printf("\n");
    }

    printf("\n--- Transposed Matriz (m2: %dx%d) ---\n", c, l);
    for(int i = 0; i < c; i++){
        for(int j = 0; j < l; j++){
            printf("%3d", m2[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < l; i++) free(m1[i]);
    free(m1);

    for(int i = 0; i < c; i++) free(m2[i]);
    free(m2);

    return 0;
}
