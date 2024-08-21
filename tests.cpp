#include "solver.h"
#include "tests.h"
#include <stdio.h>

int RunSolverTests (void) {
    printf("# Testing SolveEquation()\n");

    int failed = 0;
    int n = 12;

    //                   n    a      b       c   n_roots     x1         x2
    failed += SolverTest(1,   0,     0,      0,  INF_ROOTS,  0,         0);
    failed += SolverTest(2,   0,     0,      1,  NO_ROOTS,   0,         0);
    failed += SolverTest(3,   0,     1,      0,  ONE_ROOT,   0,         0);
    failed += SolverTest(4,   0,     1,      1,  ONE_ROOT,  -1,         0);
    failed += SolverTest(5,   1,     0,      0,  ONE_ROOT,   0,         0);
    failed += SolverTest(6,   1,     0,      1,  NO_ROOTS,   0,         0);
    failed += SolverTest(7,   1,     1,      0,  TWO_ROOTS, -1,         0);
    failed += SolverTest(8,   1,     1,      1,  NO_ROOTS,   0,         0);
    failed += SolverTest(9,   1.28,  5.67,  -10, TWO_ROOTS, -5.781078,  1.351391);
    failed += SolverTest(10, -8,    -55.6,  -5,  TWO_ROOTS, -6.858877, -0.091122);
    failed += SolverTest(11,  0,     2,     -10, ONE_ROOT,   5,         0);
    failed += SolverTest(12,  1,     0,     -25, TWO_ROOTS, -5,         5);

    printf ("# SolveEquation(): Failed %d tests out of %d\n\n", failed, n);

    return failed;
}

int SolverTest (int n, double a, double b, double c,
                NUM_ROOTS n_roots_exp, double x1_exp, double x2_exp) {

        double x1 = 0, x2 = 0;
        NUM_ROOTS n_roots = SolveEquation (a, b, c, &x1, &x2);

        int status = 0; // 0 - OK, 1 - Error
        if (n_roots == n_roots_exp) {
            switch (n_roots_exp) {
                case NO_ROOTS:  if (NonZero(x1) || NonZero(x2)) status = 1;
                                break;

                case ONE_ROOT:  if (NonZero(x1 - x1_exp) || NonZero(x2)) status = 1;
                                break;

                case TWO_ROOTS: if (NonZero(x1 - x1_exp) || NonZero(x2 - x2_exp)) status = 1;
                                break;

                case INF_ROOTS: if (NonZero(x1) || NonZero(x2)) status = 1;
                                break;

                default:        printf("PrintResults(): n_roots is incorrect");
                                return 1;
            }
        }
        else status = 1;

        if (status == 1) {
            printf ("# SolveEquation(): Test %d failed. Params: a=%lf, b=%lf, c=%lf\n"
                    "Expected: n_roots=%d, x1=%lf, x2=%lf, get: n_roots=%d, x1=%lf, x2=%lf\n",
                    n, a, b, c, n_roots_exp, x1_exp, x2_exp, n_roots, x1, x2);
        }

        return status;
}

const double NonZero_in[4] = {0, 1, 0.001, 0.00000001};
const int NonZero_out[4] = {0, 1, 1, 0};


int RunNonZeroTests (void) {
    printf("Testing NonZero()\n");

    int failed = 0;
    int i = 0;
    for (; i < 4; i++) {
        double in = NonZero_in[i];
        int out = NonZero_out[i];

        if (NonZeroTest(in, out)) {
            printf("NonZero(): Test %d failed. In: %lg, correct out: %d, function out: %d\n", i + 1, in, out, NonZero(in));
            failed += 1;
        }
    }

    printf ("NonZero(): Failed %d tests out of %d\n", failed, i);

    return failed;
}

int NonZeroTest (double in, int out) {
    return NonZero(in) != out;
}
