// Exercício 3
// Faça um programa que leia um inteiro n e crie um vetor de n números reais. O vetor deve
// ser alocado de maneira dinâmica.

#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int n;
    scanf("%d", &n);

    int* vetor = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        vetor[i] = i;
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", vetor[i]);
    }

    free(vetor);
    return 0;
}