/**
 * @file args_handler.cpp
 * @brief Command line arguments handling
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
const static char *cat_filename = "include/x.txt";


void HandleArgs (const int argc, const char *argv[]) {

    Args_Status args_status = BAD;

    for (int num_arg = 1; num_arg < argc; num_arg++) {

        const char *arg = argv[num_arg];

        if (strcmp(arg, "--help") == 0 || strcmp(arg, "-h") == 0) {
            args_status = GOOD;

            PrintHelp();
        }

        else if (strcmp(arg, "--test_file_help") == 0) {
            args_status = GOOD;

            PrintTestFileHelp();
        }

        else if (strcmp(arg, "--solve") == 0 || strcmp(arg, "-s") == 0) {
            if (num_arg < argc - 3) {
                args_status = SolveFromArgs(argv + num_arg + 1);
            }
            else {
                args_status = BAD;
            }
        }

        else if (strcmp(arg, "--test") == 0 || strcmp(arg, "-t") == 0) {
            bool is_last = (num_arg == argc - 1);

            const char *next_arg = "";
            if (!is_last) {
                next_arg = argv[num_arg + 1];
            }

            args_status = TestingFromArgs (is_last, next_arg);
        }

        else if (strcmp(arg, "--epsilon") == 0 || strcmp(arg, "--eps") == 0) {
            args_status = GOOD;

            PrintEps();
        }

        else if (strcmp(arg, "--cat") == 0) {
            args_status = GOOD;

            FILE *file_cat = fopen(cat_filename, "r");

            if (file_cat != NULL) {
                PrintCat(file_cat);
            }
            else {
                RedText();
                printf("# No file with cat!\n");
                DefaultText();
            }

            printf("\n");
        }
    }

    if (args_status == BAD) {
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

        return GOOD;
    }

    return BAD;
}

Args_Status TestingFromArgs (bool is_last, const char *next_arg) {
    Args_Status args_status = BAD;

    if (is_last or next_arg[0] == '-') {
        args_status = GOOD;

        RunSolverTests(solver_tests);
    }
    else if (!IsCsvFileName (next_arg)) {
        args_status = IncorrectFileName (next_arg);
    }
    else {
        FILE *file_with_tests = fopen(next_arg, "r");

        if (file_with_tests == NULL) {
            args_status = IncorrectFileName (next_arg);
        }
        else {
            args_status = RunTestsFromFile (file_with_tests);
        }

        fclose(file_with_tests);
    }

    return args_status;
}

bool IsNumberInStr (const char *c) {
    while (*c < '0' || *c > '9') {
        c++;

        if (*c == '\0') {
            return false;
        }
    }

    return true;
}

Args_Status IncorrectFileName (const char *file_name) {
    RedText();
    printf ("# Incorrect file name: %s\n\n", file_name);
    DefaultText();

    return BAD;
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
