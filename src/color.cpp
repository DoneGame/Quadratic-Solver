#include "color.h"
#include <stdlib.h>
#include <stdio.h>

void ColorOn (void) {system(" ");}


void RedText (void) {printf("\x1b[31m");}

void YellowText (void) {printf("\x1b[33m");}

void GreenText (void) {printf("\x1b[32m");}

void WhiteText (void) {printf("\x1b[37m");}

void DefaultText (void) {printf("\x1b[0m");}


void WhiteBG (void) {printf("\x1b[47m");}

void DefaultBG (void) {printf("\x1b[49m");}
