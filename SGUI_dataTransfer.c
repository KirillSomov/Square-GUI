
#include "SGUI_dataTransfer.h"
#include "LCD_api.h"


void SGUI_drawSquare(unsigned short x0, unsigned short y0, unsigned short x1, unsigned short y1, unsigned short color)
{
  LCD_drawSquare(x0, y0, x1, y1, color);
}

void SGUI_drawFilledSquare(unsigned short x0, unsigned short y0, unsigned short x1, unsigned short y1, unsigned short color)
{
  LCD_drawFilledSquare(x0, y0, x1, y1, color);
}
