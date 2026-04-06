#include <stdio.h>
#include <math.h>

double f1(double x) { 
    return x*x*x - x - 2; 
}
double f2(double x) { 
    return cos(x) - x; 
}
double f3(double x) { 
    return exp(-x) - x; 
}
double f4(double x) { 
    return x*x - 4; 
}
double f5(double x) { 
    return log(x) + x - 2; 
}

double bisseccao(double (*f)(double), double a, double b) {
    double mid;
    for (int i = 0; i < 1000; i++) {
        mid = (a + b) / 2.0;
        if (f(mid) == 0.0) {
            break;
        }
        if (f(a) * f(mid) < 0) {
            b = mid;
        }
        else {
            a = mid;
        }
    }
    return mid;
}

int main() {
    printf("%.6f\n", bisseccao(f1, 1.0, 2.0));
    printf("%.6f\n", bisseccao(f2, 0.0, 1.0));
    printf("%.6f\n", bisseccao(f3, 0.0, 1.0));
    printf("%.6f\n", bisseccao(f4, 0.0, 3.0));
    printf("%.6f\n", bisseccao(f5, 1.0, 2.0));
    return 0;
}