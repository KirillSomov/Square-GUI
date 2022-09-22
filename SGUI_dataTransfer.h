
#ifndef SGUI_DATA_TRANSFER_H
#define SGUI_DATA_TRANSFER_H


#include "stdbool.h"


void SGUI_setLcdPage(unsigned long page);
void SGUI_showLcdPage(unsigned long page);

void SGUI_LCD_drawSquare(unsigned short x0, unsigned short y0,
                         unsigned short x1, unsigned short y1,
                         unsigned short rx, unsigned short ry,
                         unsigned short color);
void SGUI_LCD_drawFilledSquare(unsigned short x0, unsigned short y0,
                               unsigned short x1, unsigned short y1,
                               unsigned short rx, unsigned short ry,
                               unsigned short color);
void SGUI_LCD_drawPicture(const unsigned char* picture,
                          unsigned long page,
                          unsigned short x, unsigned short y,
                          unsigned short w, unsigned short h);

bool SGUI_sampleTouch(unsigned short* x, unsigned short* y);


#endif
