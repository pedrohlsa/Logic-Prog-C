#include <stdio.h>



#define linhas 10

#define colunas 10

#define letras 10



void matriz()

{

    int matriz[linhas][colunas] = {0};

    char cabecario[letras] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};



    matriz [1][3] = 3; matriz [2][3] = 3; matriz [3][3] = 3;

    matriz [7][5] = 3; matriz [7][6] = 3; matriz [7][7] = 3;

   

    printf("   ");

    for (int i = 0; i < letras; i++)

    {

        printf("%c ", cabecario[i]);

    }

    printf("\n");



    for (int i = 0; i < linhas; i++){

        printf("%2d ", i + 1);

        for (int j = 0; j < colunas; j++){

           

            printf("%d ", matriz[i][j]);

        }

        printf("\n");

    }





}



int main()

{

    matriz();

}
