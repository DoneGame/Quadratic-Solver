/**
 * @file output.cpp
 * @brief All output functions of program
 */

#include <stdio.h>
#include "output.h"
#include "solver.h"
#include "solver_structs.h"
#include "color.h"

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
