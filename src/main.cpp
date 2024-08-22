#include "../include/num_roots.h"
#include "../include/input.h"
#include "../include/solver.h"
#include "../include/solver_structs.h"
#include "../include/output.h"
#include "../include/testing.h"
#include "../include/args_handler.h"
#include <stdio.h>

int main (int argc, char *argv[]) {
    if (argc > 1) {
        HandleArgs (argc, argv);
    }
    else {

        printf("# Second power equation solver\n");

        struct COEFFICIENTS coefficients = GetCoefs ();

        struct ROOTS solution = SolveEquation (coefficients);

        PrintResults (solution);

    }
}
