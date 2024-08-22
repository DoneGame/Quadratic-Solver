#include "input.h"
#include "solver_structs.h"
#include <stdio.h>

struct COEFFICIENTS GetCoefs(void) {
    struct COEFFICIENTS coefs = {.a=0, .b=0, .c=0};

    printf ("# Solving a*x^2 + b*x + c = 0\n");
    printf ("# Enter a, b, c (separated by spaces): ");
    while (scanf ("%lg %lg %lg", &coefs.a, &coefs.b, &coefs.c) != 3) {
        ClearBuffer();

        printf("# Incorrect format. Enter a, b, c: ");
    }

    return coefs;
}

void ClearBuffer (void) {
    int s = '\0';
    while ((s = getchar()) != '\n' && s != EOF);
}

struct COEFFICIENTS GetCoefsFromStr (char **start) {
    struct COEFFICIENTS coefs = {.a=0, .b=0, .c=0};

    sscanf (*start++, "%lf", &coefs.a);
    sscanf (*start++, "%lf", &coefs.b);
    sscanf (*start++, "%lf", &coefs.c);

    return coefs;
}
