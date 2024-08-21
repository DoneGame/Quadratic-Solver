#include "output.h"
#include "color.h"
#include <stdio.h>

void PrintResults (NUM_ROOTS n_roots, double x1, double x2) {
    switch (n_roots) {
        case NO_ROOTS:  YellowText();
                        printf("# No roots\n");
                        break;

        case ONE_ROOT:  GreenText();
                        printf("# x = %.5lg\n", x1);
                        break;

        case TWO_ROOTS: GreenText();
                        printf("# x1 = %.5lg\n"
                               "# x2 = %.5lg\n", x1, x2);
                        break;

        case INF_ROOTS: YellowText();
                        printf("# Infinite number of roots\n");
                        break;

        default:        RedText();
                        printf("# PrintResults(): n_roots is incorrect\n");
    }

    DefaultText();
}
