// Radianos para Graus

// Leia um número real α em radianos, transforme-o em graus e imprima-o na tela.

// Input
// Uma linha com um número real α (0≤α≤2π).

// Output
// Uma linha com o número α convertido para graus.

// Note
// Para cada caso de teste, se sua resposta é um valor y e a do juiz é o valor z, sua resposta será considerada correta se |y−z|≤10−5.

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main() {
    double radianos;
    int graus;

    printf("Digite o numero a ser convertido:\n ");
    scanf("%lf", &radianos);

    graus = radianos * (180 / M_PI);
    printf("%d", graus);
    return 0;
}