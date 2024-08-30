/**
 * @file color.cpp
 * @brief Color text and background for command line
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "color.h"


void ColorOn (void) {
    if (NotRedirected())
        system(" ");
}

void ColorTextAndBG (Color_Codes color_number) {
    if (NotRedirected())
        printf("\x1b[" "%d" "m", color_number);
}


void RedText        (void) { ColorTextAndBG(RED_TEXT);     }

void YellowText     (void) { ColorTextAndBG(YELLOW_TEXT);  }

void GreenText      (void) { ColorTextAndBG(GREEN_TEXT);   }

void WhiteText      (void) { ColorTextAndBG(WHITE_TEXT);   }

void DefaultText    (void) { ColorTextAndBG(DEFAULT_TEXT); }


void WhiteBG        (void) { ColorTextAndBG(WHITE_BG);     }

void DefaultBG      (void) { ColorTextAndBG(DEFAULT_BG);   }


bool NotRedirected (void) {
    return isatty(fileno(stdout));
}
