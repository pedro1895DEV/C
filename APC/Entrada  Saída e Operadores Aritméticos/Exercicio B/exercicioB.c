// Grau para Radiano
// Leia um número real α em graus, transforme-o em radianos e imprima-o na tela.

//Input
// Uma linha com um número real α (0∘≤α≤360∘).

// Output
// Uma linha com o número α convertido para radianos.

// Note
// Para cada caso de teste, se sua resposta é um valor y e a do juiz é o valor z, sua resposta será considerada correta se |y−z|≤10−5.

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main() {
    int graus;
    double radianos;

    printf("Digite o numero a ser convertido:\n ");
    scanf("%d", &graus);

    radianos = graus * (M_PI / 180);
    printf("%lf", radianos);

    return 0;
}