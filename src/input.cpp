/**
 * @file input.cpp
 * @brief Most of the program's input
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "input.h"
#include "solver_structs.h"
#include "color.h"


struct Coefficients GetCoefs (void) {
    struct Coefficients coefs = {.a = 0, .b = 0, .c = 0};

    printf ("# Solving a*x^2 + b*x + c = 0\n\n");
    printf ("# Enter a, b, c (separated by spaces): ");

    while (scanf("%lg %lg %lg", &coefs.a, &coefs.b, &coefs.c) != 3) {
        ClearBuffer();

        if (getchar() == EOF) {
            coefs.a = NAN;
            coefs.b = NAN;
            coefs.c = NAN;

            return coefs;
        }

        YellowText();
        printf("# Incorrect format. ");
        DefaultText();
        printf("Enter a, b, c: ");
    }

    printf("# Entered: a = %.6lg, b = %.6lg, c = %.6lg\n", coefs.a, coefs.b, coefs.c);
    printf("\n");

    return coefs;
}

void ClearBuffer (void) {
    int s = '\0';
    while ((s = getchar()) != '\n') {
        if (s == EOF) {
            YellowText();
            printf("\nEOF: Noting else to read!");
            DefaultText();

            return;
        }
    }
}

void FileClearBuffer (FILE *file) {
    assert(file);

    int symbol = '\0';

    while ((symbol = getc(file)) != '\n' && symbol != EOF) {};
}
