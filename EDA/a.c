#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
    int frequencia;
} Item;

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main () {
    int arr[] = {1, 2, 2, 3, 7, 3};
    int tamanho = 6;

    qsort(arr, tamanho, sizeof(int), comparar);

    Item itens[10];
    int qtd = 0;

    int contador = 1;

    for (int i = 1; i < tamanho; i++) {
        if (arr[i] == arr[i - 1]) {
            contador++;
        } else {
            itens[qtd].valor = arr[i - 1];
            itens[qtd].frequencia = contador;
            qtd++;

            contador = 1;
        }
    }

    // último grupo
    itens[qtd].valor = arr[tamanho - 1];
    itens[qtd].frequencia = contador;
    qtd++;

    // impressão correta
    for (int i = 0; i < qtd; i++) {
        printf("%d aparece %d vezes\n", itens[i].valor, itens[i].frequencia);
    }

    return 0;
}