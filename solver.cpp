#include "solver.h"
#include "solver_structs.h"
#include <math.h>
#include <assert.h>


//-----------------------------------
//! Solving equation ax^2 + bx + c = 0 with any coefs
//!
//! @param [in]  a  first coef
//! @param [in]  b  second coef
//! @param [in]  c  third coef
//!
//! @param [out] x1 smallest or single root
//! @param [out] x2 largest root
//!
//! @return number of roots
//!
//! @note x1 = 0, x2 = 0 if equation have no roots or infinite number of roots,
//!       x2 = 0 if eq. have one root
//-----------------------------------

struct ROOTS SolveEquation (struct COEFFICIENTS coefs) {

    assert(isfinite(coefs.a));
    assert(isfinite(coefs.b));
    assert(isfinite(coefs.c));

    if (NonZero(coefs.a)) {
        return SolveQuadratic (coefs);
    }

    struct COEFFICIENTS lin_coefs = {0, 0, 0};
    lin_coefs.a = coefs.b;
    lin_coefs.b = coefs.c;

    return SolveLinear (lin_coefs);

}

struct ROOTS SolveLinear (struct COEFFICIENTS coefs) {

    struct ROOTS sol = {NO_ROOTS, 0, 0};

    if (NonZero(coefs.a)) {
        sol.x1 = -coefs.b / coefs.a;
        sol.num_roots = ONE_ROOT;

        assert(isfinite(sol.x1));

        return sol;
    }

    if (NonZero(coefs.b)) sol.num_roots = NO_ROOTS;
    else sol.num_roots = INF_ROOTS;

    return sol;

}

struct ROOTS SolveQuadratic (struct COEFFICIENTS coefs) {

    struct ROOTS sol = {NO_ROOTS, 0, 0};

    double descr = coefs.b*coefs.b - 4*coefs.a*coefs.c;

    if (NonZero(descr)) {
        if (descr < 0) {
            sol.num_roots = NO_ROOTS;
            return sol;
        }

        else {
            double sqrt_descr = sqrt(descr);

            double root_1 = (-coefs.b + sqrt_descr) / (2*coefs.a);
            double root_2 = (-coefs.b - sqrt_descr) / (2*coefs.a);

            assert(isfinite(root_1));
            assert(isfinite(root_2));

            sol.x1 = (root_1 < root_2) ? root_1 : root_2; // min
            sol.x2 = (root_1 > root_2) ? root_1 : root_2; // max

            sol.num_roots = TWO_ROOTS;
            return sol;
        }
    }


    sol.x1 = -coefs.b / (2*coefs.a);

    assert(isfinite(sol.x1));

    sol.num_roots = ONE_ROOT;
    return sol;

}

int NonZero (double fp_number) {return (fabs(fp_number) > PRECISION) ? 1 : 0;}
