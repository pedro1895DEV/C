#include <stdio.h>
#include <stdlib.h>

typedef struct informacoes {
    int numero;
    int frequencia;
}informacoes;

void merge(informacoes *v, informacoes *v1, informacoes *v2, size_t size) {

    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (v1[j].numero <= v2[k].numero) {
            v[i].numero = v1[j++].numero;
        }
        else {
            v[i].numero = v2[k++].numero;
        }
    }

    while (j < size_v1) {
        v[i++].numero = v1[j++].numero;
    }
    while (k < size_v2) {
        v[i++].numero = v2[k++].numero;
    }
}

void mergesort(informacoes *v, size_t size) {
    size_t mid;
    if (size > 1) {
        mid = size / 2;
        informacoes v1[mid];
        informacoes v2[size - mid];
        int i;
        for (i = 0; i < mid; i++) {
            v1[i].numero = v[i].numero;
        }
        for (i = mid; i < size; i++) {
            v2[i - mid].numero = v[i].numero;
        }
        mergesort(v1, mid);
        mergesort(v2, size - mid);
        merge(v, v1, v2, size);
    }
}

void merge2(informacoes *v, informacoes *v1, informacoes *v2, size_t size) {

    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (v1[j].frequencia > v2[k].frequencia || (v1[j].frequencia == v2[k].frequencia && v1[j].numero > v2[k].numero)) {
            v[i] = v1[j++];
        }
        else {
            v[i] = v2[k++];
        }
    }

    while (j < size_v1) {
        v[i++] = v1[j++];
    }
    while (k < size_v2) {
        v[i++] = v2[k++];
    }
}

void mergesort2(informacoes *v, size_t size) {
    size_t mid;
    if (size > 1) {
        mid = size / 2;
        informacoes v1[mid];
        informacoes v2[size - mid];
        int i;
        for (i = 0; i < mid; i++) {
            v1[i] = v[i];
        }
        for (i = mid; i < size; i++) {
            v2[i - mid]= v[i];
        }
        mergesort2(v1, mid);
        mergesort2(v2, size - mid);
        merge2(v, v1, v2, size);
    }
}

int main () {
    int n;
    scanf("%d", &n);
    informacoes* vetor = malloc(sizeof(informacoes) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i].numero);
    }

    mergesort(vetor, n);

    informacoes *valores = malloc(sizeof(informacoes) * n);

    int qtd = 0;
    int contador = 1;

    for(int i = 1; i < n; i++) {
        if (vetor[i].numero == vetor[i - 1].numero) {
            contador++;
        } else {
            valores[qtd].numero = vetor[i -  1].numero;
            valores[qtd].frequencia = contador;
            qtd++;

            contador = 1;
        }
    }

    valores[qtd].numero = vetor[n  - 1].numero;
    valores[qtd].frequencia = contador;
    qtd++;

    mergesort2(valores, qtd);

    for (int i = 0; i < qtd; i++) {
        for (int j = 0; j < valores[i].frequencia; j++) {
            printf("%d ", valores[i].numero);
        }
    }
    free(vetor);
    free(valores);
    return 0;
}