
#ifndef SGUI_PAGE_H
#define SGUI_PAGE_H


#include "SGUI_label.h"
#include "SGUI_button.h"
#include "SGUI_picture.h"


typedef struct
{
  unsigned short	ObjLabelNum;
  unsigned short	ObjButtonNum;
  unsigned short	ObjPictureNum;
  Object_Label*		ObjLabelList;
  Object_Button*	ObjButtonList;
  Object_Picture*	ObjPictureList;
}Object_List_t;


typedef struct
{
  unsigned long lcdPage;
  Object_List_t objList;
  void (*pageActionFunc)(void);
}Page_t;


void SGUI_LinkPageToLcd(unsigned short guiPage, unsigned long lcdPage);
void SGUI_setPage(unsigned short page);
void SGUI_drawPage(unsigned short page);
void SGUI_showPage(unsigned short page);
void SGUI_clearPage(unsigned short color);
void SGUI_pageSetActionFunc(unsigned short page, void (*pageActionFunc)(void));


#endif
