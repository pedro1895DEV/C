#include <stdio.h>
#include <stdlib.h>

typedef struct sequencia {
    int vetor;
    int alvos;
}sequencia;

static void merge(sequencia *v, sequencia *v1, sequencia *v2, size_t size) {
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (v1[j].vetor <= v2[k].vetor) {
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

void merge_sort(sequencia *v, size_t size) {
    size_t mid;
    if (size > 1) {
        mid = size / 2;

        sequencia *v1 = malloc(sizeof(sequencia) * mid);
        sequencia *v2 = malloc(sizeof(sequencia) * (size - mid));

        int i;
        for (i = 0; i < mid; i++) {
            v1[i] = v[i];
        }
        for (i = mid; i < size; i++) {
            v2[i - mid] = v[i];
        }

        merge_sort(v1, mid);
        merge_sort(v2, size - mid);

        merge(v, v1, v2, size);

        free(v1);
        free(v2);
    }
}

int binary_search(sequencia *v, int n, int alvos) {
    int l = 0;
    int r = n - 1;
    int primeiro = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (v[mid].vetor == alvos) {
            primeiro = mid;
            r = mid - 1;
        } else if (alvos < v[mid].vetor) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return primeiro;
}

int binary_search2(sequencia *v, int n, int alvos) {
    int l = 0;
    int r = n -1;
    int ultimo = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (v[mid].vetor == alvos) {
            ultimo = mid;
            l = mid + 1;
        } else if (alvos < v[mid].vetor) {
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

    sequencia* vetor = malloc(sizeof(sequencia) * n);
    sequencia* alvos = malloc(sizeof(sequencia) * q);

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i].vetor);
    }

    for (int i = 0; i < q; i++) {
        scanf("%d", &alvos[i].alvos);
    }

    merge_sort(vetor, n);
    for (int i = 0; i < q; i++) {
        int primeiro = binary_search(vetor, n, alvos[i].alvos);
        int segundo = binary_search2(vetor, n, alvos[i].alvos);

        if (primeiro == -1) {
            printf("-1\n");
        } else {
            printf("%d %d\n", primeiro + 1, segundo + 1);
        }
    }

    return 0;
}