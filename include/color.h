/**
 * @file color.h
 * @brief Color text and background for command line
 */

#ifndef COLOR_H
#define COLOR_H

/**
 * @brief Turn on colors for text
 *
 * Enable text color change with ANSI Escape Sequences
 *
 * @warning I don't know how it works
 */
void ColorOn     (void);
void RedText     (void);
void YellowText  (void);
void GreenText   (void);
void WhiteText   (void);
/**
 * @brief Return to default color text
 */
void DefaultText (void);


void WhiteBG     (void);
/**
 * @brief Return to default background color
 */
void DefaultBG   (void);

#endif
