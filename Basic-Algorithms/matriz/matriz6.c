#include <stdio.h>

#define TAM 3

int main(){
    int matriz[TAM][TAM] = {{1,2,3}, {6,7,5}, {7,8,9}};
    int target = 5;
    int found = 0;

    for (int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            if(matriz[i][j] == target){
                printf("Elemento %d encontrando na posicao. (%d,%d)\n", target, i,j);
                found = 1;
                break;
            }        
        }
        if (found) break;
    }

    if (!found) {
        printf("elemendo %d não encontrado na matriz.\n", target);
    }
return 0;
}
