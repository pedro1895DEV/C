// Despertador

// João resolveu configurar o seu celular para despertar em um determinado horário. Dados a hora e minuto que João configurou o celular e a hora e o minuto em que ele
// deseja que o celular toque, faça um programa que determine quantas horas e minutos faltam para que o celular de João dispare o alarme. Note que o horário programado
// para despertar pode estar no dia posterior ao da programação por João, por exemplo: João pode desejar que o celular toque às 17 horas, sendo que o momento em que ele
// configurou o despertador foi às 18h30, o que nos dá uma diferença de 22h30 horas.

// A entrada possui duas linhas, cada uma com dois inteiros separados por um espaço. A primeira possui a hora HH1 e o minuto MM1 em que João configurou o despertador.  A segunda 
// linha possui a hora HH2 e o minuto MM2 com o horário do despertador. Temos que (0 ≤ HH1, HH2 ≤ 23) e (0 ≤ MM1, MM2 ≤ 59). É garantido que os dois horários estão com menos 
// de um dia de diferença e que os dois horários não são os mesmos.

// Output  
// Imprima uma linha com dois inteiros HH3 e MM3, separados por um espaço, que indicam as horas e minutos restantes para o despertador tocar.


#include <stdio.h>

int main () {
    int h1, h2, m1, m2, h3, m3;
    printf("Digite a hora e o minuto do momento: ");
    scanf("%d %d", &h1, &m1);
    printf("Digite a hora e o minuto do despertador: ");
    scanf("%d %d", &h2, &m2);

    int minutos1 = h1 * 60 + m1;
    int minutos2 = h2 * 60 + m2;

    if (h1 < 0 || h1 > 23 || h2 < 0 || h2 > 23 || m1 < 0 || m1 > 60 || m2 < 0 || m2 > 60) {
        printf("impossivel");
        return 0;
    }
    int diferenca = minutos2 - minutos1;

    if (diferenca > 0) {
        h3 = diferenca / 60;
        m3 = diferenca % 60;
    }
    else if (diferenca < 0) {
        h3 = (diferenca + 1440) / 60;
        m3 = (diferenca + 1440) % 60;
    }

    printf("%d %d", h3, m3);


    return 0;
}