/**
 * @file color.cpp
 * @brief Color text and background for command line
 */

#include <stdlib.h>
#include <stdio.h>
#include "color.h"

/**
 * @brief Turn on colors for text
 *
 * Enable text color change with ANSI Escape Sequences
 *
 * @warning I don't know how it works
 */
void ColorOn     (void) {system(" ");}


void RedText     (void) {printf("\x1b[31m");}

void YellowText  (void) {printf("\x1b[33m");}

void GreenText   (void) {printf("\x1b[32m");}

void WhiteText   (void) {printf("\x1b[37m");}
/**
 * @brief Return to default color text
 */
void DefaultText (void) {printf("\x1b[0m");}


void WhiteBG     (void) {printf("\x1b[47m");}
/**
 * @brief Return to default background color
 */
void DefaultBG   (void) {printf("\x1b[49m");}
