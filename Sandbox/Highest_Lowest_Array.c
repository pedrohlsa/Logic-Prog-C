#include <stdio.h>

void biggestAndSmallest() {
    int numeros[5];
    int maior, menor;

    printf("Enter 5 integers:\n");

    for(int i = 0; i < 5; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    menor = numeros[0];

    for(int i = 1; i < 5; i++) {
        if(numeros[i] > maior) maior = numeros[i];
        if(numeros[i] < menor) menor = numeros[i];
    }

    printf("\n=== RESULT ===\n");
    printf("Highest number: %d\n", maior);
    printf("Lowest number: %d\n", menor);
}

int main() {
    biggestAndSmallest();
    return 0;
}
