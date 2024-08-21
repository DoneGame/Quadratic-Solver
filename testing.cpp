#include "solver.h"
#include "testing.h"
#include "tests.h"
#include <stdio.h>

typedef enum __TEST_STATUS {
    OK = 0,
    FAIL = 1
} TEST_STATUS;


int RunSolverTests (void) {
    printf("# Testing SolveEquation()\n");

    int failed = 0;
    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++) {
        failed += SolverTest(tests[i]);
    }

    printf ("# SolveEquation(): Failed %d tests out of %d\n\n", failed, num_tests);

    return failed;
}

int SolverTest (struct solver_test test) {

        double x1 = 0, x2 = 0;
        NUM_ROOTS n_roots = SolveEquation (test.a, test.b, test.c, &x1, &x2);

        TEST_STATUS status = OK;
        if (n_roots == test.n_roots_expected) {
            switch (n_roots) {
                case NO_ROOTS:  if (NonZero(x1) || NonZero(x2)) status = FAIL;
                                break;

                case ONE_ROOT:  if (NonZero(x1 - test.x1_expected) || NonZero(x2)) status = FAIL;
                                break;

                case TWO_ROOTS: if (NonZero(x1 - test.x1_expected) || NonZero(x2 - test.x2_expected)) status = FAIL;
                                break;

                case INF_ROOTS: if (NonZero(x1) || NonZero(x2)) status = FAIL;
                                break;

                default:        printf("PrintResults(): n_roots is incorrect");
                                return 1;
            }
        }
        else status = FAIL;

        if (status == FAIL) {
            printf ("# SolveEquation(): Test %d failed. Params: a=%lf, b=%lf, c=%lf\n"
                    "Expected: n_roots=%d, x1=%lf, x2=%lf, get: n_roots=%d, x1=%lf, x2=%lf\n",
                    test.n, test.a, test.b, test.c, test.n_roots_expected, test.x1_expected, test.x2_expected, n_roots, x1, x2);
        }

        return (int) status;
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
