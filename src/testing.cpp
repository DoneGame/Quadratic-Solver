#include "solver.h"
#include "testing.h"
#include "tests.h"
#include "solver_structs.h"
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

        struct COEFFICIENTS coefs = {0, 0, 0};
        coefs.a = test.a;
        coefs.b = test.b;
        coefs.c = test.c;

        struct ROOTS sol = SolveEquation (coefs);

        TEST_STATUS status = OK;
        if (sol.num_roots == test.n_roots_exp) {
            switch (sol.num_roots) {
                case NO_ROOTS:  if (NonZero(sol.x1) || NonZero(sol.x2)) status = FAIL;
                                break;

                case ONE_ROOT:  if (NonZero(sol.x1 - test.x1_exp) || NonZero(sol.x2)) status = FAIL;
                                break;

                case TWO_ROOTS: if (NonZero(sol.x1 - test.x1_exp) || NonZero(sol.x2 - test.x2_exp)) status = FAIL;
                                break;

                case INF_ROOTS: if (NonZero(sol.x1) || NonZero(sol.x2)) status = FAIL;
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
                    test.test_number, test.a, test.b, test.c, test.n_roots_exp, test.x1_exp, test.x2_exp,
                    sol.num_roots, sol.x1, sol.x2);
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
