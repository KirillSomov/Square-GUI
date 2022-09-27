
#include "SGUI_primitives.h"
#include "SGUI_dataTransfer.h"


void SGUI_drawLine(unsigned short x0, unsigned short y0,
                   unsigned short x1, unsigned short y1,
                   unsigned short width, unsigned short color)
{
  if(x0 == x1)
  {
    for(unsigned short i = 0; i < width; i++)
    {
      SGUI_LCD_drawLine(x0+i, y0, x1+i, y1, color);
    }
  }
  else
  {
    for(unsigned short i = 0; i < width; i++)
    {
      SGUI_LCD_drawLine(x0, y0+i, x1, y1+i, color);
    }
  }
}


void SGUI_drawFrame(unsigned short x0, unsigned short y0,
                    unsigned short x1, unsigned short y1,
                    unsigned short rx, unsigned short ry,
                    unsigned short frameWidth, unsigned short frameColor)
{
  for(unsigned short i = 0; i < frameWidth; i++)
  {
    SGUI_LCD_drawSquare(x0+i, y0+i, x1-i, y1-i, rx, ry, frameColor);
    SGUI_LCD_drawSquare(x0+i, y0+i, x1-i, y1-i, rx+2, ry+2, frameColor);
  }
}


void SGUI_drawFilledFrame(unsigned short x0, unsigned short y0,
                          unsigned short x1, unsigned short y1,
                          unsigned short rx, unsigned short ry,
                          unsigned short frameWidth, unsigned short frameColor,
                          unsigned short fillColor)
{
  SGUI_LCD_drawFilledSquare(x0, y0, x1, y1, rx, ry, fillColor);
  if(frameWidth > 0)
  {
    SGUI_drawFrame(x0, y0, x1, y1, rx, ry, frameWidth, frameColor);
  }
}
