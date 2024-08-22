#ifndef INPUT_H
#define INPUT_H

struct COEFFICIENTS GetCoefs        (void);
struct COEFFICIENTS GetCoefsFromStr (char **start);
void                ClearBuffer     (void);

#endif
