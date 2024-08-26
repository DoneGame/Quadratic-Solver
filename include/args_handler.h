/**
 * @file args_handler.h
 * @brief Command line arguments handling
 */

#ifndef ARGS_HANDLER_H
#define ARGS_HANDLER_H

/// Checking for valid argument
typedef enum __ARGS {
    GOOD = 1, ///< Was at least one valid argument
    BAD  = 0, ///< No valid arguments
} ARGS_STATUS;

/**
 * @brief Command line argument handler
 *
 * Goes though all arguments and performs appropriate actions
 *
 * @param argc Number of arguments
 * @param argv List of arguments
 *
 * @note Throws error if none of the arguments were correct
 */
void        HandleArgs        (int argc, char *argv[]);

/**
 * @brief --solve argument handler
 *
 * Searches next three args for coefficients and outputs
 * solution of quadratic equation
 *
 * @param argv List of arguments after -s or --solve
 *
 * @return Correctness of the passed arguments
 */
ARGS_STATUS SolveFromArgs     (char *argv[]);

/**
 * @brief Prints info about incorrect file name
 *
 * @param file_name String with file name
 *
 * @return Correctness of the passed arguments
 */
ARGS_STATUS IncorrectFileName (char *file_name);

/**
 * @brief Checks if file name ends with .csv
 *
 * @param arg String with command line argument
 *
 * @return 0 or 1
 */
int IsCsvFileName             (char *arg);

#endif
