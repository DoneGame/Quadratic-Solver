#ifndef SOLVER_H
#define SOLVER_H

#include "num_roots.h"

const double PRECISION = 0.000001;

NUM_ROOTS SolveEquation  (double a, double b, double c, double *x1, double *x2);
NUM_ROOTS SolveQuadratic (double a, double b, double c, double *x1, double *x2);
NUM_ROOTS SolveLinear    (double a, double b, double *x);
int       NonZero        (double fp_number);

#endif
