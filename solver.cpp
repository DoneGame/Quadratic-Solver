#include "solver.h"
#include <math.h>
#include <assert.h>

NUM_ROOTS SolveEquation (double a, double b, double c,
                         double *x1, double *x2) {

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != x2);

    if (NonZero(a)) {
        return SolveQuadratic (a, b, c, x1, x2);
    }

    return SolveLinear (b, c, x1);

}

NUM_ROOTS SolveLinear (double a, double b, double *x) {

    if (NonZero(a)) {
        *x = -b / a;

        assert(isfinite(*x));

        return ONE_ROOT;
    }

    if (NonZero(b)) return NO_ROOTS;
    else return INF_ROOTS;

}

NUM_ROOTS SolveQuadratic (double a, double b, double c,
                          double *x1, double *x2) {

    double D = b*b - 4*a*c;

    if (NonZero(D)) {
        if (D < 0) {
            return NO_ROOTS;
        }

        else {
            double sqrt_D = sqrt(D);

            double sol1 = (-b + sqrt_D) / (2*a);
            double sol2 = (-b - sqrt_D) / (2*a);

            assert(isfinite(sol1));
            assert(isfinite(sol2));

            *x1 = (sol1 < sol2) ? sol1 : sol2; // min
            *x2 = (sol1 > sol2) ? sol1 : sol2; // max

            return TWO_ROOTS;
        }
    }


    *x1 = -b / (2*a);

    assert(isfinite(*x1));

    return ONE_ROOT;

}

int NonZero (double fp_number) {return (fabs(fp_number) > PRECISION) ? 1 : 0;}
