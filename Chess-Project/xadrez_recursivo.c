#include <stdio.h>

// bispo 5 diagonais direita cima 
// torre 5 casas direita
// rainha 8 casas esquerda
// cavalo 2 cima direita

void movertorre(int casas)
{
if (casas > 0)
    {
    printf("Torre Direita\n");
    movertorre (casas - 1);
    }
} 

void moverbispo(int casas)
{
if (casas > 0)
    {
    printf("Bispo à Diagonal Direita\n");
    moverbispo (casas - 1);
    }
}

void moverrainha(int casas)
{
    if(casas > 0)
    { 
    printf("Rainha à Esquerda\n");
    moverrainha (casas - 1);
    }
} 

void movercavalocima(int casas)
{
    if (casas > 0)
    {
        printf("Cavalo Cima\n");
        movercavalocima (casas - 1);
    }
}

void movercavaloreto(int casas)
{
    if (casas > 0)
    {
    printf("Cavalo Direita\n");
    movercavaloreto (casas - 1);
    }
} 


int main(){
    movertorre(5);

    moverbispo(5);

    moverrainha(8);

    movercavalocima(2);
    
    movercavaloreto(1);

    return 0;
} 
