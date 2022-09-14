
#include "SGUI_button.h"
#include "SGUI_system.h"
#include "SGUI_page.h"
#include "SGUI_primitives.h"


extern GUI_t GUI;


void	SGUI_drawButton(unsigned short page, unsigned short	buttonId)
{
  Object_Button *btn = &GUI.pages[page]->objList.ObjButtonList[buttonId];
  
   SGUI_drawFilledFrame(btn->x0, btn->y0, btn->x1, btn->y1, btn->frameWidth, btn->frameColor, btn->buttonColor);
  
  /*if(btn->str != 0)
    btn->textLenght = LCD_printString(btn->X0+btn->textMarginX, btn->Y0+btn->textMarginY, btn->str, btn->textColor, btn->fontInfoStruct);
  else
    btn->textLenght = 0;*/
}


void	SGUI_createButton(unsigned short page,
                      unsigned short	x0,	unsigned short	y0,
                      unsigned short	x1,	unsigned short	y1,
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
                      void			(*action)(void))
{
  Object_Button *btn = &GUI.pages[page]->objList.ObjButtonList[GUI.pages[page]->objList.ObjButtonNum];
  
  btn->x0	=	x0;
  btn->y0	=	y0;
  btn->x1	=	x1;
  btn->y1	=	y1;
  btn->frameWidth						=	frameWidth;
  btn->buttonColor						=	buttonColor;
  btn->frameColor					=	frameColor;
  btn->str									=	str;
  btn->textColor						=	textColor;
  //btn->fontInfoStruct			=	fontInfoStruct;
  btn->textMarginX					=	textMarginX;
  btn->textMarginY					=	textMarginY;
  btn->state								=	state;
  btn->msDelay							=	msDelay;
  btn->flag_buttonWasClicked	= 0;
  btn->timerVal 						= 0;
  btn->action							=	action;
  
  GUI.pages[page]->objList.ObjButtonNum++;
}


void	SGUI_buttonChangeText(unsigned short page,
                            unsigned short	buttonId,
                              char	*str,
                          unsigned short	textColor/*,
              const struct fontInfo *fontInfoStruct*/)
{
  Object_Button *btn = &GUI.pages[page]->objList.ObjButtonList[GUI.pages[page]->objList.ObjButtonNum];
  
  btn->str 					  = str;
  btn->textColor			=	textColor;
  /*btn->fontInfoStruct	=	fontInfoStruct;
  
  GUI_drawFilledFrame(btn->X0+btn->textMarginX,
                      btn->textLenght,
                      btn->Y0+btn->textMarginY,
                      btn->Y0+btn->textMarginY+24,
                      0,
                      btn->mainColor,
                      0);
  
  if(str != 0)
    btn->textLenght = LCD_printString(btn->X0+btn->textMarginX,
                                      btn->Y0+btn->textMarginY,
                                      str, textColor, fontInfoStruct);*/
}


void	SGUI_buttonChangeColor(unsigned short page,
                             unsigned short	buttonId,
                             unsigned short	buttonColor)
{
  Object_Button *btn = &GUI.pages[page]->objList.ObjButtonList[GUI.pages[page]->objList.ObjButtonNum];
  
  btn->buttonColor = buttonColor;
  
  SGUI_drawFilledFrame(btn->x0,
                      btn->y0,
                      btn->x1,
                      btn->y1,
                      btn->frameWidth,
                      btn->frameColor,
                      btn->buttonColor);
  
  /*if(btn->str != 0)
    GUI_buttonChangeText(page, buttonNum, btn->str, btn->textColor, btn->fontInfoStruct);*/
}
