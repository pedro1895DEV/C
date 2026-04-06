#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
    int target;
}valores;

void merge(valores *v, valores *v1, valores *v2, size_t size) {

    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (v1[j].valor <= v2[k].valor) {
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

void mergesort(valores *v, size_t size) {
    size_t mid;
    if (size > 1) {
        mid = size / 2;
        valores v1[mid];
        valores v2[size - mid];
        int i;
        for (i = 0; i < mid; i++) {
            v1[i] = v[i];
        }
        for (i = mid; i < size; i++) {
            v2[i - mid] = v[i];
        }
        mergesort(v1, mid);
        mergesort(v2, size - mid);
        merge(v, v1, v2, size);
    }
}

int binary_search(valores *v, int n, int target) {
    int l = 0;
    int r = n - 1;
    int primeiro = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (v[mid].valor == target) {
            primeiro = mid;
            r = mid - 1;
        } else if (target < v[mid].valor) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return primeiro;
}

int binary_search2(valores *v, int n, int target) {
    int l = 0;
    int r = n - 1;
    int ultimo = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (v[mid].valor == target) {
            ultimo = mid;
            l = mid + 1;
        } else if (target < v[mid].valor) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ultimo;
}


int main () {
    int n, q;
    scanf("%d %d", &n, &q);

    valores* sequencia = malloc(sizeof(valores) * n);
    valores* valoresPesquisados = malloc(sizeof(valores) * q);

    for (int i = 0; i < n; i++) {
        scanf("%d", &sequencia[i].valor);
    }

    for (int i = 0; i < q; i++) {
        scanf("%d", &valoresPesquisados[i].target);
    }

    mergesort(sequencia, n);

    for (int i = 0; i < q; i++) {
        int primeiro = binary_search(sequencia, n, valoresPesquisados[i].target);
        int segundo = binary_search2(sequencia, n, valoresPesquisados[i].target);
        if (primeiro == -1) {
            printf("-1\n");
        } else {
            printf("%d %d\n", primeiro + 1, segundo + 1);
        }
    }

    free(sequencia);
    free(valoresPesquisados);
    return 0;
}