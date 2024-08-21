#ifndef TESTING_H
#define TESTING_H

#include "num_roots.h"

int SolverTest (struct solver_test test);
int RunSolverTests (void);

int RunNonZeroTests (void);
int NonZeroTest     (double in, int out);

#endif
