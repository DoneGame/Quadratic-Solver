#ifndef SOLVER_H
#define SOLVER_H

#include "num_roots.h"

const double PRECISION = 0.000001;

struct ROOTS SolveEquation  (struct COEFFICIENTS coefs);
struct ROOTS SolveQuadratic (struct COEFFICIENTS coefs);
struct ROOTS SolveLinear    (struct COEFFICIENTS coefs);
int          NonZero        (double fp_number);

#endif
