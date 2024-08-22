/**
 * @file solver.cpp
 * @brief Quadratic equation solver
 */

#include <math.h>
#include "solver.h"
#include "solver_structs.h"
#include "my_asserts.h"


/**
 * @brief Main solver
 *
 * Decides to which class equation
 * can be assigned
 *
 * @param coefs Struct with coefficients of equation
 *
 * @return Struct with solution
 */
struct ROOTS SolveEquation (struct COEFFICIENTS coefs) {

    isfinite_assert(coefs.a);
    isfinite_assert(coefs.b);
    isfinite_assert(coefs.c);

    if (NonZero(coefs.a)) {
        return SolveQuadratic (coefs);
    }

    struct COEFFICIENTS lin_coefs = {0, 0, 0};
    lin_coefs.a = coefs.b;
    lin_coefs.b = coefs.c;

    return SolveLinear (lin_coefs);

}

/**
 * @brief Linear equation solver
 *
 * Solves a*x + b = 0 equation
 *
 * @param coefs Struct with coefficients of equation
 *
 * @warning Only two first coeficients are used (a and b) and only x1 contains root
 *
 * @return Struct with solution
 */
struct ROOTS SolveLinear (struct COEFFICIENTS coefs) {

    struct ROOTS sol = {.num_roots = NO_ROOTS, .x1 = 0, .x2 = 0};

    if (NonZero(coefs.a)) {
        sol.x1 = -coefs.b / coefs.a;
        sol.num_roots = ONE_ROOT;

        isfinite_assert(sol.x1);

        return sol;
    }

    if (NonZero(coefs.b)) sol.num_roots = NO_ROOTS;
    else sol.num_roots = INF_ROOTS;

    return sol;

}

/**
 * @brief Quadratic equation solver
 *
 * Solves a*x^2 + b*x + c = 0 equation
 *
 * @param coefs Struct with coefficients of equation
 *
 * @warning If equation have one solution, only x1 contains root
 *
 * @return Struct with solution
 */
struct ROOTS SolveQuadratic (struct COEFFICIENTS coefs) {

    struct ROOTS sol = {.num_roots = NO_ROOTS, .x1 = 0, .x2 = 0};

    double descr = coefs.b * coefs.b - 4 * coefs.a * coefs.c;

    if (NonZero(descr)) {
        if (descr < 0) {
            sol.num_roots = NO_ROOTS;
            return sol;
        }

        else {
            double sqrt_descr = sqrt(descr);

            double root_1 = (-coefs.b + sqrt_descr) / (2 * coefs.a);
            double root_2 = (-coefs.b - sqrt_descr) / (2 * coefs.a);

            isfinite_assert(root_1);
            isfinite_assert(root_2);

            sol.x1 = (root_1 < root_2) ? root_1 : root_2; // min
            sol.x2 = (root_1 > root_2) ? root_1 : root_2; // max

            sol.num_roots = TWO_ROOTS;
            return sol;
        }
    }


    sol.x1 = -coefs.b / (2 * coefs.a);

    isfinite_assert(sol.x1);

    sol.num_roots = ONE_ROOT;
    return sol;

}

/**
 * @brief Number is non-zero
 *
 * Checks whether floating point number can be considered
 * non-zero with given precision (see PRECISION constant)
 *
 * @param fp_number Floating points number
 *
 * @return 0 or 1
 */
int NonZero (double fp_number) {return fabs(fp_number) > PRECISION;}
