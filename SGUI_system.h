
#ifndef SGUI_SYSTEM_H
#define SGUI_SYSTEM_H


#include "SGUI_page.h"
#include "stdbool.h"


typedef	struct
{
  unsigned short	x;
  unsigned short	y;
}TouchPoint_t;


typedef	struct
{
  signed short idle;
  unsigned short flag_touch;
  TouchPoint_t touchPoint;
  unsigned short currentPage;
  Page_t **pages;
}GUI_t;


extern GUI_t GUI;


void SGUI_objectListReset(void);
void SGUI_idle(unsigned short dt);
bool SGUI_getSampleTouch(unsigned short* x, unsigned short* y);
void SGUI_handler(void);
void SGUI_sync(unsigned short dt);


#endif
