#include "solver.h"
#include "testing.h"
#include "tests.h"
#include "color.h"
#include <stdio.h>


int RunSolverTests (void) {
    printf("# Testing SolveEquation()\n");

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int failed = 0;
    for (int i = 0; i < num_tests; i++) {
        failed += (int) SolverTest(tests[i]);
    }

    if (failed == 0) GreenText();
    else if (failed < num_tests / 2) YellowText();
    else RedText();
    printf ("# SolveEquation(): Failed %d tests out of %d\n\n", failed, num_tests);
    DefaultText();

    return failed;
}

TEST_STATUS SolverTest (struct solver_test test) {

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
                                return FAIL;
            }
        }
        else status = FAIL;

        if (status == FAIL) {


            RedText();
            printf ("# SolveEquation(): Test %d failed. Params: a=%lf, b=%lf, c=%lf\n"
                    "Expected: n_roots=%d, x1=%lf, x2=%lf, get: n_roots=%d, x1=%lf, x2=%lf\n",
                    test.test_number, test.a, test.b, test.c, test.n_roots_expected, test.x1_expected, test.x2_expected,
                    n_roots, x1, x2);
            DefaultText();
        }

        return status;
}


int RunNonZeroTests (void) {
    printf("# Testing NonZero()\n");

    int num_tests = sizeof(NonZero_in) / sizeof(NonZero_in[0]);
    int failed = 0;
    for (int i = 0; i < num_tests; i++) {
        failed += (int) NonZeroTest(i + 1, NonZero_in[i], NonZero_out[i]);
    }

    if (failed == 0) GreenText();
    else if (failed < num_tests / 2) YellowText();
    else RedText();
    printf ("# NonZero(): Failed %d tests out of %d\n\n", failed, num_tests);
    DefaultText();

    return failed;
}

TEST_STATUS NonZeroTest (int test_number, double in, int out) {
    int result = NonZero(in);

    if (result != out) {

        RedText();
        printf("# NonZero(): Test %d failed. Params: fp=%lg\n"
               "Expected: out=%d, get: out=%d\n",
               test_number, in, out, result);
        DefaultText();

        return FAIL;
    }

    return OK;
}
