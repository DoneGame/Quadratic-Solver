/**
 * @file tests.h
 * @brief All tests for unit testing
 */

#ifndef TESTS_H
#define TESTS_H

#include <math.h>
#include "testing.h"
#include "num_roots.h"

/**@var NonZero_tests_in
 *
 * Input data for NonZero() testing
 *
 * @warning -1 are treated as end of test list
 *
 * @see @ref RunNonZeroTests
 */
const double NonZero_tests_in[] =  {0, 1, 0.00001, 0.0000009, -0.00001, NAN, INFINITY, -1};

/**@var NonZero_tests_out
 *
 * Expected output data for NonZero() testing
 *
 * @warning All negative numbers are treated as end of test list
 *
 * @see @ref RunNonZeroTests
 */
const int    NonZero_tests_out[] = {0, 1, 1      , 0        , 1       , 1  , 1       , -1};

/**@var solver_tests
 *
 * Standard tests for SolveEquation() testing
 *
 * @see @ref RunSolverTests
 */
struct SOLVER_TEST solver_tests [] = {

//   n    a       b       c      n_roots     x1         x2
{    1,   0,      0,      0,     INF_ROOTS,  NAN,       NAN      },
{    2,   0,      0,      1,     NO_ROOTS,   NAN,       NAN      },
{    3,   0,      1,      0,     ONE_ROOT,   0,         NAN      },
{    4,   0,      1,      1,     ONE_ROOT,  -1,         NAN      },
{    5,   1,      0,      0,     ONE_ROOT,   0,         NAN      },
{    6,   1,      0,      1,     NO_ROOTS,   NAN,       NAN      },
{    7,   1,      1,      0,     TWO_ROOTS, -1,         0        },
{    8,   1,      1,      1,     NO_ROOTS,   NAN,       NAN      },
{    9,   1.28,   5.67,  -10,    TWO_ROOTS, -5.781078,  1.351391 },
{    10, -8,     -55.6,  -5,     TWO_ROOTS, -6.858877, -0.091122 },
{    11,  0,      2,     -10,    ONE_ROOT,   5,         NAN      },
{    12,  1,      0,     -25,    TWO_ROOTS, -5,         5        },
{    13,  1,     -2,      1,     ONE_ROOT,   1,         NAN      },
{    14,  1,      0,     -1,     TWO_ROOTS, -1,         1        },
{    15,  1,     -1,     -1,     TWO_ROOTS, -0.618033,  1.618033 },
{    16,  10000, -6000,  -60,    TWO_ROOTS, -0.009838,  0.609838 },
{    17, -10,     6,      34,    TWO_ROOTS, -1.568154,  2.168154 },
{    18, -10000,  600.58, 308.55,TWO_ROOTS, -0.148175,  0.208233 },
{    19,  100000, 0.005, -0.005, TWO_ROOTS, -0.000223,  0.000223 },
{    20,  10,    -0.05,   0.05,  NO_ROOTS,   NAN,       NAN      },
{   -1,   NAN,    NAN,    NAN,   NO_ROOTS,   NAN,       NAN      }  //stoping test (for correct processing)
};

#endif //TESTS_H
