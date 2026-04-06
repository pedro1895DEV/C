#include <stdio.h>

int busca_sequencial (int* v, size_t n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (v[i] == key) {
            return i;
        }
    }
    return -1;
}

int main () {
    int vetor[] = {5, 2, 1, 6, 7, 8, 11, 22};
    printf("%d", busca_sequencial(vetor, 8, 22));

    return 0;
}