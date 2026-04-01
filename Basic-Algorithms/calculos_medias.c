#include <stdio.h>

int main(){
    float x, y, z;
    printf("Insira x, y e z: ");
    scanf("%f %f %f", &x, &y, &z);

    float soma = x + y;
    float produto = x * y;
    float media = (soma + produto) / 2;
    int media_arredondada = (int)media;

    printf("Soma: %.2f\nProduto: %.2f\nMedia: %.2f\n", soma, produto, media);
    printf("Media Arredondada (Casting): %d\n", media_arredondada);
    
    return 0;
}
