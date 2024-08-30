/**
 * @file my_asserts.h
 *
 * @brief Implementation of asserts with define
 *
 * Can be deactivated with #define DEACTIVATE_MY_ASSERTS or NBEDUG
 */

#ifndef MY_ASSERTS_H
#define MY_ASSERTS_H

#include <stdio.h>
#include <stdlib.h>
#include "color.h"

//#define DEACTIVATE_MY_ASSERTS


#if (!defined (NDEBUG) && !defined (DEACTIVATE_MY_ASSERTS))
    /** My implementation of assert() from assert.h*/
    #define my_assert(log_expr) {                                                             \
        if (! (log_expr)) {                                                                    \
            ColorOn();                                                                        \
            RedText();                                                                        \
            printf("Assertion failed!\n");                                                    \
            printf("File: %s, line: %d, function: %s()\n", __FILE__, __LINE__, __FUNCTION__); \
            printf("Logical expression: %s\n", #log_expr);                                    \
            DefaultText();                                                                    \
            exit(1);                                                                          \
        }                                                                                     \
    }

    /** United impementation of assert(isfinite(fp_number)),
        gives additional information about fp_number value*/
    #define isfinite_assert(fp_number) {                                                      \
        if (! isfinite(fp_number)) {                                                           \
            ColorOn();                                                                        \
            RedText();                                                                        \
            printf("Assertion failed!\n");                                                    \
            printf("Error: %s is not finite double!\n", #fp_number);                          \
            printf("File: %s, line: %d, function: %s()\n", __FILE__, __LINE__, __FUNCTION__); \
            printf("Value of %s: %lg\n", #fp_number, (fp_number));                            \
            DefaultText();                                                                    \
            exit(1);                                                                          \
        }                                                                                     \
    }

#else
    #define my_assert(log_expr)
    #define isfinite_assert(fp_number)
#endif


#endif //MY_ASSERTS_H
