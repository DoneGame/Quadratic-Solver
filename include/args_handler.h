/**
 * @file args_handler.h
 * @brief Command line arguments handling
 */

#ifndef ARGS_HANDLER_H
#define ARGS_HANDLER_H

/// Checking for valid argument
typedef enum Args_Status {
    ARGS_GOOD = 1, ///< Was at least one valid argument
    ARGS_BAD  = 0, ///< No valid arguments
} Args_Status;

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
void                HandleArgs        (const int argc, const char *argv[]);

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
Args_Status         SolveFromArgs     (const char *argv[]);

/**
 * @brief --test argument handler
 *
 * Uses the next argument as the file name unless it is a flag
 *
 * @param is_last  Was --test/-t the last argument?
 * @param next_arg Next argument (if exists)
 *
 * @return Correctness of the passed arguments
 */
Args_Status         TestingFromArgs   (bool is_last, const char *next_arg);

/**
 * @brief Is number simbol in string
 *
 * Checks if string contains number
 *
 * @param c String
 *
 * @return Result of check (true or false)
 */
bool                IsNumberInStr     (const char *c);

/**
 * @brief Prints info about incorrect file name
 *
 * @param file_name String with file name
 *
 * @return Correctness of the passed arguments
 */
Args_Status         IncorrectFileName (const char *file_name);

/**
 * @brief Checks if file name ends with .csv
 *
 * @param arg String with command line argument
 *
 * @return Result of check (true or false)
 */
bool                IsCsvFileName     (const char *arg);

/**
 * @brief Get coefficients from command line arguments
 *
 * Search for number in each of 3 consecutive command line argument
 *
 * @param start Pointer to the first of three arguments
 *
 * @see @ref SolveFromArgs
 *
 * @return Struct with 3 coefficients of equation
 */
struct Coefficients GetCoefsFromStr   (const char **start);

#endif // ARGS_HANDLER_H
