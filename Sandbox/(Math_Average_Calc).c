#include <stdio.h>

void show() {
    int num1, num2, num3;
    printf("Enter 3 integers (Do NOT use dots):\n");
    scanf("%d %d %d", &num1, &num2, &num3);

    int soma = num1 + num2 + num3;
    float divisao = (float)(num1 + num2 + num3) / 3;

    printf("\n=== RESULT ===\n");
    printf("Sum: %d | Average: %.2f\n", soma, divisao);
}

int main() {
    show();
    return 0;
}
