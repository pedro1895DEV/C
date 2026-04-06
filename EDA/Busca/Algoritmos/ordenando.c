#include <stdio.h>
#include <stdlib.h>

void static merge(int *v, int *v1, int *v2, int n) {
    size_t size_v1 = n / 2;
    size_t size_v2 = n - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (v1[j] <= v2[k]) {
            v[i] = v1[j++]; 
        } else {
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

void merge_sort(int *v, size_t size) {
    size_t mid;
    if (size > 1) {
        mid = size / 2;

        int* v1 = malloc(sizeof(int) * mid);
        int* v2 = malloc(sizeof(int) * (size - mid));

        int i;
        for (i = 0; i < mid; i++) {
            v1[i] = v[i];
        }

        for (i = mid; i < size; i++) {
            v2[i - mid] = v[i];
        }

        merge_sort(v1,mid);
        merge_sort(v2, size - mid);

        merge(v, v1, v2, size);

        free(v1);
        free(v2);
    }
}

int main () {
    int n;
    scanf("%d", &n);

    // int* numeros = malloc(sizeof(int) * n);

    char** nomes = malloc(sizeof(char*) * n);

    for (int i = 0; i < n; i++) {
        nomes[i] = malloc(sizeof(char) * 100);
        scanf("%s", nomes[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", nomes[i]);
    }

    // for (int i = 0; i < n; i++) {
    //     scanf("%d", &numeros[i]);
    // }

    // merge_sort(numeros, n);
    // int diferente = 1;
    // for (int i = 0; i < n - 1; i++) {
    //     if(numeros[i] != numeros[i + 1]) {
    //         diferente++;
    //     }
    // }

    // printf("%d", diferente);
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     int valor;
//     int freq;
// } Elemento;

// int cmp_valor(const void *a, const void *b) {
//     return (*(int *)a - *(int *)b);
// }

// int comparador(const void *a, const void *b) {
//     Elemento *ea = (Elemento *)a;
//     Elemento *eb = (Elemento *)b;
//     if (eb->freq != ea->freq)
//         return eb->freq - ea->freq;
//     return eb->valor - ea->valor;
// }

// int main() {
//     int n;
//     scanf("%d", &n);

//     int *v = malloc(sizeof(int) * n);
//     for (int i = 0; i < n; i++)
//         scanf("%d", &v[i]);

//     // Ordena para agrupar elementos iguais
//     qsort(v, n, sizeof(int), cmp_valor);

//     // Conta frequências
//     Elemento *elementos = malloc(sizeof(Elemento) * n);
//     int qtd = 0;

//     for (int i = 0; i < n; ) {
//         int j = i;
//         while (j < n && v[j] == v[i]) j++;
//         elementos[qtd].valor = v[i];
//         elementos[qtd].freq = j - i;
//         qtd++;
//         i = j;
//     }

//     // Ordena pelo critério do problema
//     qsort(elementos, qtd, sizeof(Elemento), comparador);

//     // Imprime
//     int primeiro = 1;
//     for (int i = 0; i < qtd; i++) {
//         for (int j = 0; j < elementos[i].freq; j++) {
//             if (!primeiro) printf(" ");
//             printf("%d", elementos[i].valor);
//             primeiro = 0;
//         }
//     }
//     printf("\n");

//     free(v);
//     free(elementos);
//     return 0;
// }