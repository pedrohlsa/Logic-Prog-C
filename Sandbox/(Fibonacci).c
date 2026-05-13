#include <stdio.h>

int main()
{
    int op, t1 = 0, t2 = 1, proximoTerm = 0;

    printf("Qual termo Fibonacci você quer? ");
    scanf("%d", &op);

    if (op == 1)
        printf("%d\n", t1);
    else if (op == 2)
        printf("%d\n", t2);
    else
    {
        for (int i = 3; i <= op; i++)
        {
            proximoTerm = t1 + t2;
            t1 = t2;
            t2 = proximoTerm;
        }
        printf("%d° termo de Fibonnaci é: %d", op, t2);
    }
}
