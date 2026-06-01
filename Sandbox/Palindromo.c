#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

bool verificarEImprimir(const char *texto) {
    int tam = strlen(texto);
    bool ehPalindromo = true;

    printf("Original: %s | Invertido: ", texto);

    for (int i = 0; i < tam; i++) {
     
        char caractereInvertido = texto[tam - 1 - i];
        printf("%c", caractereInvertido);


        if (texto[i] != caractereInvertido) {
            ehPalindromo = false;
        }
    }

    printf(" -> %s\n", ehPalindromo ? "E palindromo!" : "Nao e palindromo!");
    return ehPalindromo;
}

int main() {
    // Casos de teste
    char palavra1[] = "arara";
    char palavra2[] = "billy";

    printf("--- Verificador de Palindromos ---\n\n");

    verificarEImprimir(palavra1);
    verificarEImprimir(palavra2);

    printf("\n----------------------------------\n");

    return 0;
}
