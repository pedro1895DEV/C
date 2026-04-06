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
        if (strlen(v1[j]) <= strlen(v2[k])) {
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
    char** str = mallocx(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        str[i] = mallocx(12 * sizeof(char));
        fgets(str[i], 12, stdin);
        str[i][strcspn(str[i], "\n")] = '\0';
    }

    ordena(str, n);

    for (int i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }

    for (int i = 0; i < n; i++) {
        free(str[i]);
    }
    free(str);

    return 0;
}