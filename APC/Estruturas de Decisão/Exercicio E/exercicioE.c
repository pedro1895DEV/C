// Condição de Existência de um Triângulo

// Leia três números reais que correspondem ao comprimento de três segmentos de reta e verifique se eles podem formar um triângulo.

// Input
// A entrada possui uma única linha com três reais, A, B e C (0 < A, B, C ≤ 10⁹ ), separados por um espaço, que descrevem o comprimento de cada um dos segmentos de
// reta.

// Output
// Imprima "Sim" se é possível formar o triângulo com os segmentos de comprimento A, B e C e "Nao" caso contrário.

#include <stdio.h>

int main () {
    double a, b, c;

    printf("Digite tres segmentos de reta: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a + b > c && b + c > a && a + c > b) {
        printf("Sim");
    } else {
        printf("Nao");
    }

    return 0;
}