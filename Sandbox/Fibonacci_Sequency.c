#include <stdio.h>

int main() {
    int n;
    printf("Quantos números de Fibonacci? ");
    scanf("%d", &n);
    
    if(n <= 0) {
        printf("Número inválido!\n");
        return 1;
    }
    
    int a = 0, b = 1, prox;
    
    printf("Sequência: ");
    
    for(int i = 1; i <= n; i++) {
        printf("%d ", a);
        prox = a + b;
        a = b;
        b = prox;
    }
    
    printf("\n");
    return 0;
}
