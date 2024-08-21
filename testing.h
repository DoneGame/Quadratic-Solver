#ifndef TESTING_H
#define TESTING_H

#include "num_roots.h"

typedef enum __TEST_STATUS {
    OK = 0,
    FAIL = 1
} TEST_STATUS;

int RunSolverTests      (void);
TEST_STATUS SolverTest  (struct solver_test test);

int RunNonZeroTests     (void);
TEST_STATUS NonZeroTest (int test_number, double in, int out);

#endif
