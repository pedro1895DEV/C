#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void* mallocx(size_t n){
    void* ptr = malloc(n);
    if(ptr==NULL){
        printf("Erro mallocx");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

typedef struct piloto {
    char nome[31];
    char tempo[21];
} piloto;

void imprime_piloto(piloto *p, int tempo, int pos) {
        int total = tempo;
        int minuto = total / 60000;
        total = total % 60000;

        int segundos = total / 1000;
        int ms = total % 1000;
        printf("%d. %s - %d:%02d.%03d\n", pos, p->nome, minuto, segundos, ms);
}

void le_piloto(piloto *p) {
    scanf("%s", p->nome);
    getchar();
    fgets(p->tempo, sizeof(p->tempo), stdin);
}

void listar_pilotos(piloto *v_piloto, int n, int *tempoFinal) {
    for (int i = 0; i < n; i++) {
        imprime_piloto(&v_piloto[i], tempoFinal[i], i + 1);
    }
}

void somar_tempo(piloto *v_piloto, int n, int* tempoFinal) {
    double volta1;
    double volta2;
    double volta3;
    for (int i = 0; i < n; i++) {
        sscanf(v_piloto[i].tempo, "%lf %lf %lf", &volta1, &volta2, &volta3);
        tempoFinal[i] = (int)round((volta1 + volta2 + volta3) * 1000);
    }
}

void swap(int* v, piloto *v_piloto,int i, int j) {
    int t = v[i];
    v[i] = v[j];
    v[j] = t;

    piloto temp = v_piloto[i];
    v_piloto[i] = v_piloto[j];
    v_piloto[j] = temp; 
}

void bubble_sort(int *v, piloto *v_piloto, size_t size) {
    int swapped = 1;
    for (int i = 0; i < size - 1 && swapped; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v, v_piloto, j, j + 1);
                swapped = 1;
            }
        }
    }
}

int main () {
    int n;
    scanf("%d", &n);
    piloto *v_piloto = mallocx(n * sizeof(piloto));
    int* tempoFinal = mallocx(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        le_piloto(&v_piloto[i]);
    }
    somar_tempo(v_piloto, n, tempoFinal);
    bubble_sort(tempoFinal, v_piloto, n);

    listar_pilotos(v_piloto, n, tempoFinal);

    free(v_piloto);
    free(tempoFinal);
    return 0;
}