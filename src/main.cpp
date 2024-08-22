#include "num_roots.h"
#include "input.h"
#include "solver.h"
#include "solver_structs.h"
#include "output.h"
#include "testing.h"
#include "args_handler.h"
#include "color.h"
#include <stdio.h>

int main (int argc, char *argv[]) {
    ColorOn();

    if (argc > 1) {
        HandleArgs (argc, argv);
    }
    else {

        printf("# Second power equation solver\n");

        struct COEFFICIENTS coefficients = GetCoefs();

        struct ROOTS solution = SolveEquation (coefficients);

        PrintResults (solution);

    }
}
