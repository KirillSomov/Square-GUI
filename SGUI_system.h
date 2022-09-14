
#ifndef SGUI_SYSTEM_H
#define SGUI_SYSTEM_H


#include "SGUI_page.h"


typedef	struct
{
  unsigned short	x;
  unsigned short	y;
}tPoint_t;


typedef	struct
{
  unsigned short flag_touch;
  tPoint_t touchPoint;
  unsigned short currentPage;
  Page_t **pages;
}GUI_t;


extern GUI_t GUI;


void	SGUI_objectListReset(void);
void	SGUI_getTouchPoint(void);
void	SGUI_objSetHandlerFunc(unsigned short page, void (*objActionFunc)(void));
void	SGUI_objHandler(void);
void	SGUI_Handler(unsigned long dT);


#endif
