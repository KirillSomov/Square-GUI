
#include "SGUI_page.h"
#include "SGUI_system.h"
#include "SGUI_dataTransfer.h"


extern GUI_t GUI;


void SGUI_LinkPageToLcd(unsigned short guiPage, unsigned long lcdPage)
{
  GUI.pages[guiPage]->lcdPage = lcdPage;
}


void SGUI_setPage(unsigned short page)
{
  SGUI_setLcdPage(GUI.pages[page]->lcdPage);
}


void SGUI_drawPage(unsigned short page)
{  
  for(unsigned short label = 0; label < GUI.pages[page]->objList.ObjLabelNum; label++)
  {
    SGUI_drawLabel(page, label);
  }
  for(unsigned short btn = 0; btn < GUI.pages[page]->objList.ObjButtonNum; btn++)
  {
    SGUI_drawButton(page, btn);
  }
}


void SGUI_showPage(unsigned short page)
{
  GUI.currentPage = page;
  //drawPage();
  SGUI_showLcdPage(GUI.pages[page]->lcdPage);
}


void SGUI_clearPage(unsigned short color)
{
  SGUI_drawFilledSquare(0, 0, 1023, 599, color);
}


void	SGUI_pageSetActionFunc(unsigned short page, void (*pageActionFunc)(void))
{
  GUI.pages[page]->pageActionFunc = pageActionFunc;
}
