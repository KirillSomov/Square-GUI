
#include "SGUI_label.h"
#include "SGUI_system.h"
#include "SGUI_page.h"
#include "SGUI_primitives.h"


extern GUI_t GUI;


void	SGUI_drawLabel(unsigned short page, unsigned short	labelId)
{
  Object_Label *label = &GUI.pages[page]->objList.ObjLabelList[labelId];  
  
  SGUI_drawFilledFrame(label->x0, label->y0, label->x1, label->y1, label->frameWidth, label->frameColor, label->labelColor);
  
  /*if(label->str != 0)
    label->textLenght = LCD_printString(label->X0+label->textMarginX, label->Y0+label->textMarginY, label->str, label->textColor, label->fontInfoStruct);
  else
    label->textLenght = 0;*/
}


void	SGUI_createLabel(unsigned short page,
                      unsigned short	x0,	unsigned short	y0,
                      unsigned short	x1,	unsigned short	y1,
                      unsigned short	frameWidth,
                      unsigned short	labelColor,
                      unsigned short	frameColor,
                      char			*str,
                      unsigned short	textColor,
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
  label->frameWidth					=	frameWidth;
  label->labelColor				=	labelColor;
  label->frameColor			=	frameColor;
  label->str							=	str;
  label->textColor				=	textColor;
  //label->fontInfoStruct	=	fontInfoStruct;
  label->textMarginX			=	textMarginX;
  label->textMarginY			=	textMarginY;
  label->action					=	action;
  
  GUI.pages[page]->objList.ObjLabelNum++;
}


void	SGUI_labelChangeText(unsigned short page,
                          unsigned short	labelId,
                            char	*str,
                        unsigned short	textColor/*,
            const struct fontInfo *fontInfoStruct*/)
{
  Object_Label *label = &GUI.pages[page]->objList.ObjLabelList[GUI.pages[page]->objList.ObjLabelNum];
  
  label->str 						= str;
  label->textColor			=	textColor;
  //label->fontInfoStruct	=	fontInfoStruct;
  
  /*PixelMap_t pixelMap;
  pixelMap.W = 100;
  pixelMap.H = 25;
  static unsigned short colors[25 * 100];
  pixelMap.colors = colors;
  
  PixelMap_drawFilledFrame(&pixelMap,
                      0,
                      pixelMap.W - 1,
                      0,
                      pixelMap.H - 1,
                      0,
                      label->mainColor,
                      0);
  
  unsigned short prev_textLength = label->textLenght;
  if(str != 0)
  {
    label->textLenght = PixelMap_printString(&pixelMap, 0, 0, str, textColor, fontInfoStruct);
    label->textLenght += label->X0
                       + label->textMarginX;
  }
  
  LCD_drawPixelMap(&pixelMap,
                   label->X0+label->textMarginX,
                  (label->textLenght > prev_textLength) ? label->textLenght : prev_textLength,
                   label->Y0+label->textMarginY,
                   label->Y0+label->textMarginY+24);*/
  
//	GUI_drawFilledFrame(GUI.objList.ObjLabelList[labelNum].X0+GUI.objList.ObjLabelList[labelNum].textMarginX,
//											GUI.objList.ObjLabelList[labelNum].textLenght,
//											GUI.objList.ObjLabelList[labelNum].Y0+GUI.objList.ObjLabelList[labelNum].textMarginY,
//											GUI.objList.ObjLabelList[labelNum].Y0+GUI.objList.ObjLabelList[labelNum].textMarginY+24,
//											0,
//											GUI.objList.ObjLabelList[labelNum].mainColor,
//											0);	
  
//	if(str != 0)
//		GUI.objList.ObjLabelList[labelNum].textLenght = LCD_printString(GUI.objList.ObjLabelList[labelNum].X0+GUI.objList.ObjLabelList[labelNum].textMarginX,
//																																GUI.objList.ObjLabelList[labelNum].Y0+GUI.objList.ObjLabelList[labelNum].textMarginY,
//																																str, textColor, fontInfoStruct);
}


void	SGUI_labelChangeColor(unsigned short page,
                            unsigned short	labelId,
                            unsigned short	labelColor)
{
  Object_Label *label = &GUI.pages[page]->objList.ObjLabelList[GUI.pages[page]->objList.ObjLabelNum];
  
  label->labelColor = labelColor;
  
  SGUI_drawFilledFrame(label->x0,
                      label->y0,
                      label->x1,
                      label->y1,
                      label->frameWidth,
                      label->frameColor,
                      label->labelColor);
  
  /*if(label->str != 0)
    GUI_labelChangeText(page, labelNum, label->str,
                        label->textColor,
                        label->fontInfoStruct);*/
}
