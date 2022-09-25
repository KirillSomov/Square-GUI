
#include "SGUI_picture.h"
#include "SGUI_system.h"
#include "SGUI_page.h"
#include "SGUI_primitives.h"
#include "SGUI_dataTransfer.h"


extern GUI_t GUI;


void	SGUI_drawPicture(unsigned short page, unsigned short	picId)
{
  Object_Picture *pic = &GUI.pages[page]->objList.ObjPictureList[picId];

  SGUI_LCD_drawPicture(pic->picture, GUI.pages[page]->lcdPage,
                       pic->x, pic->y, pic->w, pic->h);

  SGUI_drawFrame(pic->x-pic->frameWidth, pic->y-pic->frameWidth,
                 pic->x+pic->w+pic->frameWidth-1, pic->x+pic->h+pic->frameWidth-1,
                 pic->rx, pic->ry,
                 pic->frameWidth, pic->frameColor);
}


void	SGUI_createPicture(unsigned short page,
                         unsigned char *picture,
                         unsigned short	x, unsigned short	y,
                         unsigned short	w, unsigned short	h,
                         unsigned short	rx, unsigned short ry,
                         unsigned short	frameWidth,
                         unsigned short	frameColor)
{
  Object_Picture *pic = &GUI.pages[page]->objList.ObjPictureList[GUI.pages[page]->objList.ObjPictureNum];
  
  pic->picture = picture;
  pic->x	=	x;
  pic->y	=	y;
  pic->w	=	w;
  pic->h	=	h;
  pic->rx = rx;
  pic->ry = ry;
  pic->frameWidth = frameWidth;
  pic->frameColor = frameColor;
  
  GUI.pages[page]->objList.ObjPictureNum++;
}
