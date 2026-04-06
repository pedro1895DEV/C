#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int *v1, int *v2, size_t size, int m) {

    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (v1[j] % m < v2[k] % m) {
            v[i] = v1[j++];
        } else if (v1[j] % m  > v2[k] % m) {
            v[i] = v2[k++];
        }
        else {
            if (v1[j] % 2 == 0 && v2[k] % 2 != 0) {
                v[i] = v2[k++];
            } else if (v1[j] % 2 == 0 && v2[k] % 2 == 0) {
                if (v1[j] < v2[k]) {
                    v[i] = v1[j++];
                } else {
                    v[i] = v2[k++];
                }
            } else if (v1[j] % 2 != 0 && v2[k] % 2 != 0) {
                if (v1[j] > v2[k]) {
                    v[i] = v1[j++];
                } else {
                    v[i] = v2[k++];
                }
            }
            else if (v1[j] % 2 != 0 && v2[k] % 2 == 0) {
                v[i] = v1[j++];
            }
        }
    }

    while (j < size_v1) {
        v[i++] = v1[j++];
    }
    while (k < size_v2) {
        v[i++] = v2[k++];
    }
}

void mergesort(int *v, size_t size, int m) {
    size_t mid;
    if (size > 1) {
        mid = size / 2;
        int v1[mid];
        int v2[size - mid];
        int i;
        for (i = 0; i < mid; i++) {
            v1[i] = v[i];
        }
        for (i = mid; i < size; i++) {
            v2[i - mid] = v[i];
        }
        mergesort(v1, mid, m);
        mergesort(v2, size - mid, m);
        merge(v, v1, v2, size, m);
    }
}

int main () {
    int n, m;
    scanf("%d %d", &n, &m);

    int* valores = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &valores[i]);
    }

    mergesort(valores, n, m);

    for (int i = 0; i < n; i++) {
        printf("%d\n", valores[i]);
    }

    free(valores);
    return 0;
}