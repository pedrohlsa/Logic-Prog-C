#include <stdio.h>
#include <stdlib.h> 

int main(){

    int tam;
    printf("Tamanho dos vetores: ");
    scanf("%d", &tam);

    int *v1 = (int*)malloc(tam * sizeof(int));
    int *v2 = (int*)malloc(tam * sizeof(int));
    
    if (v1 == NULL || v2 == NULL) {
        printf("Erro de memória!\n");
        return 1;
    }
    
    printf("\n=== PREENCHER VETOR 1 ===\n");
    for(int i = 0; i < tam; i++){
        printf("#%d: ", i + 1); 
        scanf("%d", &v1[i]);
    }
    
    printf("\n=== PREENCHER VETOR 2 ===\n");
    for(int i = 0; i < tam; i++){
        printf("#%d: ", i + 1);
        scanf("%d", &v2[i]);
    }

    int *res = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
        res[i] = v1[i] + v2[i];
    }

    printf("\n=== RESULTADO ===\n");
    for(int i = 0; i < tam; i++){
        printf("v1[%d] = %2d | v2[%d] = %2d | soma = %3d\n", 
               i, v1[i], i, v2[i], res[i]); 
    }

    free(v1);
    free(v2);
    free(res);

    return 0;
}
