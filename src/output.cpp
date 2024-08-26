/**
 * @file output.cpp
 * @brief Most of the program's output
 */

#include <stdio.h>
#include <stdlib.h>

#include "output.h"
#include "solver.h"
#include "solver_structs.h"
#include "color.h"

void EntryMessage (void) {
    printf("# Second power equation solver\n");
}

void PrintResults (struct ROOTS solution) {
    // -0 bug solution
    if (!NonZero(solution.x1)) solution.x1 = 0;
    if (!NonZero(solution.x2)) solution.x2 = 0;

    switch (solution.num_roots) {
        case NO_ROOTS:  YellowText();
                        printf("# No roots\n");
                        break;

        case ONE_ROOT:  GreenText();
                        printf("# x = %.5lg\n", solution.x1);
                        break;

        case TWO_ROOTS: GreenText();
                        printf("# x1 = %.5lg\n"
                               "# x2 = %.5lg\n", solution.x1, solution.x2);
                        break;

        case INF_ROOTS: YellowText();
                        printf("# Infinite number of roots\n");
                        break;

        default:        RedText();
                        printf("# PrintResults(): n_roots is incorrect\n");
    }

    DefaultText();
}

void PrintTestingRes (const char *tested_func, int num_tests, int failed) {
    if (failed == 0)
        GreenText();
    else if (failed < num_tests / 2)
        YellowText();
    else
        RedText();

    printf ("# %s(): Failed %d tests out of %d\n\n", tested_func, failed, num_tests);
    DefaultText();
}

void PrintHelp (void) {
    printf ("# usage: quad.exe [-s | --solve <a> <b> <c>] [-h | --help] [--test_file_help] [-t | --test (optional) <filename.csv>] [--epsilon | --eps]\n\n"
            "  no agrs        Solving quadratic equation. Coefficients must be in form \"<a> <b> <c>\"\n"
            "  solve          Solving quadratic equation. Coefficients must be in form \"-s <a> <b> <c>\"\n"
            "  test           Testing internal functions.\n"
            "                 It is possiblee to use tests for Solver from file: --test_file_help for more info\n"
            "  test_file_help Prints help info about format of file with tests\n"
            "  epsilon        Printing current value of constant for NonZero()\n"
            "\n");
}

void PrintTestFileHelp (void) {
    printf ("# usage: quad.exe --test (optional) <filename.csv>\n\n"
            "  File must have .csv format with ',' separtor and '\\n' as end of line. First row may be header, which must start\n"
            "  with a non-blank character, not a number and not a dot. Float numbers must have '.' decimal separator.\n"
            "  Test number must be positive. Each root must be indicated with accuracy of 6 decimal places.\n"
            "  File must contain no more one line of text (header).\n"
            "\n"
            "  Sequence of test parameters:\n"
            "  test number,  first coef,  second coef,  third coef,  number of roots (-1 if infinite),  expected smaller root, expected larger root\n"
            "\n"
            "  Example:\n"
            "  n, a,   b,   c,  roots, x1,        x2\n"
            "  1, 0,   0,   0,  -1,    0,         0\n"
            "  2, 1.5, 2.3, -4, 2,     -2.570674, 1.037341\n"
            "  3, 0,   1,   1,  0,     0,         0\n"
            "\n");
}

void PrintEps (void) {
    YellowText();
    printf("# Epsilon = %lg\n\n", PRECISION);
    DefaultText();
}

void PrintCat (void) {
    FILE *file_cat = fopen("include/x.txt", "r");

    if (file_cat != NULL) {
        int c = '\0';
        while ((c = getc(file_cat)) != EOF)
            putchar(c);

        fclose(file_cat);
    }
    else {
        RedText();
        printf("# No file with cat!\n");
        DefaultText();
    }

    printf("\n");
}
