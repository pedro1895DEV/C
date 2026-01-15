// Data Válida

// Faça um programa que leia uma data informada pelo usuário (dia, mês e ano) e determine se aquela data é válida ou não. Uma data é considerada válida quando:
// O valor do ano está entre 0 e 3000;
// O valor do mês está entre 1 e 12;
// O valor do dia:
// Está entre 1 e 28 no mês de fevereiro em anos não bissextos.
// Está entre 1 e 29 no mês de fevereiro em anos bissextos.
// Está entre 1 e 30 nos meses de abril, junho, setembro e novembro.
// Está entre 1 e 31 nos demais casos.

// Input
// A entrada possui uma linha com três inteiros, separados por um espaço, D (1 ≤ D ≤ 50), M (1 ≤ M ≤ 24), A (1 ≤ A ≤ 3000).

// Output
// Imprima uma linha com a mensagem "Sim" caso a data seja válida e "Nao" caso contrário.

#include <stdio.h>

int main () {
    int dia, mes, ano;
    printf("Digite tres valores para dia, mes e ano: ");
    scanf("%d %d %d", &dia, &mes, &ano);
    int bissexto = ano % 4 == 0 && (ano % 400 == 0  || ano % 100 != 0);

    if ((ano > 0 && ano < 3000) && (mes >= 1 && mes <=12)) {
        if (mes == 2 && dia <= 29 && bissexto) {
            printf("Sim");
        } 
        else if (mes == 2 && dia <= 28 && !bissexto) {
            printf("Sim");
        }
        else if (dia >= 1 && dia <= 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
            printf("Sim");
        }
        else if (dia >= 1 && dia <= 31 && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)) {
            printf("Sim");
        }
        else {
            printf("Nao");
        }
    } else {
        printf("Nao");
    }

    return 0;
}