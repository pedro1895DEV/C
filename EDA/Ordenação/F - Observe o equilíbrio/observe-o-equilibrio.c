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

static void merge (int *v, int *v1, int *v2, size_t size) {
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (v1[j] <= v2[k]) {
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

void merge_sort(int *v, size_t size) {
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

        merge_sort(v1, mid);
        merge_sort(v2, size - mid);

        merge(v, v1, v2, size);

        free(v1);
        free(v2);
    }
}

int main () {
    int n;
    scanf("%d", &n);
    int* valores = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &valores[i]);
    }

    merge_sort(valores, n);

    int equilibrada = 1;
    int l = 0;
    int r = n - 1;
    while (l < r) {
        if (valores[l] == 0 || valores[l + 1] == 0) {
            l++;
        } 
        else if (valores[l] % valores[l + 1] == 0 || valores[l+1] % valores[l] == 0) {
            l++;
        }
        else {
            equilibrada = 0;
            break;
        }
    }

    if (equilibrada == 1) {
        printf("Sim");
    }
    if (equilibrada == 0) {
        printf("Nao");
    }

    free(valores);
    return 0;
}