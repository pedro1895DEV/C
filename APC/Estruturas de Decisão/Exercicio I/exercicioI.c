// Ano Bissexto

// Crie um programa que verifique se um ano é bissexto.

// Input
// A entrada possui uma única linha com um inteiro A (0 ≤ A ≤ 10⁹), o qual representa um ano.

// Output
// Imprima uma linha com a mensagem "Sim" caso o ano seja bissexto e "Nao" caso contrário.
#include <stdio.h>

int main () {
    int ano;
    printf("Digite o ano: ");
    scanf("%d", &ano);

    if (ano % 4 == 0 && (ano % 400 == 0  || ano % 100 != 0)) {
        printf("Sim");
    }
    else {
        printf("Nao");
    }

    return 0;
}