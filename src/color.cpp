/**
 * @file color.cpp
 * @brief Color text and background for command line
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "color.h"


/// ANSI Escape sequences color codes
typedef enum COLOR_CODES {
    RED_TEXT     = 31,
    YELLOW_TEXT  = 33,
    GREEN_TEXT   = 32,
    WHITE_TEXT   = 37,
    DEFAULT_TEXT = 0,

    WHITE_BG     = 47,
    DEFAULT_BG   = 49
} COLOR_CODES;


void ColorOn (void) {
    if (NotRedirected())
        system(" ");
}

void ColorTextAndBG (int color_number) {
    if (NotRedirected())
        printf("\x1b[" "%d" "m", color_number);
}


void RedText        (void) {ColorTextAndBG(RED_TEXT);}

void YellowText     (void) {ColorTextAndBG(YELLOW_TEXT);}

void GreenText      (void) {ColorTextAndBG(GREEN_TEXT);}

void WhiteText      (void) {ColorTextAndBG(WHITE_TEXT);}

void DefaultText    (void) {ColorTextAndBG(DEFAULT_TEXT);}


void WhiteBG        (void) {ColorTextAndBG(WHITE_BG);}

void DefaultBG      (void) {ColorTextAndBG(DEFAULT_BG);}


int NotRedirected (void) {
    return isatty(fileno(stdout));
}
