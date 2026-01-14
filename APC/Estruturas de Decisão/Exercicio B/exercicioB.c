// Área de Figuras

// Considere as seguintes opções de cálculo de área:
// 1. Círculo;
// 2. Triângulo retângulo;
// 3. Retângulo;
// 4. Losango;

// Leia a opção do usuário e calcule a área da figura correspondente.
// Input
// A primeira linha da entrada possui um inteiro O (1 ≤ O ≤ 4), que indica a opção escolhida para o cálculo da área de uma figura específica, sendo 1 para o círculo, 2 para o
// triângulo retângulo, 3 para o retângulo e 4 para o losango.

// A segunda linha da entrada depende do valor da opção lido:
// Para o círculo, haverá um real R (0 ≤ R ≤ 10⁹), indicando ao tamanho do raio.
// Para o triângulo retângulo, haverá dois reais, C1 e C2 (0 ≤ Ci ≤ 10⁹) indicando os tamanhos dos catetos.
// Para o retângulo, haverá dois reais, B e H (0 ≤ B, H ≤ 10⁹), indicando os tamanhos da base e altura.
// Para o losango, haverá dois reais, D1 e D2 (0 ≤ D1, D2 ≤ 10⁹ ), indicando os tamanhos das diagonais.

// Em todos os casos, os valores estão separados por um espaço.

// Output
// Imprima a área da figura correspondente.

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main () {
    int o;
    double raio, c1, c2, b, h, d1, d2;
    double area;

    printf("Escolha de 1 ate 4 para:\n 1. Circulo \n 2. Triangulo Retangulo \n 3. Retangulo \n 4. Losango \n");
    scanf("%d", &o);

    if (o == 1) {
        printf("Digite o valor do raio: ");
        scanf("%lf", &raio);
        area = M_PI * pow(raio, 2);
    }
    else if (o == 2) {
        printf("Digite os dois valores dos catetos: ");
        scanf("%lf %lf", &c1, &c2);
        area = (c1 * c2) / 2;
    }
    else if (o == 3) {
        printf("Digite o valor da base e da altura: ");
        scanf("%lf %lf", &b, &h);
        area = b * h;
    }
    else if (o == 4) {
        printf("Digite o valor da diagonal maior e diagonal menor: ");
        scanf("%lf %lf", &d1, &d2);
        area = (d1 * d2) / 2;

    } else {
        printf("Digite um valor O (1 ≤ O ≤ 4)");
    }

    printf("%lf", area);
    return 0;
}