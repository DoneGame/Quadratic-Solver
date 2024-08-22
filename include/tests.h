#ifndef TESTS_H
#define TESTS_H

const double NonZero_in[] = {0, 1, 0.00001, 0.0000009};
const int NonZero_out[] = {0, 1, 1, 0};

#include "num_roots.h"

struct solver_test {
    int test_number;
    double a;
    double b;
    double c;
    NUM_ROOTS n_roots_exp;
    double x1_exp;
    double x2_exp;
} tests [] = {

//  n    a       b       c      n_roots     x1         x2
    1,   0,      0,      0,     INF_ROOTS,  0,         0,
    2,   0,      0,      1,     NO_ROOTS,   0,         0,
    3,   0,      1,      0,     ONE_ROOT,   0,         0,
    4,   0,      1,      1,     ONE_ROOT,  -1,         0,
    5,   1,      0,      0,     ONE_ROOT,   0,         0,
    6,   1,      0,      1,     NO_ROOTS,   0,         0,
    7,   1,      1,      0,     TWO_ROOTS, -1,         0,
    8,   1,      1,      1,     NO_ROOTS,   0,         0,
    9,   1.28,   5.67,  -10,    TWO_ROOTS, -5.781078,  1.351391,
    10, -8,     -55.6,  -5,     TWO_ROOTS, -6.858877, -0.091122,
    11,  0,      2,     -10,    ONE_ROOT,   5,         0,
    12,  1,      0,     -25,    TWO_ROOTS, -5,         5,
    13,  1,     -2,      1,     ONE_ROOT,   1,         0,
    14,  1,      0,     -1,     TWO_ROOTS, -1,         1,
    15,  1,     -1,     -1,     TWO_ROOTS, -0.618033,  1.618033,
    16,  10000, -6000,  -60,    TWO_ROOTS, -0.009838,  0.609838,
    17, -10,     6,      34,    TWO_ROOTS, -1.568154,  2.168154,
    18, -10000,  600.58, 308.55,TWO_ROOTS, -0.148175,  0.208233,
    19,  100000, 0.005, -0.005, TWO_ROOTS, -0.000223,  0.000223,
    20,  10,    -0.05,   0.05,  NO_ROOTS,   0,         0
};

#endif
