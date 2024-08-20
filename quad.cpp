#include <stdio.h>
#include <math.h>
#include <assert.h>

typedef enum __NUM_ROOTS {
    INF_ROOTS = -1,
    NO_ROOTS = 0,
    ONE_ROOT,
    TWO_ROOTS,
} NUM_ROOTS;

const double PRECISION = 0.00001;

void GetCoefs(double *a, double *b, double *c);
NUM_ROOTS SolveQuadraticEquation (double a, double b, double c, double *x1, double *x2);
NUM_ROOTS SolveLinearEquation (double a, double b, double *x);
void PrintResults (NUM_ROOTS n_roots, double x1, double x2);
int NonZero (double x);

int main() {
    double a = 0, b = 0, c = 0;

    printf("# Second power equation solver\n");

    GetCoefs (&a, &b, &c);

    double x1 = 0, x2 = 0;
    NUM_ROOTS n_roots = SolveQuadraticEquation (a, b, c, &x1, &x2);

    PrintResults (n_roots, x1, x2);

}

void GetCoefs(double *a, double *b, double *c) {

    printf("# a*x^2 + b*x + c = 0\n");
    printf("# Enter a, b, c: ");
    while (scanf("%lg %lg %lg", a, b, c) != 3) {
        int s = '\0';
        while ((s = getchar()) != '\n' && s != EOF);  // clear buffer

        printf("# Incorrect format. Enter a, b, c: ");
    }

}

NUM_ROOTS SolveQuadraticEquation (double a, double b, double c,
                            double *x1, double *x2) {

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != x2);

    if (NonZero(a)) {
        double D = b*b - 4*a*c;

        if (NonZero(D)) {
            if (D < 0) return NO_ROOTS;

            double sqrt_D = sqrt(D);

            *x1 = (-b + sqrt_D) / (2*a);
            *x2 = (-b - sqrt_D) / (2*a);

            assert(isfinite(*x1));
            assert(isfinite(*x2));

            return TWO_ROOTS;
        }


        *x1 = *x2 = -b / (2*a);

        assert(isfinite(*x1));

        return ONE_ROOT;
    }

    return SolveLinearEquation (b, c, x1);
    *x2 = *x1;

}

NUM_ROOTS SolveLinearEquation (double a, double b, double *x) {

    if (NonZero(a)) {
        *x = -b / a;

        assert(isfinite(*x));

        return ONE_ROOT;
    }

    if (NonZero(b)) return NO_ROOTS;
    else return INF_ROOTS;

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

int NonZero (double x) {return (fabs(x) > PRECISION) ? 1 : 0;}
