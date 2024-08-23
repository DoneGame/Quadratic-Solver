#ifndef TESTING_H
#define TESTING_H

typedef enum __TEST_STATUS {
    OK   = 0,
    FAIL = 1,
} TEST_STATUS;

int         RunTests        (const char *func_name, int (*func_to_test)(double), double tests_in[], int tests_exp_out[]);
TEST_STATUS Test            (int test_number, const char *func_name, int (*func_to_test)(double), double in, int exp_out);
void        PrintTestingRes (const char *tested_func, int num_tests, int failed);

#endif
