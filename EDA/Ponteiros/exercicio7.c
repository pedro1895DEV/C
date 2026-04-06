// Exercício 7
// Crie uma função min_max que recebe um vetor de inteiros de n elementos e retorne as
// posições dos valores mínimo e máximo do vetor através de dois parâmetros inteiros l e r
// passados por “referência” para função. Em caso de empate, a função deverá considerar a
// posição mais à esquerda possível. Sua função deverá possuir a seguinte assinatura:
// void min_max(int* v,int n, int* l,int* r);

#include <stdio.h>
#include <stdlib.h>

void min_max(int* v, int n, int* l, int* r) {
        for (int i = 0; i < n; i++) {
            if (v[i] < v[*l]) {
                *l = i;
            }
            if (v[i] > v[*r]) {
                *r = i;
            }
        }       
}

int main (void) {
    int n = 15;
    int values[] = {2, 2, 6, 3, 10, 10, 1, 2, 8, 3, 5, 1, 3, 10, 7};

    int* vetor = values;
    int minimo = 0;
    int maximo = 0;
    min_max(vetor, n, &minimo, &maximo);
    printf("Minimo: %d\n", minimo);
    printf("Maximo: %d", maximo);
    return 0;
}


    // int* vetor = malloc(sizeof(int));
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++) {
    //     vetor[i] = i;
    // }
