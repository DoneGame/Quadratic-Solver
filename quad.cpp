#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quad.h"

const double PRECISION = 0.00001;

int main() {
    double a = 0, b = 0, c = 0;

    printf("# Second power equation solver\n");

    GetCoefs (&a, &b, &c);

    double x1 = 0, x2 = 0;
    NUM_ROOTS n_roots = SolveEquation (a, b, c, &x1, &x2);

    PrintResults (n_roots, x1, x2);

}

void GetCoefs(double *a, double *b, double *c) {

    printf("# a*x^2 + b*x + c = 0\n");
    printf("# Enter a, b, c (separated by spaces): ");
    while (scanf("%lg %lg %lg", a, b, c) != 3) {
        ClearBuffer();

        printf("# Incorrect format. Enter a, b, c: ");
    }

}

void ClearBuffer (void) {
    int s = '\0';
    while ((s = getchar()) != '\n' && s != EOF);
}

NUM_ROOTS SolveEquation (double a, double b, double c,
                         double *x1, double *x2) {

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != x2);

    if (NonZero(a)) {
        return SolveQuadratic (a, b, c, x1, x2);
    }

    return SolveLinear (b, c, x1);

}

NUM_ROOTS SolveLinear (double a, double b, double *x) {

    if (NonZero(a)) {
        *x = -b / a;

        assert(isfinite(*x));

        return ONE_ROOT;
    }

    if (NonZero(b)) return NO_ROOTS;
    else return INF_ROOTS;

}

NUM_ROOTS SolveQuadratic (double a, double b, double c,
                          double *x1, double *x2) {

    double D = b*b - 4*a*c;

    if (NonZero(D)) {
        if (D < 0) {
            return NO_ROOTS;
        }

        else {
            double sqrt_D = sqrt(D);

            *x1 = (-b + sqrt_D) / (2*a);
            *x2 = (-b - sqrt_D) / (2*a);

            assert(isfinite(*x1));
            assert(isfinite(*x2));

            return TWO_ROOTS;
        }
    }


    *x1 = *x2 = -b / (2*a);

    assert(isfinite(*x1));

    return ONE_ROOT;

}

void PrintResults (NUM_ROOTS n_roots, double x1, double x2) {
    switch (n_roots) {
        case NO_ROOTS:  printf("No roots");
                        break;

        case ONE_ROOT:  printf("x = %.5lg", x1);
                        break;

        case TWO_ROOTS: printf("x1 = %.5lg\n"
                               "x2 = %.5lg", x1, x2);
                        break;

        case INF_ROOTS: printf("Infinite number of roots");
                        break;

        default:        printf("PrintResults(): n_roots is incorrect");
    }
}

int NonZero (double fp_number) {return (fabs(fp_number) > PRECISION) ? 1 : 0;}
