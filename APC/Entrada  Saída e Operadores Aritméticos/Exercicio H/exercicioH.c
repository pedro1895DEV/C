// Pitágoras

// Dado os comprimentos de dois catetos em um triângulo retângulo, calcule o comprimento da hipotenusa.

// Input
// A entrada possui uma linha com dois números reais, b e c (0<b,c≤102), que representam o comprimento dos catetos.

// Output
// Imprima o comprimento da hipotenusa em uma linha.

# include <stdio.h>
#include <math.h>

int main () {
    double b;
    double c;
    double hipotenusa;

    printf("Digite os valores dos catetos: ");
    scanf("%lf %lf", &b, &c);

    hipotenusa = pow(b, 2) + pow(c, 2);

    printf("%lf", sqrt(hipotenusa)); 
    return 0;
}