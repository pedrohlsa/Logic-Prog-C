#include <stdio.h>
#include <ctype.h> 

void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int temp;
    char medida;
    float resultado;

    printf("Digite a temperatura (valor inteiro): ");
    if (scanf("%d", &temp) != 1) {
        printf("\nErro: Entrada invalida. Digite um numero.\n");
        return 1;
    }
    cleanBuffer();

    printf("-> Informe a unidade de origem [C/F]: ");
    scanf("%c", &medida);
    cleanBuffer();

    medida = toupper(medida);

    printf("\n------------------------------------\n");

    if (medida == 'C' && temp >= -250) {
        resultado = (temp * 1.8) + 32;
        printf(" Entrada: %d° Celsius\n", temp);
        printf(" Saida  : %.2f° Fahrenheit\n", resultado);
    } 
    else if (medida == 'F' && temp >= -350) {
        resultado = (temp - 32) / 1.8;
        printf(" Entrada: %d° Fahrenheit\n", temp);
        printf(" Saida  : %.2f° Celsius\n", resultado);
    } 
    else {
        printf(" [ERRO] Unidade invalida ou temperatura\n");
        printf(" abaixo do zero absoluto!\n");
    }

    printf("------------------------------------\n");

    return 0;
}
