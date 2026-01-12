// Dadas as descrições de dois pontos no plano R2, a=(x1,y1) e b=(x2,y2), calcule a distância entre eles.

// Input
// A entrada possui duas linhas. Cada linha possui dois números reais, (xi,yi) (−105≤xi,yi≤105), separados por um espaço, que descrevem um ponto.

// Output
// A distância entre os pontos a e b lidos deve ser impressa na tela.

#include <stdio.h>
#include <math.h>

int main () {
    double x1;
    double y1;
    double x2;
    double y2;
    double distancia;

    printf("Digite dois numeros reais de A: ");
    scanf("%lf %lf", &x1, &y1);
    printf("Digite dois numeros reais de B: ");
    scanf("%lf %lf", &x2, &y2);

    distancia = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    printf("%lf", distancia);

    return 0;
}