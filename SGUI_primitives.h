
#ifndef SGUI_PRIMITIVES_H
#define SGUI_PRIMITIVES_H


void	GUI_intToStr(int num, char *strBuf);
void	GUI_floatToStr(float num, char *strBuf);

void SGUI_drawLine(unsigned short x0, unsigned short y0,
                   unsigned short x1, unsigned short y1,
                   unsigned short width, unsigned short color);

void SGUI_drawFrame(unsigned short x0, unsigned short y0,
                    unsigned short x1, unsigned short y1,
                    unsigned short rx, unsigned short ry,
                    unsigned short frameWidth, unsigned short frameColor);
void SGUI_drawFilledFrame(unsigned short x0, unsigned short y0,
                          unsigned short x1, unsigned short y1,
                          unsigned short rx, unsigned short ry,
                          unsigned short frameWidth, unsigned short frameColor,
                          unsigned short fillColor);


#endif
