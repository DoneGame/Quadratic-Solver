/**
 * @file main.cpp
 * @brief Main file of program
 */

#include "my_asserts.h"
#include <math.h>
#include <assert.h>

#include <stdio.h>
#include "num_roots.h"
#include "input.h"
#include "solver.h"
#include "solver_structs.h"
#include "output.h"
#include "testing.h"
#include "args_handler.h"
#include "color.h"


/**
 * @brief Entry point
 *
 * Enabling color for text, handling
 * number of arguments and main use case
 *
 *
 * @param argc Number of arguments
 * @param argv List of arguments
 *
 * @return Program exit status
 *
 * @see @ref HandleArgs
 */
int main (int argc, char *argv[]) {
    ColorOn();

    if (argc > 1) {
        HandleArgs (argc, argv);
    }
    else {

        printf("# Second power equation solver\n");

        struct COEFFICIENTS coefficients = GetCoefs();

        struct ROOTS solution = SolveEquation (coefficients);

        PrintResults (solution);

    }

    return 0;
}
