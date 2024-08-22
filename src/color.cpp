#include "../include/color.h"
#include <TXLib.h>

void RedText (void) {txSetConsoleAttr (FOREGROUND_RED | DEFAULT_BACKGROUND);}

void YellowText (void) {txSetConsoleAttr (FOREGROUND_YELLOW | DEFAULT_BACKGROUND);}

void GreenText (void) {txSetConsoleAttr (FOREGROUND_GREEN | DEFAULT_BACKGROUND);}

void WhiteText (void) {txSetConsoleAttr (FOREGROUND_WHITE | DEFAULT_BACKGROUND);}

void DefaultText (void) {txSetConsoleAttr (DEFAULT_COLOR_ATTR);}
