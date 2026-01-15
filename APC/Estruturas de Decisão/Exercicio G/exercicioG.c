// Bhaskara

// A forma geral de uma equação do segundo grau é: f(x) = ax² + bx + c

// Dados os coeficientes a, b e c, determine, se houver, as raízes de uma equação do segundo grau.

// Input
// A entrada possui três números rais, separados por um espaço, que correspondem, respectivamente, aos coeficientes a, b e c (−100 ≤ a, b, c ≤ 100).

// Output
// Caso a equação possua duas raízes reais, imprima uma linha com às duas raízes (em qualquer ordem), separadas por um espaço. Se a equação possuir apenas uma raiz real,
// imprima uma linha com a única raiz. Se a equação não possuir raízes reais, imprima "sem raiz".

#include <stdio.h>
#include <math.h>

int main () {
    double a, b, c;
    printf("Digite tres valores reais: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double delta = pow(b, 2) - (4 * a * c);
    double x1 = (-b + sqrt(delta)) / (2 * a);
    double x2 = (-b - sqrt(delta)) / (2 * a);

    if (delta > 0) {
        printf("%lf %lf", x1, x2);
    } 
    else if (delta == 0) {
        printf("%lf", x1);
    }
    else {
        printf("sem raiz");
    }

    return 0;
}