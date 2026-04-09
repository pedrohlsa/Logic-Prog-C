#include <stdio.h>  

#define TAM 3

int main(){
    int matriz[TAM][TAM] = {{1,2,3}, {4,5,6}, {7,8,9}}; //valor padrao do meu cod
    int numpar = 0, numimpar = 0;

    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            if(matriz[i][j] % 2 == 0){
                numpar++;
            } else{
                numimpar++;
            }
        }
    }
printf("numeros de elem pares: %d", numpar);
printf("\nnumeros de elem impares: %d", numimpar);
return 0;
}
