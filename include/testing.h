/**
 * @file testing.h
 * @brief Unit testing
 */

#ifndef TESTING_H
#define TESTING_H

#include "num_roots.h"
#include "args_handler.h"

/** @struct SOLVER_TEST
 *  @brief Test for SolveEquation()
 *
 *  @warning All negative test numbers are treated as end of test list
 */
 struct Solver_Test {
    int       test_number; ///< Test number - must be non-negative for real tests and negative for last (stopping) test
    double    a;           ///< First coef
    double    b;           ///< Second coef
    double    c;           ///< Third coef
    Num_Roots n_roots_exp; ///< Number of roots (expected)
    double    x1_exp;      ///< Smaller or single root (expected)
    double    x2_exp;      ///< Larger root (expected)
};

/// Test result
typedef enum Test_Status {
    OK   = 0,
    FAIL = 1,
} Test_Status;


/**
 * @brief SolveEquation() testing
 *
 * Checks function with tests from tests.h
 *
 * @param tests Tests to run
 *
 * @warning All negative test numbers are treated as end of test list
 *
 * @return Number of failed tests
 */
int         RunSolverTests        (struct Solver_Test tests[]);

/**
 * @brief Single Solver test
 *
 * Checks function with test
 *
 * @param test Standard solver test
 *
 * @return Result of test (enum)
 */
Test_Status SolverTest            (struct Solver_Test test);

/**
 * @brief NonZero() testing
 *
 * Checks function with tests from tests.h
 *
 * @return Number of failed tests
 */
int         RunNonZeroTests       (const double *tests_in, const int *tests_out);

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
Test_Status NonZeroTest           (int test_number, double in, int out);

/**
 * @brief Runs Solver tests from given file
 *
 * Get all tests from given cvs file and passes them to RunSolverTests()
 *
 * @param file_with_tests File pointer (file in csv format)
 *
 * @return Correctness of passed argument
 */
Args_Status RunTestsFromFile      (FILE *file_with_tests);

#endif //TESTING_H
