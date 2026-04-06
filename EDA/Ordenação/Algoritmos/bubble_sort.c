#include <stdio.h>

void swap(int* v, int i, int j) { // função auxiliar que recebe um ponteiro que aponta para o primeiro elemento do vetor int* v, i a posição atual e j a próxima posição
    int t = v[i]; // cria uma var temporária para o elemento atual
    v[i] = v[j]; // troca de lugar o elemento atual com o próximo elemento (i e j)
    v[j] = t; // Coloca o valor de v[j] como o valor original de v[i]
}

void bubble_sort(int *v, size_t size) { // função principal do algoritmo que recebe a cabeça do vetor e o tamanho do mesmo
    int swapped = 1; // Inicia a variável swapped como 1 / true
    for (int i = 0; i < size - 1 && swapped; i++) { // Começa a percorrer o array da primeira posição até a última enquanto swapped for 1 e não tiver chego até o último elemento do array
        swapped = 0; // seta o valor de swapped para 0, para ser a última ordenação
        for (int j = 0; j < size - i - 1; j++) { // Loop interno começando na posição 0, enquanto j for menor que o tamanho do vetor - i - 1 vai aplicar o if
            if (v[j] > v[j + 1]) { //  se a posição de j for maior que a próxima posição
                swap(v, j, j + 1); // usa a função auxiliar swap para trocar os dois valores de posição
                swapped = 1; // altera novamente o valor de swapped para 1 para continuar a execução do loop
            }
        }
    }
}

int main () {
    int valores[] = {7, 12, 9, 11, 3};
    bubble_sort(valores, 5);
    
    for (int i = 0; i < 5; i++) {
        printf("%d \n", valores[i]);
    }
    return 0;
}