// Reajuste Salarial

// Os funcionários de uma empresa sofrerão um reajuste salarial conforme a seguinte tabela:

// | Salário                     | Reajuste |
// |----------------------------|----------|
// | Menos de 2000.00           | 15%      |
// | Entre 2000.00 e 5000.00    | 10%      |
// | Mais que 5000.00           | 5%       |

// Faça um programa que leia o salário de um funcionário e calcule o novo salário reajustado.

// Input  
// A entrada possui uma linha com um real S (500 ≤ S ≤ 10⁵), o valor do salário.

// Output  
// Imprima o salário reajustado.


#include <stdio.h>

int main () {
    double s;
    printf("Digite o salario: ");
    scanf("%lf", &s);

    if (s < 2000.00) {
        s = s * 1.15;
        printf("%lf", s);
    }
    else if (s >= 2000.00 && s <= 5000.00) {
        s = s * 1.10;
        printf("%lf", s);
    }
    else if (s > 5000.00) {
        s = s * 1.05;
        printf("%lf", s);
    }

    return 0;
}