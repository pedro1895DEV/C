// Troca de Variáveis
// Leia dois inteiros, a e b em duas variáveis, troque os valores das variáveis entre si e imprima os valores de a e b.

// Input
// Uma linha com dois inteiros a e b (0≤a≤109), separados por um espaço.

// Output
// Uma linha com os valores de a e b trocados entre si e separados por um espaço.

#include <stdio.h>

int main() {
  int a;
  int b;

  printf("Digite um numero para a variavel A: \n");

  scanf("%d", &a);

  printf("Digite um numero para a variavel B: \n");
  scanf("%d", &b);

  a = b + a;
  b = a - b;
  a = a - b;

  printf("%d %d", a, b);
  return 0;
}