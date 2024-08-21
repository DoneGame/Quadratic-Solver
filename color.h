#ifndef COLOR_H
#define COLOR_H

#include <TXLib.h>

const unsigned DEFAULT_COLOR_ATTR = txGetConsoleAttr();
const unsigned DEFAULT_BACKGROUND = DEFAULT_COLOR_ATTR & 240;

void RedText (void);
void YellowText (void);
void GreenText (void);
void WhiteText (void);
void DefaultText (void);

#endif
