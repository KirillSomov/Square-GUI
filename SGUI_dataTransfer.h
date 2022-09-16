
#ifndef SGUI_DATA_TRANSFER_H
#define SGUI_DATA_TRANSFER_H


#include "stdbool.h"


void SGUI_drawSquare(unsigned short x0, unsigned short y0, unsigned short x1, unsigned short y1, unsigned short color);
void SGUI_drawFilledSquare(unsigned short x0, unsigned short y0, unsigned short x1, unsigned short y1, unsigned short color);

bool SGUI_sampleTouch(unsigned short* x, unsigned short* y);




#endif
