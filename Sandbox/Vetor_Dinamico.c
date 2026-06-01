#include <stdio.h>
#include <stdlib.h> 

int main(){

    int tam;
    printf("Quantos numeros voce quer armazenar? ");
    scanf("%d", &tam);

    int *array = (int*)malloc(tam * sizeof(int));
    
    if (array == NULL) {
        printf("Erro: Memoria cheia!\n");
        return 1;
    }
    
    for(int i = 0; i < tam; i++){
        printf("#%d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("\nOrdem inversa: ");
    
    for(int i = tam - 1; i >= 0; i--){
        printf("%d ", array[i]);
    }
    
    printf("\n");

    free(array);

    return 0;
}
