/**
 * @file testing.h
 * @brief Unit testing
 */

#ifndef TESTING_H
#define TESTING_H

#include "num_roots.h"

/// Test result
typedef enum __TEST_STATUS {
    OK   = 0,
    FAIL = 1,
} TEST_STATUS;


/**
 * @brief SolveEquation() testing
 *
 * Checks function with tests from tests.h
 *
 * @return Number of failed tests
 */
int RunSolverTests      (void);

/**
 * @brief Single Solver test
 *
 * Checks function with test
 *
 * @param test Standard solver test
 *
 * @return Result of test (enum)
 */
TEST_STATUS SolverTest  (struct solver_test test);

/**
 * @brief NonZero() testing
 *
 * Checks function with tests from tests.h
 *
 * @return Number of failed tests
 */
int RunNonZeroTests     (void);

/**
 * @brief Single NonZero test
 *
 * Checks function with test
 *
 * @param test_number Number of test in sequence
 * @param in          Test input
 * @param out         Expected function output
 *
 * @return Result of test (enum)
 */
TEST_STATUS NonZeroTest (int test_number, double in, int out);

#endif
