/**
 * @file main.cpp
 * @brief Main file of program
 */

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
int main (const int argc, const char *argv[]) {
    ColorOn();

    if (argc > 1) {
        HandleArgs (argc, argv);
    }
    else {

        EntryMessage();

        struct Coefficients coefficients = GetCoefs();

        struct Roots solution = SolveEquation (coefficients);

        PrintResults (solution);

    }

    return 0;
}
