// Aposentadoria

// Implemente um programa que receba a idade e o tempo de contribuição de um trabalhador e informe se ele pode se aposentar de acordo com os seguintes critérios:
// Ter pelo menos 65 anos;
// Ou ter contribuído por pelo menos 30 anos;
// Ou ter ao menos 60 anos e contribuído ao menos por 25 anos;

// Input
// A entrada possui uma linha com dois inteiros, I e T (0 ≤ T ≤ I ≤ 100), separados por um espaço, que indicam, respectivamente, a idade e o tempo de contribuição de um
// trabalhador.

// Output
// Imprima uma linha com a mensagem "Sim" caso o trabalhador esteja elegível para se aposentar, ou "Nao" caso contrário.

#include <stdio.h>

int main () {
    int idade, tempoContribuicao;
    printf("Digite a idade e o tempo de contribuicao:");
    scanf("%d %d", &idade, &tempoContribuicao);

    if (idade >= 65 || tempoContribuicao >= 30 || (idade >= 60 && tempoContribuicao > 25)) {
        printf("Sim");
    } 
    else {
        printf("Nao");
    }

    return 0;
}