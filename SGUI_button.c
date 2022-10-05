
#include "SGUI_button.h"
#include "SGUI_system.h"
#include "SGUI_page.h"
#include "SGUI_primitives.h"


extern GUI_t GUI;


static void textPositioning(Object_Button *btn)
{
  unsigned short maxStrLen = 0;
  unsigned short textHeight = 0;

  for(unsigned short i = 0; btn->str[i] != '\0'; i++)
  {
    maxStrLen++;
    if((btn->str[i] == '\n') || (btn->str[i+1] == '\0'))
    {
      textHeight++;
      if(maxStrLen > btn->textLenght)
      {
        btn->textLenght = maxStrLen;
        maxStrLen = 0;
      }
    }
  }

  btn->textMarginX = (unsigned short)(((btn->x1 - btn->x0 - btn->frameWidth*2) - btn->textLenght*btn->fontSize/2) / 2);
  btn->textMarginY = (unsigned short)(((btn->y1 - btn->y0 - btn->frameWidth*2) - textHeight*btn->fontSize) / 2);
}

static void clearText(Object_Button *btn)
{
  SGUI_drawFilledFrame(btn->x0+btn->textMarginX, btn->y0+btn->textMarginY,
                       btn->x0+btn->textMarginX+(btn->textLenght)*(btn->fontSize)/2,
                       btn->y0+btn->textMarginY+btn->fontSize,
                       0, 0,
                       0, 0, btn->buttonColor);
}


void SGUI_drawButton(unsigned short page, unsigned short	buttonId)
{
  Object_Button *btn = &GUI.pages[page]->objList.ObjButtonList[buttonId];

  if(btn->visibility)
  {
    SGUI_drawFilledFrame(btn->x0, btn->y0,
                         btn->x1, btn->y1,
                         btn->rx, btn->ry,
                         btn->frameWidth, btn->frameColor, btn->buttonColor);

    if(btn->textLenght != 0)
    {
      SGUI_printString(btn->str,
                       btn->x0+btn->textMarginX, btn->y0+btn->textMarginY,
                       btn->fontSize,
                       btn->buttonColor, btn->fontColor);
    }
  }
}


void SGUI_createButton(unsigned short page,
                       unsigned short	x0,	unsigned short	y0,
                       unsigned short	x1,	unsigned short	y1,
                       unsigned short	rx, unsigned short	ry,
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
                       void			(*action)(void))
{
  Object_Button *btn = &GUI.pages[page]->objList.ObjButtonList[GUI.pages[page]->objList.ObjButtonNum];
  
  btn->x0	=	x0;
  btn->y0	=	y0;
  btn->x1	=	x1;
  btn->y1	=	y1;
  btn->rx = rx;
  btn->ry = ry;
  btn->frameWidth = frameWidth;
  btn->buttonColor = buttonColor;
  btn->frameColor = frameColor;
  btn->str = str;
  //btn->fontInfoStruct = fontInfoStruct;
  btn->fontSize = fontSize;
  btn->fontColor = fontColor;
  btn->textMarginX = textMarginX;
  btn->textMarginY = textMarginY;
  btn->inUsage = inUsage;
  btn->msDelay = msDelay;
  btn->flag_buttonWasClicked = 0;
  btn->timerVal = 0;
  btn->action = action;

  textPositioning(btn);
  
  GUI.pages[page]->objList.ObjButtonNum++;
}


void SGUI_buttonSetText(unsigned short page,
                        unsigned short buttonId,
                        char *str,
                        unsigned short	fontSize,
                        unsigned short fontColor/*,
            const struct fontInfo *fontInfoStruct*/)
{
  Object_Button *btn = &GUI.pages[page]->objList.ObjButtonList[buttonId];
  
  btn->str = str;
  btn->fontSize = fontSize;
  btn->fontColor = fontColor;
  textPositioning(btn);
  //btn->fontInfoStruct	=	fontInfoStruct;
  SGUI_drawButton(page, buttonId);
}


void SGUI_buttonSetColor(unsigned short page,
                         unsigned short buttonId,
                         unsigned short buttonColor)
{
  Object_Button *btn = &GUI.pages[page]->objList.ObjButtonList[buttonId];
  
  btn->buttonColor = buttonColor;
  
  SGUI_drawFilledFrame(btn->x0, btn->y0,
                       btn->x1, btn->y1,
                       btn->rx, btn->ry,
                       btn->frameWidth, btn->frameColor, btn->buttonColor);                       
  
  if(btn->textLenght != 0)
  {
    SGUI_printString(btn->str,
                     btn->x0+btn->textMarginX, btn->y0+btn->textMarginY,
                     btn->fontSize,
                     btn->buttonColor, btn->fontColor);
  }
}


void SGUI_buttonSetFrameColor(unsigned short page,
                              unsigned short buttonId,
                              unsigned short frameColor)
{
  Object_Button *btn = &GUI.pages[page]->objList.ObjButtonList[buttonId];
  
  btn->frameColor = frameColor;
  
  SGUI_drawFrame(btn->x0, btn->y0,
                 btn->x1, btn->y1,
                 btn->rx, btn->ry,
                 btn->frameWidth, btn->frameColor);
}


void SGUI_buttonInUsage(unsigned short page,
                        unsigned short buttonId,
                        bool inUsage)
{
  GUI.pages[page]->objList.ObjButtonList[buttonId].inUsage = inUsage;
}


void SGUI_buttonVisibility(unsigned short page,
                           unsigned short buttonId,
                           bool visibility)
{
  Object_Button *btn = &GUI.pages[page]->objList.ObjButtonList[buttonId];
  btn->visibility = visibility;
  if(visibility)
  {
    SGUI_drawButton(page, buttonId);  
  }
  else
  {
    SGUI_drawFilledFrame(btn->x0, btn->y0,
                         btn->x1, btn->y1,
                         btn->rx, btn->ry,
                         btn->frameWidth, 0xFFFF, 0xFFFF);    
  }
}                          
