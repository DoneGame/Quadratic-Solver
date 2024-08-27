/**
 * @file output.h
 * @brief Most of the program's output
 */

#ifndef OUTPUT_H
#define OUTPUT_H

#include "num_roots.h"

/**
 * @brief Prints first message
 *
 * @see @ref main
 */
void EntryMessage      (void);

/**
 * @brief Solution output
 *
 * Prints results of solving equation.
 * Considers different number of roots and highlights with color.
 *
 * @param solution Struct with solution
 *
 */
void PrintResults      (struct Roots solution);

/**
 * @brief Testing result
 *
 * Prints information about failed tests in different colors
 *
 * @param tested_func Name of the function that was tested
 * @param num_tests   Number of tests
 * @param failed      Number of failed tests
 *
 * @see @ref RunSolverTests
 * @see @ref RunNonZeroTests
 */
void PrintTestingRes   (const char *tested_func, int num_tests, int failed);

/**
 * @brief Helpful information
 *
 * Prints helping information in console
 *
 * @see @ref HandleArgs
 */
void PrintHelp         (void);

/**
 * @brief Helpful information about file with tests
 *
 * Prints information in console
 *
 * @see @ref HandleArgs
 */
void PrintTestFileHelp (void);

/**
 * @brief Prints PRECISION
 *
 * Prints parameter for NonZero()
 *
 * @see @ref HandleArgs
 */
void PrintEps          (void);

/**
 * @brief Easter egg
 *
 * Prints poltorashka
 *
 * @param file_cat File with ASCII cat
 *
 * @see @ref HandleArgs
 */
void PrintCat          (FILE *file_cat);

#endif //OUTPUT_H
