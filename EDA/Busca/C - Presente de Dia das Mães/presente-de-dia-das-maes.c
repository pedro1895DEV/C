#include <stdio.h>
#include <stdlib.h>

static void merge(int *v, int *v1, int *v2, size_t size) {
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
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

        int *v1 = malloc(sizeof(int) * mid);
        int *v2 = malloc(sizeof(int) * (size - mid));

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

int viavel (int *v, int n, int m, int mid) {
    int soma = 0;
    for(int i = 0; i < n; i++) {
        soma += v[i] / mid;
    }
    return soma>=m;
}

int binary_search(int *v, int n, int m) {
    int l = 1;
    int r = v[n - 1];
    int chocolates = 0;
    
    while (l <= r) {
        int mid = l + (r -  l) / 2;
        if (viavel(v, n, m, mid)) {
            chocolates = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return chocolates;
}

int main () {
    int n, m;
    scanf("%d %d", &n, &m);

    int* quantidadeChocolates = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &quantidadeChocolates[i]);
    }

    merge_sort(quantidadeChocolates, n);
    printf("%d", binary_search(quantidadeChocolates, n, m));

    return 0;
}