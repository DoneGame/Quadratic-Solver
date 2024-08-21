#ifndef TESTS_H
#define TESTS_H

#include "num_roots.h"

struct solver_test {
    int n;
    double a;
    double b;
    double c;
    NUM_ROOTS n_roots_expected;
    double x1_expected;
    double x2_expected;
} tests [] = {

//  n    a      b       c   n_roots     x1         x2
    1,   0,     0,      0,  INF_ROOTS,  0,         0,
    2,   0,     0,      1,  NO_ROOTS,   0,         0,
    3,   0,     1,      0,  ONE_ROOT,   0,         0,
    4,   0,     1,      1,  ONE_ROOT,  -1,         0,
    5,   1,     0,      0,  ONE_ROOT,   0,         0,
    6,   1,     0,      1,  NO_ROOTS,   0,         0,
    7,   1,     1,      0,  TWO_ROOTS, -1,         0,
    8,   1,     1,      1,  NO_ROOTS,   0,         0,
    9,   1.28,  5.67,  -10, TWO_ROOTS, -5.781078,  1.351391,
    10, -8,    -55.6,  -5,  TWO_ROOTS, -6.858877, -0.091122,
    11,  0,     2,     -10, ONE_ROOT,   5,         0,
    12,  1,     0,     -25, TWO_ROOTS, -5,         5,
    13,  1,    -2,      1,  ONE_ROOT,   1,         0
};

#endif
