#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char secreta[] = "PROGRAMACAO";
    int tamanho = strlen(secreta);
    
    char mascara[tamanho + 1];
    for (int i = 0; i < tamanho; i++) mascara[i] = '_';
    mascara[tamanho] = '\0'; 

    char letrasTentadas[26] = {0}; 
    int totalTentativas = 0;
    int vidas = 6;
    int acertos = 0;

    printf("========= JOGO DA FORCA =========\n");

    while (vidas > 0 && acertos < tamanho) {
        printf("\nPalavra: ");
        for (int i = 0; i < tamanho; i++) printf("%c ", mascara[i]);
        
        printf("\nVidas: %d | Tentativas: %s\n", vidas, letrasTentadas);
        printf("Digite uma letra: ");
        
        char chute;
        scanf(" %c", &chute); 
        chute = toupper(chute); 

        int jaTentou = 0;
        for (int i = 0; i < totalTentativas; i++) {
            if (letrasTentadas[i] == chute) {
                jaTentou = 1;
                break;
            }
        }

        if (jaTentou) {
            printf("\n[!] Voce ja tentou a letra %c! Tente outra.\n", chute);
            continue; 
        }

        letrasTentadas[totalTentativas] = chute;
        totalTentativas++;

        int encontrou = 0;
        for (int i = 0; i < tamanho; i++) {
            if (secreta[i] == chute) {
                mascara[i] = chute;
                acertos++;
                encontrou = 1;
            }
        }

        if (encontrou) {
            printf("\nBoa! A letra %c faz parte da palavra.\n", chute);
        } else {
            vidas--;
            printf("\nErrado! A letra %c nao existe. Restam %d vidas.\n", chute, vidas);
        }
    }

    if (acertos == tamanho) {
        printf("\nPARABENS! Voce venceu. A palavra era: %s\n", secreta);
    } else {
        printf("\nGAME OVER! Voce foi enforcado. A palavra era: %s\n", secreta);
    }

    return 0;
}
