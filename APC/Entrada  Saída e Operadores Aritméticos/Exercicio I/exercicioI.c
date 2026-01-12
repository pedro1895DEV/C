// Lei dos Cossenos

// Dados os comprimentos dos dois lados de um triângulo, a e b, e o ângulo oposto ao terceiro lado, θ, calcule o comprimento do terceiro lado.

// Input
// A entrada consiste de uma linha com três números reais, a, b (0<a,b≤102) e θ (0<θ<180), que indicam, respectivamente, ao comprimento dos dois lados do triângulo e ao valor do ângulo, em graus, oposto ao terceiro lado.

// É garantido que os dados informados são suficientes para formar um triângulo.

// Output
// Imprima, em uma linha, o comprimento do terceiro lado.

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main () {
    double a;
    double b;
    double c;
    double teta;
    double radianos;

    printf("Digite os tres valores: ");
    scanf("%lf %lf %lf", &a, &b, &teta);

    radianos = teta * (M_PI / 180);

    c = (pow(a, 2) + pow(b, 2)) - ((2*a*b) * cos(radianos));

    printf("%lf", sqrt(c));

    return 0;
}