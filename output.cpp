#include "output.h"
#include <stdio.h>

void PrintResults (NUM_ROOTS n_roots, double x1, double x2) {
    switch (n_roots) {
        case NO_ROOTS:  printf("# No roots\n");
                        break;

        case ONE_ROOT:  printf("# x = %.5lg\n", x1);
                        break;

        case TWO_ROOTS: printf("# x1 = %.5lg\n"
                               "# x2 = %.5lg\n", x1, x2);
                        break;

        case INF_ROOTS: printf("# Infinite number of roots\n");
                        break;

        default:        printf("# PrintResults(): n_roots is incorrect\n");
    }
}
