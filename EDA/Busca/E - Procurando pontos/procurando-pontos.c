#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int xl;
    int yl;
}coords;

int ok(coords *v, int n, int l, int r) {
    int resposta = 0;

    for (int i = 0; i < n; i++) {
        while (resposta <= n) {
            resposta++;
        }
        if (v[l].xl != v[l].x && v[l].yl != v[l].y) {
            l++;
            r--;
        }
    }
    return 1;
}

int binary_search(coords *v, int n, int q) {
    int l = 0;
    int r = n - 1;
    int resultado = 0;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (ok(v, n, l, r)) {
            resultado = mid;
            r = mid - 1;
        } else  {
            l = mid + 1;
        }
        // printf("%d", resultado);
    }
    return resultado;
}

int main () {
    int n, q;
    scanf("%d %d", &n, &q);

    coords* abscissaEOrdenada = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &abscissaEOrdenada[i].x, &abscissaEOrdenada[i].y);
    }

    for (int i = 0; i < q; i++) {
        scanf("%d %d", &abscissaEOrdenada[i].xl, &abscissaEOrdenada[i].yl);
    }

    // printf("\n");printf("\n");printf("\n");

    // for (int i = 0; i < n; i++) {
    //     printf("%d %d\n", abscissaEOrdenada[i].x, abscissaEOrdenada[i].y);
    // }

    // for (int i = 0; i < q; i++) {
    //     printf("%d %d\n", abscissaEOrdenada[i].xl, abscissaEOrdenada[i].yl);
    // }
// binary_search(abscissaEOrdenada, n, q);
    for (int i = 0; i < n; i++) {
        if (binary_search(abscissaEOrdenada, n, q)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    // free(abscissaEOrdenada);
    return 0;
}