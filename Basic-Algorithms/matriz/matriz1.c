#include <stdio.h>

int main()
{

    int matriz[3][3] = {{0,1,2}, {3,4,5}, {5,6,7}};
    int matriz2[3][3] = {{10, 11, 12}, {15, 16, 17}, {18,19,20}};
    int matrizsoma[3][3];

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
        {
            matrizsoma[i][j] = matriz[i][j] + matriz2[i][j];
            printf("matrizsoma[%d][%d] = %d\n", i, j, matrizsoma[i][j]);
        }

    }


}
