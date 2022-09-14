
#include "SGUI_primitives.h"
#include "SGUI_dataTransfer.h"


void SGUI_drawFrame(unsigned short x0, unsigned short y0, unsigned short x1, unsigned short y1,
                    unsigned short frameWidth, unsigned short frameColor)
{
  for(unsigned short i = 0; i < frameWidth; i++)
  {
    SGUI_drawSquare(x0+i, y0+i, x1-i, y1-i, frameColor);
  }
}


void SGUI_drawFilledFrame(unsigned short x0, unsigned short y0, unsigned short x1, unsigned short y1,
                          unsigned short frameWidth, unsigned short frameColor,
                          unsigned short fillColor)
{
  SGUI_drawFilledSquare(x0, y0, x1, y1, fillColor);
  if(frameWidth > 0)
  {
    SGUI_drawFrame(x0, y0, x1, y1, frameWidth, frameColor);
  }
}
