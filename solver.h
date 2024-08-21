typedef enum __NUM_ROOTS {
    INF_ROOTS = -1,
    NO_ROOTS  =  0,
    ONE_ROOT  =  1,
    TWO_ROOTS =  2,
} NUM_ROOTS;

NUM_ROOTS SolveEquation  (double a, double b, double c, double *x1, double *x2);
NUM_ROOTS SolveQuadratic (double a, double b, double c, double *x1, double *x2);
NUM_ROOTS SolveLinear    (double a, double b, double *x);
int       NonZero        (double fp_number);
