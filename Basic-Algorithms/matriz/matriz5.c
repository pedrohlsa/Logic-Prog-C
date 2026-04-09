#include <stdio.h>

#define TAM 3
int main(){
    int matriz[TAM][TAM] = {{1,2,3}, {4,5,6}, {7,8,9}}; 
    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            char impar;
            if (matriz [i][j] % 3 == 0){
                printf("impar.");
            } else{
            printf("%d ", matriz[i][j]);
            }
        }
        printf("\n");
    }





}
