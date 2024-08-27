/**
 * @file solver.cpp
 * @brief Quadratic equation solver
 */

#include <math.h>

#include "solver.h"
#include "solver_structs.h"
#include "my_asserts.h"


struct Roots SolveEquation (struct Coefficients coefs) {

    isfinite_assert(coefs.a);
    isfinite_assert(coefs.b);
    isfinite_assert(coefs.c);

    if (NonZero(coefs.a)) {
        return SolveQuadratic (coefs);
    }

    struct Coefficients lin_coefs = {coefs.b, coefs.c, 0};

    return SolveLinear (lin_coefs);

}

struct Roots SolveLinear (struct Coefficients coefs) {

    struct Roots sol = {.num_roots = NO_ROOTS, .x1 = NAN, .x2 = NAN};

    if (NonZero(coefs.a)) {
        sol.x1 = -coefs.b / coefs.a;
        sol.num_roots = ONE_ROOT;

        isfinite_assert(sol.x1);

        return sol;
    }

    if (NonZero(coefs.b)) {
        sol.num_roots = NO_ROOTS;
    }
    else {
        sol.num_roots = INF_ROOTS;
    }

    return sol;

}

struct Roots SolveQuadratic (struct Coefficients coefs) {

    struct Roots sol = {.num_roots = NO_ROOTS, .x1 = NAN, .x2 = NAN};

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

int NonZero (double fp_number) {
    if (! isfinite(fp_number)) {
        return 1;
    }

    return fabs(fp_number) > PRECISION;
}
