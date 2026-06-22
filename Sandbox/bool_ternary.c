#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool is_hamburguertasty;

    printf("Is hamburguer tasty? (0 = No, 1 = Yes)\n");
    scanf("%d", &is_hamburguertasty);

    is_hamburguertasty ? printf("Yes!") : printf("No!");

    return 0;
}
