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

typedef struct valores {
    int numero;
    int index;
}valor;

static void merge (valor *v, valor *v1, valor *v2, size_t size) {
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (v1[j].numero <= v2[k].numero) {
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

void merge_sort(valor *v, size_t size) {
    size_t mid;
    if (size > 1) {
        mid = size / 2;

        valor *v1 = mallocx(sizeof(valor) * mid);
        valor *v2 = mallocx(sizeof(valor) * (size - mid));

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

int binary_search(valor *v, int n, int c) {
    int l = 0;
    int r = n - 1;
    int achou = 0;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        int soma = v[l].numero + v[r].numero;
        if (c == soma) {
            printf("%d %d", v[l].index + 1, v[r].index + 1);
            achou = 1;
            break;
        } else if (c < soma) {
            r--;
        } else {
            l++;
        }
    }
    if (!achou) {
        printf("-1");
    }
}

int main () {
    int n, c;
    scanf("%d %d", &n, &c);
    valor* sequencia = malloc(n * sizeof(valor));

    for (int i = 0; i < n; i++) {
        scanf("%d", &sequencia[i].numero);
        sequencia[i].index = i;
    }

    merge_sort(sequencia , n);

    binary_search(sequencia, n, c);
    

    return 0;
}