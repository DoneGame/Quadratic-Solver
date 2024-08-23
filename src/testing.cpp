#include <stdio.h>
#include "testing.h"

int RunTests (const char *func_name, int (*func_to_test)(double),
              double tests_in[], int tests_exp_out[]) {
    printf("# Testing %s()\n", func_name);

    int num_tests = sizeof(tests_in) / sizeof(tests_in[0]);
    int failed = 0;
    for (int i = 0; i < num_tests; i++) {
        failed += (int) Test(i + 1, func_name, func_to_test, tests_in[i], tests_exp_out[i]);
    }

    PrintTestingRes(func_name, num_tests, failed);

    return failed;
}


TEST_STATUS Test (int test_number, const char *func_name, int (*func_to_test)(double),
                  double in, int exp_out) {
    int result = func_to_test(in);

    if (result != exp_out) {
        printf("# %s(): Test %d failed. Params: fp=%lg\n"
               "Expected: out=%d, get: out=%d\n",
               func_name, test_number, in, exp_out, result);

        return FAIL;
    }

    return OK;
}

void PrintTestingRes (const char *tested_func, int num_tests, int failed) {
    printf ("# %s(): Failed %d tests out of %d\n\n", tested_func, failed, num_tests);
}
