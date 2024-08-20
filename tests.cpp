#include "quad.h"
#include <stdio.h>

double NonZero_in[10] = {0, 1, 0.01, 0.0000001};
int NonZero_out[10] = {0, 1, 1, 0};
int NonZeroTest (double in, int out);


int main() {
    int nonzero_failed = 0;
    int i = 0;
    for (i = 0; i < 4; i++) {
        double in = NonZero_in[i];
        int out = NonZero_out[i];
        if (!NonZeroTest(in, out)) {
            printf("NonZero test failed. In: %lg, correct out: %d, function out: %d\n", in, out, NonZero(in));
            nonzero_failed += 1;
        }
    }

    printf ("NonZero(): Failed %d out of %d\n", nonzero_failed, i);
}

int NonZeroTest (double in, int out) {
    return NonZero(in) == out;
}
