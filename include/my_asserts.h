/**
 * @file my_asserts.h
 *
 * @brief my_assert and isfinite_assert
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
    #define my_assert(log_expr) {                                                             \
        if (!(log_expr)) {                                                                    \
            ColorOn();                                                                        \
            RedText();                                                                        \
            printf("Assertion failed!\n");                                                    \
            printf("File: %s, line: %d, function: %s()\n", __FILE__, __LINE__, __FUNCTION__); \
            printf("Logical expression: %s\n", #log_expr);                                    \
            DefaultText();                                                                    \
            exit(1);                                                                          \
        }                                                                                     \
    }

    #define isfinite_assert(fp) {                                                             \
        if (!isfinite(fp)) {                                                                  \
            ColorOn();                                                                        \
            RedText();                                                                        \
            printf("Assertion failed!\n");                                                    \
            printf("Error: %s is not finite double!\n", #fp);                                 \
            printf("File: %s, line: %d, function: %s()\n", __FILE__, __LINE__, __FUNCTION__); \
            printf("Value of %s: %lg\n", #fp, (fp));                                          \
            DefaultText();                                                                    \
            exit(1);                                                                          \
        }                                                                                     \
    }

#else
    #define my_assert(log_expr)
    #define isfinite_assert(fp)
#endif


#endif
