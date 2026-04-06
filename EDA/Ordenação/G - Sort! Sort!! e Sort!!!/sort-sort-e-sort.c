#include <stdio.h>
#include <stdlib.h>

void* mallocx(size_t n){
    void* ptr = malloc(n);
    if(ptr==NULL){
        printf("Erro mallocx");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

int comparar(int a, int b, int m) {
    int resto_a = a % m;
    int resto_b = b % m;

    if (resto_a != resto_b) {
        return resto_a < resto_b;
    }
    if (a % 2 == 0 && b % 2 == 0) {
        return a < b;
    }
    if (a % 2 != 0 && b % 2 != 0) {
        return a > b;
    }
    if (a % 2 != 0 && b % 2 == 0) {
        return 1;
    }
    return 0;
}

static void merge (int *v, int *v1, int *v2, size_t size, int m) {
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (comparar(v1[j], v2[k], m)) {
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

void merge_sort(int *v, size_t size, int m) {
    size_t mid;
    if (size > 1) {
        mid = size / 2;

        int *v1 = mallocx(sizeof(int) * mid);
        int *v2 = mallocx(sizeof(int) * (size - mid));

        int i;

        for (int i = 0; i < mid; i++) {
            v1[i] = v[i];
        }

        for (i = mid; i < size; i++) {
            v2[i - mid] = v[i];
        }

        merge_sort(v1, mid, m);
        merge_sort(v2, size - mid, m);

        merge(v, v1, v2, size, m);

        free(v1);
        free(v2);
    }
}

int main () {
    int n, m;
    scanf("%d %d", &n, &m);
    int* valores = mallocx(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &valores[i]);
    }

    merge_sort(valores, n, m);

    for (int i = 0; i < n; i++) {
        printf("%d\n", valores[i]);
    }
    return 0;
}