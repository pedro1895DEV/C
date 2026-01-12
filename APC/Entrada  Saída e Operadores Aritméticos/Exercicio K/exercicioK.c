// Área de um Triângulo

// Sejam a, b e c os comprimentos dos três lados de um triângulo. Calcule sua área.

// Input
// A entrada possui uma única linha com três números reais, a, b e c(0<a,b,c≤102), separados por um espaço.

// Output
// Imprima, em uma linha, a área do triângulo.


#include <stdio.h>
#include <math.h>

int main () {
    double a;
    double b;
    double c;
    double semiperimetro;
    double area;

    printf("Digite os tres valores: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    semiperimetro = (a + b + c) / 2;
    area = (semiperimetro * (semiperimetro - a)) * (semiperimetro - b) *  (semiperimetro - c) ;

    printf("%lf", sqrt(area));
    return 0;
}