#ifndef ARGS_HANDLER_H
#define ARGS_HANDLER_H

typedef enum __ARGS {
    GOOD = 1,
    BAD = 0
} ARGS_STATUS;

void HandleArgs (int argc, char *argv[]);
ARGS_STATUS SolveFromArgs (char *argv[]);
int StartsWith(char *a, const char *b);
int IsNumberInStr (char *c);
void PrintHelp (void);

#endif
