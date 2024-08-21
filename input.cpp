#include "input.h"
#include <stdio.h>

void GetCoefs(double *a, double *b, double *c) {

    printf("# a*x^2 + b*x + c = 0\n");
    printf("# Enter a, b, c (separated by spaces): ");
    while (scanf("%lg %lg %lg", a, b, c) != 3) {
        ClearBuffer();

        printf("# Incorrect format. Enter a, b, c: ");
    }

}

void ClearBuffer (void) {
    int s = '\0';
    while ((s = getchar()) != '\n' && s != EOF);
}
