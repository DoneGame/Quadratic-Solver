#ifndef TESTS_H
#define TESTS_H

#include "num_roots.h"

int SolverTest     (int n, double a, double b, double c,
                    NUM_ROOTS n_roots_exp, double x1_exp, double x2_exp);
int RunSolverTests (void);

int RunNonZeroTests (void);
int NonZeroTest     (double in, int out);

#endif
