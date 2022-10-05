
#ifndef SGUI_BUTTON_H
#define SGUI_BUTTON_H


#include "stdbool.h"


typedef struct
{
  unsigned short	x0;
  unsigned short	y0;
  unsigned short	x1;
  unsigned short	y1;
  unsigned short	rx;
  unsigned short	ry;
  unsigned short	frameWidth;
  unsigned short	buttonColor;
  unsigned short	frameColor;
  char *str;
  //const struct fontInfo *fontInfoStruct;
  unsigned short	fontSize;
  unsigned short	fontColor;
  unsigned short	textMarginX;
  unsigned short	textMarginY;
  bool inUsage;
  volatile	unsigned long	msDelay;
  
  unsigned short	textLenght;
  unsigned short	flag_buttonWasClicked;
  unsigned long 	timerVal;
  
  void (*action)(void);		
}Object_Button;


void	SGUI_drawButton(unsigned short page, unsigned short	buttonId);
void	SGUI_createButton(unsigned short page,
                      unsigned short	x0,	unsigned short	y0,
                      unsigned short	x1,	unsigned short	y1,
                      unsigned short	rx,	unsigned short	ry,
                      unsigned short	frameWidth,
                      unsigned short	buttonColor,
                      unsigned short	frameColor,
                      char			*str,
          //const struct fontInfo *fontInfoStruct,
                      unsigned short	fontSize,
                      unsigned short	fontColor,
                      unsigned short	textMarginX,
                      unsigned short	textMarginY,
                      bool inUsage,
                      unsigned short	msDelay,
                      void			(*action)(void));
void SGUI_buttonSetText(unsigned short page,
                        unsigned short buttonId,
                        char *str,
                        unsigned short	fontSize,
                        unsigned short fontColor/*,
            const struct fontInfo *fontInfoStruct*/);
void SGUI_buttonSetColor(unsigned short page,
                         unsigned short buttonId,
                         unsigned short buttonColor);
void SGUI_buttonSetFrameColor(unsigned short page,
                              unsigned short buttonId,
                              unsigned short frameColor);
void SGUI_buttonInUsage(unsigned short page,
                        unsigned short buttonId,
                        bool inUsage);


#endif
