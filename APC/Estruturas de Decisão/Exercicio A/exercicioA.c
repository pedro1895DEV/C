// Calculo de Médias

// Considere as seguintes opções:
// 1. Média aritmética;
// 2. Média ponderada;
// 3. Média harmônica;
// 4. Média geométrica;
// Com base em uma das opções, calcule a média correspondente de três valores. Para a média ponderada, deve-se assumir pesos 1 para o primeiro valor, 2 para o segundo e
// 3 para o terceiro.
// Input
// A primeira linha da entrada possui um inteiro O (1 ≤ O ≤ 4), que indica a opção escolhida, sendo para a média aritmética, para a ponderada, para a harmônica e
// para a geométrica.

// A segunda linha possui três reais V1 V2 V3 0 ≤ Vi ≤ 10⁹ , separados por um espaço, que correspondem aos valores cuja média será baseada.

// Output
// Imprima em uma linha o valor da média calculada.
#include <stdio.h>
#include <math.h>

int main () {
    int o;
    double v1, v2, v3;
    double media;

    printf("Escolha de 1 ate 4 para:\n 1. Media aritmetica \n 2. Media ponderada \n 3. Media harmonica \n 4. Media geometrica \n");
    scanf("%d", &o);

    if (o == 1) {
        printf("Digite tres valores reais: ");
        scanf("%lf %lf %lf", &v1, &v2, &v3);
        media = (v1 + v2 + v3) / 3;
    }
    else if (o == 2) {
        printf("Digite tres valores reais: ");
        scanf("%lf %lf %lf", &v1, &v2, &v3);
        media = (v1 * 1 + v2 * 2 + v3 * 3) / 6;
    }
    else if (o == 3) {
        printf("Digite tres valores reais: ");
        scanf("%lf %lf %lf", &v1, &v2, &v3);
        media = 3 / (1/v1 + 1/v2 + 1/v3);
    }
    else if (o == 4) {
        printf("Digite tres valores reais: ");
        scanf("%lf %lf %lf", &v1, &v2, &v3);
        media = cbrt(v1 * v2 * v3);

    } else {
        printf("Digite um valor O (1 ≤ O ≤ 4)");
    }

    printf("%lf", media);
    
    return 0;
}