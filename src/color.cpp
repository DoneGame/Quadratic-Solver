/**
 * @file color.cpp
 * @brief Color text and background for command line
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "color.h"


void ColorOn     (void) {system(" ");}


void RedText     (void) {if (NotRedirected())
                            printf("\x1b[31m");}

void YellowText  (void) {if (NotRedirected())
                            printf("\x1b[33m");}

void GreenText   (void) {if (NotRedirected())
                            printf("\x1b[32m");}

void WhiteText   (void) {if (NotRedirected())
                            printf("\x1b[37m");}

void DefaultText (void) {if (NotRedirected())
                            printf("\x1b[0m");}


void WhiteBG     (void) {if (NotRedirected())
                            printf("\x1b[47m");}

void DefaultBG   (void) {if (NotRedirected())
                            printf("\x1b[49m");}

int NotRedirected (void) {return isatty(fileno(stdout));}
