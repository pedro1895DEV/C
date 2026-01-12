// Celsius para Fahrenheit

// Leia um número real t em Celsius, transforme-o em Fahrenheit e imprima-o na tela.

// Input
// Uma linha com um número real t (−273.15≤t≤105).

// Output
// Uma linha com o número t convertido para Fahrenheit.

// Note
// Para cada caso de teste, se sua resposta é um valor y e a do juiz é o valor z, sua resposta será considerada correta se |y−z|≤10−5.

#include <stdio.h>

int main () {
    double t;
    double fahrenheit;

    printf("Digite um numero real em Celsius: \n");
    scanf("%lf", &t);

    fahrenheit = (t  * 9/5) + 32;

    printf("%lf", fahrenheit);

    return 0;
}