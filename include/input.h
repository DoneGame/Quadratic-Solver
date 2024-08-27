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
struct Coefficients GetCoefs        (void);

 /**
 * @brief Clears cin buffer
 *
 * Clears buffer to end of line, aborts program if finds EOF
 */
void                ClearBuffer     (void);

/**
 * @brief Clears file buffer for fscanf()
 *
 * Runs through file line, clearing buffer
 *
 * @param file File pointer (file in csv format)
 */
void                FileClearBuffer (FILE *file);

#endif //INPUT_H
