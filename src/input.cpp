/**
 * @file input.cpp
 * @brief Most of the program's input
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "solver_structs.h"
#include "color.h"


struct COEFFICIENTS GetCoefs(void) {
    struct COEFFICIENTS coefs = {.a = 0, .b = 0, .c = 0};

    printf ("# Solving a*x^2 + b*x + c = 0\n\n");
    printf ("# Enter a, b, c (separated by spaces): ");

    while (scanf ("%lg %lg %lg", &coefs.a, &coefs.b, &coefs.c) != 3) {
        ClearBuffer();

        YellowText();
        printf("# Incorrect format. ");
        DefaultText();
        printf("Enter a, b, c: ");
    }

    printf ("# Entered: a = %.6lg, b = %.6lg, c = %.6lg\n", coefs.a, coefs.b, coefs.c);
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
            exit(1);
        }
    };
}

struct COEFFICIENTS GetCoefsFromStr(char **start) {
    struct COEFFICIENTS coefs = {.a = 0, .b = 0, .c = 0};

    sscanf (*start++, "%lf", &coefs.a);
    sscanf (*start++, "%lf", &coefs.b);
    sscanf (*start++, "%lf", &coefs.c);

    return coefs;
}

int IsNumberInStr (char *c) {
    while (*c < '0' || *c > '9') {
        if (*(++c) == '\0') return 0;
    }

    return 1;
}
