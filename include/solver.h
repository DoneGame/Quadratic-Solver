/**
 * @file solver.h
 * @brief Quadratic equation solver
 */

#ifndef SOLVER_H
#define SOLVER_H

#include "num_roots.h"

/**@var PRECISION
 * Treshold for determining zero value of double
 *
 * @see @ref NonZero
 */
const double PRECISION = 0.000001;

/**
 * @brief Main solver
 *
 * Decides to which class equation
 * can be assigned
 *
 * @param coefs Struct with coefficients of equation
 *
 * @return Struct with solution
 *
 * @see @ref Coefficients
 * @see @ref Roots
 */
struct Roots SolveEquation  (struct Coefficients coefs);

/**
 * @brief Linear equation solver
 *
 * Solves a*x + b = 0 equation
 * Returns ROOTS.x1 = NAN if root doesn't exist
 *
 * @param coefs Struct with coefficients of equation
 *
 * @warning Only two first coeficients are used (a and b) and only x1 contains root (if it exists)
 *
 * @return Struct with solution
 *
 * @see @ref SolveEquation
 */
struct Roots SolveQuadratic (struct Coefficients coefs);

/**
 * @brief Quadratic equation solver
 *
 * Solves a*x^2 + b*x + c = 0 equation
 * Returns ROOTS.x1 = NAN or x2 = NAN if appropriate root doesn't exist
 *
 * @param coefs Struct with coefficients of equation
 *
 * @warning If equation have one solution, only x1 contains root
 *
 * @return Struct with solution
 *
 * @see @ref SolveEquation
 */
struct Roots SolveLinear    (struct Coefficients coefs);

/**
 * @brief Number is non-zero
 *
 * Checks whether floating point number can be considered
 * non-zero with given precision (see PRECISION constant)
 *
 * @warning NAN and INFINITY are considered non-zero
 *
 * @param fp_number Floating points number
 *
 * @return 0 or 1
 */
bool         NonZero        (double fp_number);

#endif //SOLVER_H
