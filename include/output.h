/**
 * @file output.h
 */

#ifndef OUTPUT_H
#define OUTPUT_H

#include "num_roots.h"

void EntryMessage    (void);
void PrintResults    (struct ROOTS solution);
void PrintTestingRes (const char *tested_func, int num_tests, int failed);
void PrintHelp       (void);

#endif
