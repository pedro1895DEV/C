// Conversão de Segundos

// Converta uma quantidade em segundos para dias, horas, minutos e segundos equivalente.

// Input
// A entrada possui uma única linha com um número inteiro t(0≤t≤109) em segundos.

// Output
// Imprima a quantidade equivalente de dias, horas, minutos e segundos, uma informação por linha, isto é:

// A primeira linha da saída indica a informação do número de dias.
// A segunda, o número de horas;
// A terceira, o número de minutos;
// A última, o número de segundos;

#include <stdio.h>

int main () {
    int t;
    int segundos;
    int minutos;
    int horas;
    int dias;
    int resto;

    printf("Digite os segundos: ");
    scanf("%d", &t);

    dias = t / 86400;
    resto = t % 86400;

    horas = resto / 3600;
    resto = resto % 3600;

    minutos = resto / 60;

    segundos = resto % 60;

    printf("%d \n", dias);
    printf("%d \n", horas);
    printf("%d \n", minutos);
    printf("%d \n", segundos);

    return 0;
}