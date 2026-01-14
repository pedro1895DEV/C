// FizzBuzz

// Implemente um programa que leia um número inteiro e:
// Imprima "FizzBuzz", caso esse número seja múltiplo de 3 e 5 simultaneamente.
// Imprima "Fizz", caso esse número seja apenas múltiplo de 3.
// Imprima "Buzz", caso esse número seja apenas múltiplo de 5.
// Imprima "BuzzFizz", caso contrário.

// Input
// A entrada possui uma única linha com um inteiro ( 1 ≤ N ≤ 10⁹).

// Output
// Imprima uma linha com a mensagem conforme o enunciado do problema.

#include <stdio.h>

int main () {
    int n;
    printf("Digite um inteiro: ");
    scanf("%d", &n);

    if (n % 3 == 0 && n % 5 == 0) {
        printf("FizzBuzz");
    }
    else if (n % 3 == 0) {
        printf("Fizz");
    }
    else if (n % 5 == 0) {
        printf("Buzz");
    } else {
        printf("BuzzFizz");
    }

    return 0;
}