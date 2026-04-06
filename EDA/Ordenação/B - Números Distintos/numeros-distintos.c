#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *v;
    size_t capacity;
    size_t size;
} numeros;

void* mallocx(size_t n){
    void* ptr = malloc(n);
    if(ptr==NULL){
        printf("Erro mallocx");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void inicializar_numeros(numeros **arr) {
    (*arr) = mallocx(sizeof(numeros));
    (*arr) -> capacity = 4;
    (*arr) -> size = 0;
    (*arr)->v = mallocx(sizeof(int) * 4);
}

void double_capacity(numeros *arr) {
    arr->capacity *= 2;
    arr->v = realloc(arr->v, sizeof(int) * arr->capacity);
}

void numeros_push(numeros *arr, int x)  {
    if (arr->size == arr->capacity) {
        double_capacity(arr);
    }
    arr->v[arr->size] = x;
    arr->size++;
}

void imprimir_array(numeros *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->v[i]);
    }
}

size_t dynamic_array_size(numeros *arr) {
    return arr->size;
}

static void merge (numeros *v, int *v1, int *v2, size_t size) {
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (v1[j] <= v2[k]) {
            v->v[i] = v1[j++];
        }
        else {
            v->v[i] = v2[k++];
        }
    }

    while (j < size_v1) {
        v->v[i++] = v1[j++];
    }

    while (k < size_v2) {
        v->v[i++] = v2[k++];
    }
}

void merge_sort(numeros *v, size_t size) {
    size_t mid;
    if (size > 1) {
        mid = size / 2;

        int *v1 = mallocx(sizeof(int) * mid);
        int *v2 = mallocx(sizeof(int) * (size - mid));

        int i;

        for (int i = 0; i < mid; i++) {
            v1[i] = v->v[i];
        }

        for (i = mid; i < size; i++) {
            v2[i - mid] = v->v[i];
        }
        numeros temp1, temp2;
        temp1.v = v1;
        temp1.size = mid;
        temp1.capacity = mid;
        
        temp2.v = v2;
        temp2.size = size - mid;
        temp2.capacity = size - mid;

        merge_sort(&temp1, mid);
        merge_sort(&temp2, size - mid);

        merge(v, v1, v2, size);

        free(v1);
        free(v2);
    }
}

int main () {
    int n;
    scanf("%d", &n);
    numeros *arr;
    inicializar_numeros(&arr);


    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        numeros_push(arr, num);
    }    

    merge_sort(arr, dynamic_array_size(arr));
    int sequencia = 0;
    if (arr->size > 0) {
        sequencia = 1;
        for (int i = 1; i < dynamic_array_size(arr); i++) {
            if (arr->v[i] != arr->v[i - 1]) {
                sequencia += 1;
            }
        }
    }
    printf("%d", sequencia);
    free(arr->v);
    free(arr);

    return 0;
}