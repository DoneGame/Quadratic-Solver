#include "output.h"
#include "solver_structs.h"
#include "color.h"
#include <stdio.h>

void PrintResults (struct ROOTS solution) {
    switch (solution.num_roots) {
        case NO_ROOTS:  YellowText();
                        printf("# No roots\n");
                        break;

        case ONE_ROOT:  GreenText();
                        printf("# x = %.5lg\n", solution.x1);
                        break;

        case TWO_ROOTS: GreenText();
                        printf("# x1 = %.5lg\n"
                               "# x2 = %.5lg\n", solution.x1, solution.x2);
                        break;

        case INF_ROOTS: YellowText();
                        printf("# Infinite number of roots\n");
                        break;

        default:        RedText();
                        printf("# PrintResults(): n_roots is incorrect\n");
    }

    DefaultText();
}
