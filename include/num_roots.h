/**
 * @file num_roots.h
 */

#ifndef NUM_ROOTS_H
#define NUM_ROOTS_H

/// Number of roots of equation
typedef enum __NUM_ROOTS {
    INF_ROOTS = -1, ///< Infinite number of roots
    NO_ROOTS  =  0, ///< No roots
    ONE_ROOT  =  1, ///< One root
    TWO_ROOTS =  2, ///< Two roots
} NUM_ROOTS;

#endif
