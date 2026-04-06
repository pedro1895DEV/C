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

typedef struct alunos {
    char nomes[11];
    int repeticoes;
}alunos;


static void merge (alunos *v, alunos *v1, alunos *v2, size_t size) {
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (strcmp(v1[j].nomes, v2[k].nomes) <= 0) {
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

void merge_sort(alunos *v, size_t size) {
    size_t mid;
    if (size > 1) {
        mid = size / 2;

        alunos *v1 = mallocx(sizeof(alunos) * mid);
        alunos *v2 = mallocx(sizeof(alunos) * (size - mid));

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
    alunos* v_alunos = mallocx(n * sizeof(alunos));

    for (int i = 0; i < n; i++) {
        scanf("%s", v_alunos[i].nomes);
        v_alunos[i].repeticoes = 1;
    }

    merge_sort(v_alunos, n);

    int contagem = 0;
    for (int i = 1; i < n; i++) {
        if (strcmp(v_alunos[i].nomes, v_alunos[i - 1].nomes) == 0) {
            v_alunos[contagem].repeticoes++;
        } else {
            contagem = i;
        }
    }

    int melhor = 0;
    for (int i = 1; i < n; i++) {
        if (strcmp(v_alunos[i].nomes, v_alunos[i - 1].nomes) != 0) {
            if (v_alunos[i].repeticoes > v_alunos[melhor].repeticoes) {
                melhor = i;
            } else if (v_alunos[i].repeticoes == v_alunos[melhor].repeticoes) {
                if (strcmp(v_alunos[i].nomes, v_alunos[melhor].nomes) < 0) {
                    melhor = i;
                }
            }
        }
    }
    printf("%s %d", v_alunos[melhor].nomes, v_alunos[melhor].repeticoes);

    free(v_alunos);

    return 0;
}