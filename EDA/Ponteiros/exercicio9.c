// Exercício 9
// Implemente uma função getline que leia uma linha inteira e retorne uma string com
// os caracteres lidos independente do número de caracteres. A string deverá ser alocada
// dinâmicamente de modo a não desperdiçar espaço. Sua função deverá possuir a seguinte
// assinatura:
// char* getline(void);
// Dica: para esta função é interessante utilizar as funções getchar() e realloc().

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getline(void);

int main (void) {
    char* linha = getline();
    printf("%s", linha);
    free(linha);
    return 0;
}

char* getline(void) {
    int capacidade = sizeof(char);
    int n = 0;
    char* string = malloc(capacidade);
    if (string == NULL) {
        printf("Erro de alocação.\n");
        exit(EXIT_FAILURE);
    }
    char c;
    while ((c = getchar()) != '\n') {
        if (n >= capacidade - 1) {
            capacidade *= 2;
            string = realloc(string, capacidade);
            if (string == NULL) {
                printf("Erro de alocação.\n");
                exit(EXIT_FAILURE);
            }
        }
        string[n++] = c;
    }
    string[n] = '\0';
    string = realloc(string, n + 1);

    return string;
}