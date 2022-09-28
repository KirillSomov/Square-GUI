
#include "SGUI_label.h"
#include "SGUI_system.h"
#include "SGUI_page.h"
#include "SGUI_primitives.h"
#include "SGUI_string.h"
#include "string.h"


extern GUI_t GUI;


static void textPositioning(Object_Label *label)
{
  label->textLenght = strlen(label->str);
}

static void clearText(Object_Label *label)
{
  SGUI_drawFilledFrame(label->x0+label->textMarginX, label->y0+label->textMarginY,
                       label->x0+label->textMarginX+(label->textLenght)*(label->fontSize)/2,
                       label->y0+label->textMarginY+label->fontSize,
                       0, 0,
                       0, 0, label->labelColor);
}


void	SGUI_drawLabel(unsigned short page, unsigned short	labelId)
{
  Object_Label *label = &GUI.pages[page]->objList.ObjLabelList[labelId];
  
  SGUI_drawFilledFrame(label->x0, label->y0,
                       label->x1, label->y1,
                       label->rx, label->ry,
                       label->frameWidth, label->frameColor, label->labelColor);
  
  if(label->textLenght != 0)
  {
    SGUI_printString(label->str,
                     label->x0+label->textMarginX, label->y0+label->textMarginY,
                     label->fontSize,
                     label->labelColor, label->fontColor);
  }
}


void	SGUI_createLabel(unsigned short page,
                      unsigned short	x0,	unsigned short	y0,
                      unsigned short	x1,	unsigned short	y1,
                      unsigned short	rx, unsigned short	ry,
                      unsigned short	frameWidth,
                      unsigned short	labelColor,
                      unsigned short	frameColor,
                      char			*str,
                      unsigned short	fontSize,
                      unsigned short	fontColor,
          //const struct fontInfo *fontInfoStruct,
                      unsigned short	textMarginX,
                      unsigned short	textMarginY,
                      void			(*action)(void))
{
  Object_Label *label = &GUI.pages[page]->objList.ObjLabelList[GUI.pages[page]->objList.ObjLabelNum];
  
  label->x0	=	x0;
  label->y0	=	y0;
  label->x1	=	x1;
  label->y1	=	y1;
  label->rx = rx;
  label->ry = ry;
  label->frameWidth = frameWidth;
  label->labelColor = labelColor;
  label->frameColor = frameColor;
  label->str = str;
  label->fontSize = fontSize;
  label->fontColor = fontColor;
  //label->fontInfoStruct	=	fontInfoStruct;
  label->textMarginX = textMarginX;
  label->textMarginY = textMarginY;
  label->action = action;

  textPositioning(label);
  
  GUI.pages[page]->objList.ObjLabelNum++;
}


void SGUI_labelSetText(unsigned short page,
                       unsigned short labelId,
                       char *str,
                       unsigned short	fontSize,
                       unsigned short fontColor/*,
            const struct fontInfo *fontInfoStruct*/)
{
  Object_Label *label = &GUI.pages[page]->objList.ObjLabelList[labelId];
  
  clearText(label);
  label->str = str;
  label->fontSize = fontSize;
  label->fontColor = fontColor;
  //label->fontInfoStruct	=	fontInfoStruct;
  textPositioning(label);
  if(label->textLenght != 0)
  {
    SGUI_printString(label->str,
                     label->x0+label->textMarginX, label->y0+label->textMarginY,
                     label->fontSize,
                     label->labelColor, label->fontColor);
  }
}


void	SGUI_labelChangeColor(unsigned short page,
                            unsigned short	labelId,
                            unsigned short	labelColor)
{
  Object_Label *label = &GUI.pages[page]->objList.ObjLabelList[labelId];
  
  label->labelColor = labelColor;
  
  SGUI_drawFilledFrame(label->x0, label->y0,
                       label->x1, label->y1,
                       label->rx, label->ry,
                       label->frameWidth, label->frameColor, label->labelColor);
  
  /*if(label->str != 0)
    GUI_labelChangeText(page, labelNum, label->str,
                        label->textColor,
                        label->fontInfoStruct);*/
}
