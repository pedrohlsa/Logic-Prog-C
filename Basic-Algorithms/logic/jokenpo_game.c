#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int escolhacomputador, escolhajogador;
    srand(time(0));

    printf("----- Jokenpô ----\n1. Pedra\n2. Papel\n3. Tesoura\nEscolha: ");
    scanf("%d", &escolhajogador);

    escolhacomputador = rand() % 3 + 1; 

    if (escolhajogador == escolhacomputador) {
        printf("Empate!\n");
    } else if ((escolhajogador == 1 && escolhacomputador == 3) ||
               (escolhajogador == 2 && escolhacomputador == 1) ||
               (escolhajogador == 3 && escolhacomputador == 2)) {
        printf("Você ganhou!\n");
    } else {
        printf("Você perdeu!\n");
    }
    return 0;
}
