/**
 * @file input.cpp
 * @brief All input functions of program
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "solver_structs.h"
#include "color.h"

/**
 * @brief Get coefficients from cin
 *
 * Search for 3 double numbers in one line,
 * doesn't pay attention to spaces and tabs,
 * finishes on EOF
 *
 *
 * @return Struct with 3 coefficients of equation
 */
struct COEFFICIENTS GetCoefs(void) {
    struct COEFFICIENTS coefs = {.a = 0, .b = 0, .c = 0};

    printf ("# Solving a*x^2 + b*x + c = 0\n");
    printf ("# Enter a, b, c (separated by spaces): ");

    while (scanf ("%lg %lg %lg", &coefs.a, &coefs.b, &coefs.c) != 3) {
        ClearBuffer();

        YellowText();
        printf("# Incorrect format. ");
        DefaultText();
        printf("Enter a, b, c: ");
    }

    printf("\n");

    return coefs;
}

/**
 * @brief Clears cin buffer
 *
 * Clears buffer to end of line,
 * aborts program if finds EOF
 *
 */
void ClearBuffer (void) {
    int s = '\0';
    while ((s = getchar()) != '\n') {
        if (s == EOF) {
            YellowText();
            printf("\nEOF: Noting else to read!");
            DefaultText();
            exit(1);
        }
    };
}

/**
 * @brief Get coefficients from command line arguments
 *
 * Search for number in each of 3 consecutive command line argument
 *
 *
 * @return Struct with 3 coefficients of equation
 */
struct COEFFICIENTS GetCoefsFromStr(char **start) {
    struct COEFFICIENTS coefs = {.a = 0, .b = 0, .c = 0};

    sscanf (*start++, "%lf", &coefs.a);
    sscanf (*start++, "%lf", &coefs.b);
    sscanf (*start++, "%lf", &coefs.c);

    return coefs;
}
