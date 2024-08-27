/**
 * @file color.h
 * @brief Color text and background for command line
 */

#ifndef COLOR_H
#define COLOR_H

/// ANSI Escape sequences color codes
typedef enum Color_Codes {
    RED_TEXT     = 31,
    YELLOW_TEXT  = 33,
    GREEN_TEXT   = 32,
    WHITE_TEXT   = 37,
    DEFAULT_TEXT = 0,

    WHITE_BG     = 47,
    DEFAULT_BG   = 49
} Color_Codes;


/**
 * @brief Turn on colors for text
 *
 * Enable text color change with ANSI Escape Sequences
 *
 * @warning I don't know how it works
 */
void ColorOn        (void);

/**
 * @brief Colors the text
 *
 * Prints escape sequence if output wasn't redirected
 *
 * @param color_number Number from ANSI Escape Sequences
 */
void ColorTextAndBG (Color_Codes color_number);

void RedText        (void);
void YellowText     (void);
void GreenText      (void);
void WhiteText      (void);
/**
 * @brief Return to default color text
 */
void DefaultText    (void);


void WhiteBG        (void);
/**
 * @brief Return to default background color
 */
void DefaultBG      (void);

/**
 * @brief Checks if stdout was redirected
 *
 * Using to not send escape sequences outside command line
 *
 * @return Result of check (true or false)
 */
bool NotRedirected  (void);

#endif //COLOR_H
