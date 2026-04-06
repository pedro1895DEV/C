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

static void merge(char* v[], char *v1[], char *v2[], size_t size) {
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    for (i = 0; j < size_v1 && k < size_v2; i++) {
        if (strcmp(v1[j], v2[k]) <= 0) {
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

void ordena(char *v[], int n) {
    size_t mid;
    if (n > 1) {
        mid = n / 2;
        char **v1 = mallocx(sizeof(char*) * mid);
        char **v2 = mallocx(sizeof(char*) * (n - mid));
        int i;
        for (i = 0; i < mid; i++) {
            v1[i] = v[i];
        }
        for (i = mid; i < n; i++) {
            v2[i - mid] = v[i];
        }
        ordena(v1, mid);
        ordena(v2, n - mid);
        merge(v, v1, v2, n);
        free(v1);
        free(v2);
    }
}

int main () {
    int n;
    scanf("%d", &n);
    getchar();
    char** horarios = mallocx(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        horarios[i] = mallocx(20 * sizeof(char));
        fgets(horarios[i], 20, stdin);
        horarios[i][strcspn(horarios[i], "\n")] = '\0';
    }

    ordena(horarios, n);

    int* chegada = mallocx(n * sizeof(int));
    int* saida = mallocx(n * sizeof(int));
    char** saidas_str = mallocx(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        int hora1, minuto1, segundo1;
        int hora2, minuto2, segundo2;
        sscanf(horarios[i], "%d:%d:%d %d:%d:%d", &hora1, &minuto1, &segundo1, &hora2, &minuto2, &segundo2);
        chegada[i] = hora1 * 3600 + minuto1 * 60 + segundo1;
        saidas_str[i] = mallocx(9 * sizeof(char));
        strncpy(saidas_str[i], horarios[i] + 9, 8);
        saidas_str[i][8] = '\0';
    }

    ordena(saidas_str, n);
    
    for (int i = 0; i < n; i++) {
        int h, m, s;
        sscanf(saidas_str[i], "%d:%d:%d", &h, &m, &s);
        saida[i] = h * 3600 + m * 60 + s;
        free(saidas_str[i]);
    }
    free(saidas_str);

    int atual = 0;
    int maximo = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && saida[j] < chegada[i]) {
            atual--;
            j++;
        }
        atual++;
        if (atual > maximo) {
            maximo = atual;
        }
    }

    printf("%d\n", maximo);

    for (int i = 0; i < n; i++) {
        free(horarios[i]);
    }
    free(horarios);
    free(chegada);
    free(saida);
    return 0;
}