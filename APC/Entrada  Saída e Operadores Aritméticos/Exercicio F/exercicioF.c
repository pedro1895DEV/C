// Média Aritmética

// Calcule a média aritmética de três números reais.

// Input
// A entrada possui uma linha com três números reais, separados por um espaço. Os números reais estão no intervalo [10−2,102].

// Output
// Imprima a média aritmética dos três números reais.

#include <stdio.h>

int main () {
    double num1;
    double num2;
    double num3;
    double mediaAritmetica;

    printf("Digite os tres numeros para calcular a media aritmetica: ");
    scanf("%lf %lf %lf", &num1, &num2, &num3);

    mediaAritmetica = (num1 + num2 + num3) / 3;
    printf("%lf", mediaAritmetica);

    return 0;
}