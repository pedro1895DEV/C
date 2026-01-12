// Média Ponderada

// Leia seis notas de avaliações de uma disciplina e calcule a média ponderada de acordo com a seguinte fórmula:
// ∑6i=1pi⋅ni∑6i=1pi

// Em que ni corresponde à nota e pi ao peso da i-ésima avaliação. Os pesos são os seguintes: p1=p2=p3=1 e p4=p5=p6=2.

// Input
// A entrada consiste de seis números reais, ni(0≤ni≤10), separados por um espaço, que correspondem às nota das seis avaliações.

// Output
// Imprima em uma linha a média ponderada das seis avaliações.

#include <stdio.h>

int main () {
    double p1 = 1;
    double p2 = 1;
    double p3 = 1;
    double p4 = 2;
    double p5 = 2;
    double p6 = 2;
    double media;

    printf("Digite as seis notas: ");
    scanf("%lf %lf %lf %lf %lf %lf", &p1, &p2, &p3, &p4, &p5, &p6);

    media = ((p1 + p2 + p3) + ((p4 + p5 + p6) * 2)) / 9;

    printf("%lf", media);

    return 0;
}