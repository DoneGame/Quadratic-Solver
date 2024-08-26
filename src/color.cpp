/**
 * @file color.cpp
 * @brief Color text and background for command line
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "color.h"


void ColorOn (void) {
    if (NotRedirected())
        system(" ");
}

void ColorTextAnbBG (int color_number) {
    if (NotRedirected())
        printf("\x1b[" "%d" "m", color_number);
}


void RedText        (void) {ColorTextAnbBG(31);}

void YellowText     (void) {ColorTextAnbBG(33);}

void GreenText      (void) {ColorTextAnbBG(32);}

void WhiteText      (void) {ColorTextAnbBG(37);}

void DefaultText    (void) {ColorTextAnbBG(0);}


void WhiteBG        (void) {ColorTextAnbBG(47);}

void DefaultBG      (void) {ColorTextAnbBG(49);}


int NotRedirected (void) {
    return isatty(fileno(stdout));
}
