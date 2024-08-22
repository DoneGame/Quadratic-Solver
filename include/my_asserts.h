#ifndef MY_ASSERTS_H
#define MY_ASSERTS_H

#include <stdio.h>
#include <stdlib.h>
#include "color.h"

#define my_assert(log_expr)                                                           \
if (!(log_expr)) {                                                                    \
    RedText();                                                                        \
    printf("File: %s, line: %d, function: %s()\n", __FILE__, __LINE__, __FUNCTION__); \
    printf("Logical expression: %s\n", #log_expr);                                    \
    DefaultText();                                                                    \
    exit(1);                                                                          \
}

#define isfinite_assert(fp)                                                           \
if (!isfinite(fp)) {                                                                  \
    RedText();                                                                        \
    printf("Error: %s is not finite double!\n", #fp);                                 \
    printf("File: %s, line: %d, function: %s()\n", __FILE__, __LINE__, __FUNCTION__); \
    printf("Value of %s: %lg\n", #fp, (fp));                                          \
    DefaultText();                                                                    \
    exit(1);                                                                          \
}

#endif
