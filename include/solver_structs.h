/**
 * @file solver_structs.h
 * @brief Structs for Solver
 */

#ifndef SOLVER_STRUCTS_H
#define SOLVER_STRUCTS_H

#include "num_roots.h"

/** @struct COEFFICIENTS
 *  @brief Coefficients of equation
 */
struct COEFFICIENTS {
    double a; ///< First coef
    double b; ///< Second coef
    double c; ///< Third coef
};

/** @struct ROOTS
 *  @brief Solution of equation
 */
struct ROOTS {
    NUM_ROOTS num_roots; ///< Number of roots
    double    x1;        ///< Smaller or single root
    double    x2;        ///< Larger root
};

#endif
