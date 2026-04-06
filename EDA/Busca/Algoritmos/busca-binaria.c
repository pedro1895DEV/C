#include <stdio.h>

int busca_binaria(int *v, size_t n, int key) {
    int l = 0;
    int r = n -1;

    while(l <= r) {
        int mid = l + (r - l) / 2;
        if (key == v[mid]) {
            return mid;
        }
        else if (key < v[mid]) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return -1;
}

int main() {
    int vetor[] = {5, 2, 1, 6, 7, 8, 11, 22};
    printf("%d", busca_binaria(vetor, 8, 22));

    return 0;
}