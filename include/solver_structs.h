#ifndef SOLVER_STRUCTS_H
#define SOLVER_STRUCTS_H

#include "num_roots.h"

struct COEFFICIENTS {
    double a;
    double b;
    double c;
};

struct ROOTS {
    NUM_ROOTS num_roots;
    double x1;
    double x2;
};

#endif
