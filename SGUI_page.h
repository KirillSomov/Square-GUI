
#ifndef SGUI_PAGE_H
#define SGUI_PAGE_H


#include "SGUI_label.h"
#include "SGUI_button.h"


typedef struct
{
  unsigned short	ObjLabelNum;
  unsigned short	ObjButtonNum;
  Object_Label*		ObjLabelList;
  Object_Button*	ObjButtonList;
}Object_List_t;


typedef struct
{
  Object_List_t objList;
  void (*objActionFunc)(void);
}Page_t;


void SGUI_setPage(unsigned short page);


#endif
