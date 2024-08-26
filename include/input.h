/**
 * @file input.h
 * @brief Most of the program's input
 */

#ifndef INPUT_H
#define INPUT_H

/**
 * @brief Get coefficients from cin
 *
 * Search for 3 double numbers in one line,
 * doesn't pay attention to spaces and tabs, finishes on EOF
 *
 * @see @ref main
 *
 * @return Struct with 3 coefficients of equation
 */
struct COEFFICIENTS GetCoefs        (void);

/**
 * @brief Get coefficients from command line arguments
 *
 * Search for number in each of 3 consecutive command line argument
 *
 * @see @ref SolveFromArgs
 *
 * @return Struct with 3 coefficients of equation
 */
struct COEFFICIENTS GetCoefsFromStr (char **start);

 /**
 * @brief Clears cin buffer
 *
 * Clears buffer to end of line, aborts program if finds EOF
 */
void                ClearBuffer     (void);

/**
 * @brief Is number simbol in string
 *
 * Checks if string contains number
 *
 * @param c String
 *
 * @return Result of check (0 or 1)
 */
int                 IsNumberInStr   (char *c);

#endif //INPUT_H
