// Ordenação de Três
// Elabore um programa que leia três inteiros e os imprima em ordem crescente.

// Input
// A entrada consiste de uma linha com três inteiros A, B e C (0 ≤ A, B, C ≤ 10⁹ ) separados por um espaço.

// Output
// Imprima uma linha com os três inteiros lidos em ordem crescente e separados por um espaço.

#include <stdio.h>

int main () {
    int a, b, c;

    printf("Digite 3 inteiros: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a <= b && b <= c) {
        printf("%d %d %d", a, b, c);
    }
    else if (a <= c && c <= b) {
        printf("%d %d %d", a, c, b);
    }
    else if (b <= a && a <= c) {
        printf("%d %d %d", b, a, c);
    }
    else if (b <= c && c <= a) {
        printf("%d %d %d", b, c, a);
    }
    else if (c <= a && a <= b) {
        printf("%d %d %d", c, a, b);
    }
    else if (c <= b && b <= a) {
        printf("%d %d %d", c, b, a);
    }

    return 0;
}