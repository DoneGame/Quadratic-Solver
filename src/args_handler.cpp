/**
 * @file args_handler.cpp
 * @brief Command line arguments handling
 */

#include <stdio.h>
#include <string.h>
#include "args_handler.h"
#include "num_roots.h"
#include "input.h"
#include "solver.h"
#include "solver_structs.h"
#include "output.h"
#include "testing.h"
#include "color.h"


void HandleArgs (int argc, char *argv[]) {

    ARGS_STATUS args_status = BAD;

    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];

        if (strcmp(arg, "--help") == 0 || strcmp(arg, "-h") == 0) {
            args_status = GOOD;

            PrintHelp();
        }

        if (strcmp(arg, "--solve") == 0 || strcmp(arg, "-s") == 0) {
            if (i < argc - 3)
                args_status = SolveFromArgs(argv + i + 1);
            else
                args_status = BAD;
        }

        if (strcmp(arg, "--test") == 0 || strcmp(arg, "-t") == 0) {
            args_status = GOOD;

            RunNonZeroTests();
            RunSolverTests();
        }

        if (strcmp(arg, "--epsilon") == 0 || strcmp(arg, "--eps") == 0) {
            args_status = GOOD;

            PrintEps();
        }
    }

    if (args_status == BAD) {
        RedText();
        printf ("# Incorrect arguments, try again\n");
        DefaultText();
    }

}

ARGS_STATUS SolveFromArgs (char *argv[]) {
    if (IsNumberInStr (argv[0]) && IsNumberInStr (argv[1]) && IsNumberInStr (argv[2])) {

        struct COEFFICIENTS coefs = GetCoefsFromStr (argv);

        printf ("# Solving a*x^2 + b*x + c = 0\n");
        printf ("# Entered: a = %.6lg, b = %.6lg, c = %.6lg\n", coefs.a, coefs.b, coefs.c);

        struct ROOTS solution = SolveEquation (coefs);

        PrintResults (solution);
        printf ("\n");

        return GOOD;
    }

    return BAD;
}
