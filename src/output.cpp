/**
 * @file output.cpp
 * @brief Most of the program's output
 */

#include <stdio.h>
#include "output.h"
#include "solver.h"
#include "solver_structs.h"
#include "color.h"

void EntryMessage (void) {
    printf("# Second power equation solver\n");
}

/**
 * @brief Solution output
 *
 * Prints results of solving equation.
 * Considers different number of roots and highlights with color.
 *
 * @param solution Struct with solution
 *
 */
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

/**
 * @brief Testing result
 *
 * Prints information about failed tests in different colors
 *
 * @param tested_func Name of the function that was tested
 * @param num_tests   Number of tests
 * @param failed      Number of failed tests
 *
 * @see @ref RunSolverTests
 * @see @ref RunNonZeroTests
 */
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

/**
 * @brief Helpful information
 *
 * Prints helping information in console
 *
 * @see @ref HandleArgs
 */
void PrintHelp (void) {
    printf ("# usage: quad.exe [-s | --solve <a> <b> <c>] [-h | --help] [-t | --test] [--epsilon | --eps]\n\n"
            "  no agrs   Solving quadratic equation. Coefficients must be in form \"<a> <b> <c>\"\n"
            "  solve     Solving quadratic equation. Coefficients must be in form \"-s <a> <b> <c>\"\n"
            "  test      Testing internal functions\n"
            "  epsilon   Printing current value of constant for NonZero()\n"
            "\n");
}

/**
 * @brief Prints PRECISION
 *
 * Prints parameter for NonZero()
 *
 * @see @ref HandleArgs
 */
void PrintEps (void) {
    YellowText();
    printf("# Epsilon = %lg\n\n", PRECISION);
    DefaultText();
}
