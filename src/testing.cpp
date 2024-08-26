/**
 * @file testing.cpp
 * @brief Unit testing
 */

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include "solver.h"
#include "testing.h"
#include "solver_structs.h"
#include "output.h"
#include "color.h"
#include "args_handler.h"

const int MAX_TESTS_IN_FILE = 101;


int RunSolverTests (struct SOLVER_TEST tests[]) {
    printf("# Testing SolveEquation()\n");

    int num_tests = 0;
    int failed = 0;
    int i = -1;
    while ((tests[++i]).test_number >= 0) {
        num_tests++;
        failed += (int) SolverTest(tests[i]);
    }

    PrintTestingRes("SolveEquation", num_tests, failed);

    return failed;
}

TEST_STATUS SolverTest (struct SOLVER_TEST test) {

        struct COEFFICIENTS coefs = {0, 0, 0};
        coefs.a = test.a;
        coefs.b = test.b;
        coefs.c = test.c;

        struct ROOTS sol = SolveEquation (coefs);

        TEST_STATUS status = OK;
        if (sol.num_roots == test.n_roots_exp) {
            switch (sol.num_roots) {
                case NO_ROOTS:  if (sol.x1 == NAN || sol.x2 == NAN) status = FAIL;
                                break;

                case ONE_ROOT:  if (NonZero(sol.x1 - test.x1_exp) || sol.x2 == NAN) status = FAIL;
                                break;

                case TWO_ROOTS: if (NonZero(sol.x1 - test.x1_exp) || NonZero(sol.x2 - test.x2_exp)) status = FAIL;
                                break;

                case INF_ROOTS: if (sol.x1 == NAN || sol.x2 == NAN) status = FAIL;
                                break;

                default:        RedText();
                                printf("PrintResults(): n_roots is incorrect\n");
                                DefaultText();
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


int RunNonZeroTests (const double *tests_in, const int *tests_out) {
    printf("# Testing NonZero()\n");

    int num_tests = sizeof(tests_in) / sizeof(tests_in[0]);
    int failed = 0;
    for (int i = 0; i < num_tests; i++) {
        failed += (int) NonZeroTest(i + 1, tests_in[i], tests_out[i]);
    }

    PrintTestingRes("NonZero", num_tests, failed);

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

ARGS_STATUS RunTestsFromFile (FILE *fp) {

    struct SOLVER_TEST tests[MAX_TESTS_IN_FILE] = {};
    int line_num  = 0;
    int s         = '\0';
    while ((s = getc(fp)) != EOF) {
        ungetc(s, fp);

        if (!isspace(s) and !isdigit(s)) // header of csv file
            FileClearBuffer (fp);

        if (line_num + 1 > MAX_TESTS_IN_FILE) {
            YellowText();
            printf ("# Too many tests in file. Using first %d tests\n", MAX_TESTS_IN_FILE);
            DefaultText();

            break;
        }

        int num_roots = 0;
        int test_n    = 0;

        assert(line_num < MAX_TESTS_IN_FILE);
        struct SOLVER_TEST *test = &tests[line_num];

        int correct_args = fscanf (fp, "%d,       %lg,       %lg,       %lg,       %d,          %lg,           %lg",
                                        &test_n,  &test->a,  &test->b,  &test->c,  &num_roots,  &test->x1_exp, &test->x2_exp);

        test->n_roots_exp = (NUM_ROOTS) num_roots;
        test->test_number = test_n;

        if (correct_args != 7 || test_n < 0) {
            RedText();
            printf("# Incorrect file with tests!\n\n");
            DefaultText();

            return GOOD;
        }

        FileClearBuffer (fp);

        line_num++;
    }

    tests[line_num].test_number = -1;

    RunSolverTests (tests);

    return GOOD;
}

void FileClearBuffer (FILE *fp) {
    int s = '\0';
    while ((s = getc(fp)) != '\n' && s != EOF);
}
