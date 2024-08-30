/**
 * @file args_handler.cpp
 * @brief Command line arguments handling
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "args_handler.h"
#include "num_roots.h"
#include "input.h"
#include "solver.h"
#include "solver_structs.h"
#include "output.h"
#include "tests.h"
#include "testing.h"
#include "color.h"

const int MAX_FILENAME_LEN = 255;

//command line options
const char help_opt_long []  = "--help"            ;
const char help_opt_short[]  = "-h"                ;

const char file_tests_opt[]  = "--file_tests_help" ;

const char solve_opt_long [] = "--solve"           ;
const char solve_opt_short[] = "-s"                ;

const char test_opt_long []  = "--test"            ;
const char test_opt_short[]  = "-t"                ;

const char eps_opt_long []   = "--epsilon"         ;
const char eps_opt_short[]   = "--eps"             ;

const char cat_opt[]         = "--cat"             ;

const static char *cat_filename = "include/x.txt";


void HandleArgs (const int argc, const char *argv[]) {
    assert(argc > 1);

    Args_Status args_status = ARGS_BAD;

    for (size_t num_arg = 1; num_arg < (size_t) argc; num_arg++) {

        const char *arg = argv[num_arg];

        if (strcmp(arg, help_opt_long) == 0 || strcmp(arg, help_opt_short) == 0) {
            args_status = ARGS_GOOD;

            PrintHelp();
        }

        else if (strcmp(arg, file_tests_opt) == 0) {
            args_status = ARGS_GOOD;

            PrintFileTestsHelp();
        }

        else if (strcmp(arg, solve_opt_long) == 0 || strcmp(arg, solve_opt_short) == 0) {
            if (num_arg < (size_t) argc - 3)
                args_status = SolveFromArgs(argv + num_arg + 1);
            else
                args_status = ARGS_BAD;
        }

        else if (strcmp(arg, test_opt_long) == 0 || strcmp(arg, test_opt_short) == 0) {
            bool is_last = (num_arg == (size_t) argc - 1);

            const char *next_arg = "";
            if (!is_last)
                next_arg = argv[num_arg + 1];

            args_status = TestingFromArgs (is_last, next_arg);
        }

        else if (strcmp(arg, eps_opt_long) == 0 || strcmp(arg, eps_opt_short) == 0) {
            args_status = ARGS_GOOD;

            PrintEps();
        }

        else if (strcmp(arg, cat_opt) == 0) {      // --cat=@internal
            args_status = ARGS_GOOD;

            FILE *file_cat = fopen(cat_filename, "r");

            if (file_cat != NULL)
                PrintCat(file_cat);
            else {
                RedText();
                printf("# No file with cat!\n");
                DefaultText();
            }

            printf("\n");
        }
    }

    if (args_status == ARGS_BAD) {
        RedText();
        printf ("# Incorrect arguments, try again\n");
        DefaultText();
    }

}

Args_Status SolveFromArgs (const char *argv[]) {
    if (IsNumberInStr (argv[0]) && IsNumberInStr (argv[1]) && IsNumberInStr (argv[2])) {

        struct Coefficients coefs = GetCoefsFromStr (argv);

        printf ("# Solving a*x^2 + b*x + c = 0\n");
        printf ("# Entered: a = %.6lg, b = %.6lg, c = %.6lg\n", coefs.a, coefs.b, coefs.c);

        struct Roots solution = SolveEquation (coefs);

        PrintResults (solution);
        printf ("\n");

        return ARGS_GOOD;
    }

    return ARGS_BAD;
}

Args_Status TestingFromArgs (bool is_last, const char *next_arg) {
    Args_Status args_status = ARGS_BAD;

    if (is_last or next_arg[0] == '-') {
        args_status = ARGS_GOOD;

        RunSolverTests(solver_tests);
    }
    else if (! IsCsvFileName (next_arg)) {
        args_status = IncorrectFileName (next_arg);
    }
    else {
        FILE *file_with_tests = fopen(next_arg, "r");

        if (! file_with_tests)
            args_status = IncorrectFileName (next_arg);
        else
            args_status = RunTestsFromFile (file_with_tests);

        fclose(file_with_tests);
    }

    return args_status;
}

bool IsNumberInStr (const char *c) {
    while (*c < '0' || *c > '9') {
        c++;

        if (*c == '\0')
            return false;
    }

    return true;
}

Args_Status IncorrectFileName (const char *file_name) {
    RedText();
    printf ("# Incorrect file name: %s\n\n", file_name);
    DefaultText();

    return ARGS_BAD;
}

bool IsCsvFileName (const char *arg) {
    char *dot = strrchr(arg, '.');
    return dot && !strcmp(dot, ".csv");
}

struct Coefficients GetCoefsFromStr(const char **start) {
    struct Coefficients coefs = {.a = 0, .b = 0, .c = 0};

    sscanf (*start, "%lf", &coefs.a);
    start++;
    sscanf (*start, "%lf", &coefs.b);
    start++;
    sscanf (*start, "%lf", &coefs.c);

    return coefs;
}
