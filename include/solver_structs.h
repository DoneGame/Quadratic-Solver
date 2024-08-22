/**
 * @file solver_structs.h
 */

#ifndef SOLVER_STRUCTS_H
#define SOLVER_STRUCTS_H

#include "num_roots.h"

/** @struct COEFFICIENTS
 *  @brief Coefficients of equation
 *  @var COEFFICIENTS::a
 *  First coef
 *  @var COEFFICIENTS::b
 *  Second coef
 *  @var COEFFICIENTS::c
 *  Third coef
 */
struct COEFFICIENTS {
    double a;
    double b;
    double c;
};

/** @struct ROOTS
 *  @brief Solution of equation
 *  @var ROOTS::num_roots
 *  Number of roots
 *  @var ROOTS::x1
 *  Smallest or single root
 *  @var ROOTS::x2
 *  Largest root
 */
struct ROOTS {
    NUM_ROOTS num_roots;
    double    x1;
    double    x2;
};

#endif
