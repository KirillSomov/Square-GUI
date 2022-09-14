
#include "SGUI_page.h"
#include "SGUI_system.h"


extern GUI_t GUI;


static void clearPage(void);
static void drawPage(void);


void clearPage(void)
{
  //LCD_fill(0xBDD7);
}


void drawPage(void)
{
  clearPage();
  
  for(unsigned short label = 0; label < GUI.pages[GUI.currentPage]->objList.ObjLabelNum; label++)
  {
    SGUI_drawLabel(GUI.currentPage, label);
  }
  for(unsigned short btn = 0; btn < GUI.pages[GUI.currentPage]->objList.ObjButtonNum; btn++)
  {
    SGUI_drawButton(GUI.currentPage, btn);
  }
}


void SGUI_setPage(unsigned short page)
{
  GUI.currentPage = page;
  drawPage();
}
