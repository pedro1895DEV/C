// Tipo de um Triângulo

// Leia três números reais que correspondem ao comprimento de três segmentos de reta e verifique se eles podem formar um triângulo e, em caso afirmativo, qual o tipo deste
// triângulo.

// Input
// A entrada possui uma única linha com três reais, A, B e C (0 < A, B, C ≤ 10⁹), separados por um espaço, que descrevem o comprimento de cada segmento de reta.

// Output
// Imprima uma linha com:
// "equilatero": caso seja possível formar um triângulo equilátero.
// "isosceles": caso seja possível formar um triângulo isósceles.
// "retangulo": caso seja possível formar um triângulo retângulo que não seja isósceles.
// "escaleno": caso seja possível formar um triângulo escaleno que não seja retângulo.
// "impossivel": caso seja impossível formar um triângulo.

#include <stdio.h>
#include <math.h>

int main () {
    double a, b, c;

    printf("Digite tres segmentos de reta: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a + b > c && b + c > a && a + c > b) {
        if ( a == b && b == c) {
            printf("equilatero");
        }
        else if (a == b || a == c || c == b) {
            printf("isoceles");
        }
        else if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
            printf("retangulo");
        }
        else if (a != b && b != c && a != c) {
            printf("escaleno");
        }
    } else {
        printf("impossivel");
    }
    return 0;
}