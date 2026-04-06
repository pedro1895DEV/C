// Exercício 8
// Crie uma função que receba n notas de um aluno e retorne a sua situação. A função também deverá calcular a média e armazená-la em uma das variáveis passadas por “referência”.
// A situação do aluno deverá ser ‘A’ em caso de aprovação, ’R’ em caso de reprovação. Considere que a média para aprovação é 6.0. Sua função deverá possuir a seguinte assinatura:
// char calcula_situacao(double* v, int n, double* media);

#include <stdio.h>
#include <stdlib.h>

char calcula_situacao(double* v, int n, double* media);

int main (void) {
    int n = 3;
    double values[] = {8.1, 8.0, 9.6};
    double soma = 0;

    double* vetor = values;

    char resultado = calcula_situacao(vetor, n, &soma);
    return 0;
}

char calcula_situacao(double* v, int n, double* media) {
    for (int i = 0; i < n; i++) {
        *media += v[i]; 
    }
    if (*media / n < 6.0) {
        printf("R");
    } else if (*media / n > 6.0) {
        printf("A");
    }
}