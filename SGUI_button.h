
#ifndef SGUI_BUTTON_H
#define SGUI_BUTTON_H


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
  unsigned short	textColor;
  unsigned short	textMarginX;
  unsigned short	textMarginY;
  unsigned short	state;
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
                      unsigned short	textColor,
          //const struct fontInfo *fontInfoStruct,
                      unsigned short	textMarginX,
                      unsigned short	textMarginY,
                      unsigned short		state,
                      unsigned short	msDelay,
                      void			(*action)(void));
void	SGUI_buttonChangeText(unsigned short page,
                            unsigned short	buttonId,
                              char	*str,
                          unsigned short	textColor/*,
              const struct fontInfo *fontInfoStruct*/);
void	SGUI_buttonChangeColor(unsigned short page,
                             unsigned short	buttonId,
                             unsigned short	buttonColor);


#endif
