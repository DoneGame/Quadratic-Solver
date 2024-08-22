#ifndef COLOR_H
#define COLOR_H

#include <TXLib.h>

const unsigned DEFAULT_COLOR_ATTR = txGetConsoleAttr();
const unsigned TEXT_COLOR_MASK = 240;
const unsigned DEFAULT_BACKGROUND = DEFAULT_COLOR_ATTR & TEXT_COLOR_MASK;

void RedText (void);
void YellowText (void);
void GreenText (void);
void WhiteText (void);
void DefaultText (void);

#endif
