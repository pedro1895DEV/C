#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* mallocx(size_t n){
    void* ptr = malloc(n);
    if(ptr==NULL){
        printf("Erro mallocx");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

typedef struct autores {
    char nome[31];
    int numeroPublicacoes;
    int indiceH;
}autor;

void le_autores(autor *a) {
    scanf("%s %d", a->nome, &a->numeroPublicacoes);

}

void le_citacoes (int* citacoes, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &citacoes[i]);
    }
}
static void merge (int *v, int *v1, int *v2, size_t size) {
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (v1[j] >= v2[k]) {
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

static void merge_autor (autor *v, autor *v1, autor *v2, size_t size) {
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (v1[j].indiceH > v2[k].indiceH) {
            v[i] = v1[j++];
        }
        else if (v1[j].indiceH == v2[k].indiceH)  {
            if (strcmp(v1[j].nome, v2[k].nome) < 0) {
                v[i] = v1[j++];
            } else {
                v[i] = v2[k++];
            }
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


void merge_sort_autor(autor *autores, size_t size) {
    size_t mid;
    if (size > 1) {
        mid = size / 2;

        autor *v1 = mallocx(sizeof(autor) * mid);
        autor *v2 = mallocx(sizeof(autor) * (size - mid));

        int i;

        for (int i = 0; i < mid; i++) {
            v1[i] = autores[i];
        }

        for (i = mid; i < size; i++) {
            v2[i - mid] = autores[i];
        }

        merge_sort_autor(v1, mid);
        merge_sort_autor(v2, size - mid);

        merge_autor(autores, v1, v2, size);

        free(v1);
        free(v2);
    }
}

int main () {
    int n;
    scanf("%d", &n);
    autor *v_autores = mallocx(n * sizeof(autor));
    int** numeroCitacoes = mallocx(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        le_autores(&v_autores[i]);
        numeroCitacoes[i] = mallocx(v_autores[i].numeroPublicacoes * sizeof(int));
        le_citacoes(numeroCitacoes[i], v_autores[i].numeroPublicacoes);
    }

    for (int i = 0; i < n; i++) {
        merge_sort(numeroCitacoes[i], v_autores[i].numeroPublicacoes);
    }
    
    for (int i = 0; i < n; i++) {
        v_autores[i].indiceH = 0;
        for (int j = 0; j < v_autores[i].numeroPublicacoes; j++) {
            if (numeroCitacoes[i][j] >= j + 1) {
                v_autores[i].indiceH = j + 1;
            } else {
                break;
            }
        }
    }
    merge_sort_autor(v_autores, n);

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", v_autores[i].nome, v_autores[i].indiceH);
    }

    return 0;
}