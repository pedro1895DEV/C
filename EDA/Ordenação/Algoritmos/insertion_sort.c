#include <stdio.h>

void insertion_sort (int* v, size_t size) { // Função insertion_sort que recebe o ponteiro v que aponta para a cabeça do vetor
    int i, j, chosen; // Declaração das três variáveis i, j e chosen que serão usadas na comparação dos valores
    for (int i = 1; i < size; i++) { // Loop que percorre de 1 até o valor de size, pulando o primeiro elemento que já está "sorted"
        chosen = v[i]; // Escolhe o elemento imediato ao início do loop (que inicia na posição arr[1])
        for (j = i - 1; (j >= 0) && (chosen < v[j]); j--) { // Inicia J começando na posição anterior a i (0 no primeiro caso); Quando j for maior ou igual a 0 e o valor chosen for menor que o valor atual v[j], decrementa o valor de j
            v[j + 1] = v[j]; // Troca a posição de v[j] uma posição para a direita
        }
        v[j + 1] = chosen; // Coloca o valor chosen na posição correta
    }
}


int main () {
    int valores[] = {8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(valores) / sizeof(valores[0]);

    insertion_sort(valores, n);
    for (int i = 0; i < n; i++) {
        printf("%d \n", valores[i]);
    }
    return 0;
}