#include <stdio.h>

int main(void) {
    int i, j;
    int numeros[100];
    int resposta = 1;
    for (i = 0; i < 100; i++) {
        printf("Digite o elemento %d: ", i);
        scanf("%d", &numeros[i]);
    }
    for (i = 0; i < 100 && resposta; i++) {
        for (j = i + 1; j < 100 && resposta; j++) {
            if (numeros[i] == numeros[j])
                resposta = 0;
        }
    }
    if (resposta) {
        printf("Todos os elementos s~ao distintos.\n");
    }
    else {
        printf("Existem elementos repetidos.\n");
    }
    return 0;
}