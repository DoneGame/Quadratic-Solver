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

/**
 * @brief Command line argument handler
 *
 * Goes though all arguments and performs appropriate actions
 *
 * @param argc Number of arguments
 * @param argv List of arguments
 *
 * @note Throws error if none of the arguments were correct
 */
void HandleArgs (int argc, char *argv[]) {

    ARGS_STATUS args_status = BAD;

    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];

        if (StartsWith(arg, "--help") || StartsWith(arg, "-h")) {
            args_status = GOOD;

            PrintHelp();
        }

        if (StartsWith(arg, "--solve") || StartsWith(arg, "-s")) {
            if (i < argc - 3) args_status = SolveFromArgs(argv + i + 1);
            else args_status = BAD;
        }

        if (StartsWith(arg, "--test") || StartsWith(arg, "-t")) {
            args_status = GOOD;

            RunNonZeroTests();
            RunSolverTests();
        }

        if (StartsWith(arg, "--epsilon") || StartsWith(arg, "--eps")) {
            args_status = GOOD;

            YellowText();
            printf("# Epsilon = %lg\n\n", PRECISION);
            DefaultText();
        }
    }

    if (args_status == BAD) {
        RedText();
        printf ("# Incorrect arguments, try again\n");
        DefaultText();
    }

}

/**
 * @brief --solve argument handler
 *
 * Searches next three args for coefficients and outputs
 * solution of quadratic equation
 *
 * @param argv List of arguments after -s or --solve
 *
 * @return Correctness of the passed arguments
 */
ARGS_STATUS SolveFromArgs (char *argv[]) {
    if (IsNumberInStr (argv[0]) && IsNumberInStr (argv[1]) && IsNumberInStr (argv[2])) {

        struct COEFFICIENTS coefs = GetCoefsFromStr (argv);

        printf ("# Solving a*x^2 + b*x + c = 0\n");
        printf ("# Entered: a=%lg, b=%lg, c=%lg\n", coefs.a, coefs.b, coefs.c);

        struct ROOTS solution = SolveEquation (coefs);

        PrintResults (solution);
        printf ("\n");

        return GOOD;
    }

    return BAD;
}

/**
 * @todo WTF?
 */
int StartsWith (char *a, const char *b)
{
   if (strncmp(a, b, strlen(b) + 1) == 0) return 1;

   return 0;
}

/**
 * @brief Is number simbol in string
 *
 * Checks if string contains number
 *
 * @param c String
 *
 *
 * @return Result of check
 */
int IsNumberInStr (char *c) {
    while (*c < '0' || *c > '9') {
        if (*(++c) == '\0') return 0;
    }

    return 1;
}

/**
 * @brief Helpful information
 *
 * Prints helping information in console
 */
void PrintHelp (void) {
    printf ("# usage: quad.exe [-s | --solve <a> <b> <c>] [-h | --help] [-t | --test] [--epsilon | --eps]\n\n"
            "  no agrs   Solving quadratic equation. Coefficients must be in form \"<a> <b> <c>\"\n"
            "  solve     Solving quadratic equation. Coefficients must be in form \"-s <a> <b> <c>\"\n"
            "  test      Testing internal functions\n"
            "  epsilon   Current parameter for NonZero()\n"
            "\n");
}
