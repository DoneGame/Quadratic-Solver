#include <math.h>
#include <stdio.h>
#include <float.h>
#include "main.h"
#include "testing.h"

int main()
{
    double tests_in[]     = {NAN, INFINITY, 0, 9e15, 9e-15, 100, 0.01, DBL_MAX, DBL_MIN, DBL_EPSILON};
    int isnan_out[]       = {1,   0,        0, 0,    0,     0,   0,    0,       0,       0          };
    int isinf_out[]       = {0,   1,        0, 0,    0,     0,   0,    0,       0,       0          };
    int isfinite_out[]    = {0,   0,        1, 1,    1,     1,   1,    1,       1,       1          };

    RunTests("IsNaN",    IsNaN,    tests_in, isnan_out);
    RunTests("IsInf",    IsInf,    tests_in, isinf_out);
    RunTests("IsFinite", IsFinite, tests_in, isfinite_out);
}

int IsNaN (double fp_number) {
    return fp_number != fp_number;
}

int IsInf (double fp_number) {
    return (0.1*fp_number == fp_number) && (fp_number + 1 == fp_number);
}

int IsFinite (double fp_number) {
    return !IsInf (fp_number) && !IsNaN (fp_number);
}




