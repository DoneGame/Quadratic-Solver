/**
 * @file testing.cpp
 * @brief Unit testing
 */

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <assert.h>

#include "solver.h"
#include "testing.h"
#include "solver_structs.h"
#include "output.h"
#include "input.h"
#include "color.h"
#include "args_handler.h"

const int MAX_TESTS_IN_FILE = 100;


unsigned RunSolverTests (struct Solver_Test tests[]) {
    printf("# Testing SolveEquation()\n");

    unsigned failed   = 0;
    size_t   num_test = 0;

    for (; (tests[num_test]).test_number >= 0; num_test++) {
        failed += (int) SolverTest(tests[num_test]);
        assert(num_test < MAX_TESTS_IN_FILE); // last line contains stopping test, max tests in struct = max tests in file + 1
    }

    PrintTestingRes("SolveEquation", num_test, failed);

    return failed;
}

Test_Status SolverTest (struct Solver_Test test) {

        struct Coefficients coefs = {test.a, test.b, test.c};

        struct Roots sol = SolveEquation (coefs);

        Test_Status status = OK;

        if (sol.num_roots == test.n_roots_exp) {
            switch (sol.num_roots) {
                case NO_ROOTS:  if (!isnan(sol.x1) || !isnan(sol.x2)) {
                                    status = FAIL;
                                }
                                break;

                case ONE_ROOT:  if (NonZero(sol.x1 - test.x1_exp) || !isnan(sol.x2)) {
                                    status = FAIL;
                                }
                                break;

                case TWO_ROOTS: if (NonZero(sol.x1 - test.x1_exp) || NonZero(sol.x2 - test.x2_exp)) {
                                    status = FAIL;
                                }
                                break;

                case INF_ROOTS: if (!isnan(sol.x1) || !isnan(sol.x2)) {
                                    status = FAIL;
                                }
                                break;

                default:        RedText();
                                printf("PrintResults(): n_roots is incorrect\n");
                                DefaultText();
                                return FAIL;
            }
        }
        else {
            status = FAIL;
        }

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

Args_Status RunTestsFromFile (FILE *file_with_tests) {
    assert(file_with_tests);

    struct Solver_Test tests[MAX_TESTS_IN_FILE + 1] = {};
    size_t line_num  = 0;
    int    symbol    = '\0';
    while ((symbol = getc(file_with_tests)) != EOF) {
        ungetc(symbol, file_with_tests);

        if (!isspace(symbol) && !isdigit(symbol) && symbol != '.') { // header of csv file
            FileClearBuffer (file_with_tests);
        }

        if (line_num + 1 > MAX_TESTS_IN_FILE) {
            YellowText();
            printf ("# Too many tests in file. Using first %d tests\n", MAX_TESTS_IN_FILE);
            DefaultText();

            break;
        }

        int num_roots = 0;
        int test_n    = 0;

        assert(line_num < MAX_TESTS_IN_FILE);
        struct Solver_Test *test = &tests[line_num];

        int correct_args = fscanf (file_with_tests, "%d,       %lg,       %lg,       %lg,       %d,          %lg,           %lg",
                                                     &test_n,  &test->a,  &test->b,  &test->c,  &num_roots,  &test->x1_exp, &test->x2_exp);

        test->n_roots_exp = (Num_Roots) num_roots;
        test->test_number = test_n;

        if (correct_args != 7 || test_n < 0) {
            RedText();
            printf("# Incorrect file with tests!\n\n");
            DefaultText();

            return GOOD;
        }

        FileClearBuffer (file_with_tests);

        line_num++;
    }

    fclose(file_with_tests);

    assert(line_num <= MAX_TESTS_IN_FILE); // last line contains stopping test, max tests in struct = max tests in file + 1
    tests[line_num].test_number = -1;

    RunSolverTests (tests);

    return GOOD;
}
