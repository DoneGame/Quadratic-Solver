#include <stdio.h>
#include <math.h>

const int INF_ROOTS = -1;
const double precision = 0.00001;

int SolveEquation (double a, double b, double c, double *x1, double *x2);
int non_zero (double x);

int main() {
    double a = 0, b = 0, c = 0;

    printf("# Second order equation solver\n");
    printf("# a*x^2 + b*x + c = 0\n");
    printf("# Enter a, b, c: ");
    while (scanf("%lg %lg %lg", &a, &b, &c) != 3)
        printf("Incorrect format. Enter a, b, c: ");

    double x1 = 0, x2 = 0;
    int n_roots = SolveEquation (a, b, c, &x1, &x2);

    switch (n_roots) {
        case 0: printf("No roots");
        break;

        case 1: printf("x = %.5lg", x1);
        break;

        case 2: printf("x1 = %.5lg\n"
                       "x2 = %.5lg", x1, x2);
        break;

        case INF_ROOTS: printf("Infinite number of roots");
        break;

        default: printf("main(): n_roots is incorrect");
    }

}

int SolveEquation (double a, double b, double c,
                   double *x1, double *x2) {

    if (non_zero(a)) {
        double D = b*b - 4*a*c;
        double sqrt_D = sqrt(D);

        *x1 = (-b + sqrt_D) / (2*a);
        *x2 = (-b - sqrt_D) / (2*a);

        if (D < 0) return 0;

        if (non_zero(D)) return 2;
        else return 1;
    }

    if (non_zero(b)) {
        *x1 = *x2 = -c / b;

        return 1;
    }

    if (non_zero(c)) return 0;
    else return INF_ROOTS;

}

int non_zero (double x) {return (fabs(x) > precision) ? 1 : 0;}
