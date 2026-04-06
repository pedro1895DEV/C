#include <stdio.h>
#include <stdlib.h>

int valida(int *postes, int n, int m, int mid, int *casas) {
    int distancia = 0;
    for (int i = 0; i < n; i++) {
        while (distancia < m && postes[distancia] < casas[i] - mid) {
            distancia++;
        }
        if (distancia >= m || postes[distancia] > casas[i] + mid) {
            return 0;
        }
    }
    return 1;
}

int binary_search(int *casas, int *postes, int n, int m) {
    int l = 0;
    int r = 1000000000;
    int rNecessario = 0;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (valida(postes, n, m, mid, casas)) {
            rNecessario = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return rNecessario;
}

int main () {
    int n, m;
    scanf("%d", &n);
    int* casas = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &casas[i]);
    }

    scanf("%d", &m);
    int* localizacaoPoste = malloc(sizeof(int) * m);

    for (int i = 0; i < m; i++) {
        scanf("%d", &localizacaoPoste[i]);
    }

    printf("%d", binary_search(casas, localizacaoPoste, n, m));

    free(casas);
    free(localizacaoPoste);
    return 0;
}