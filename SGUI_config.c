
#include "SGUI_config.h"
#include "SGUI_system.h"
#include "SGUI_page.h"
#include "SGUI_label.h"
#include "SGUI_button.h"


SGUI_pageStorageCreate(0, 2, 2);

SGUI_pagesStorageCreate(1);

SGUI_guiStorageCreate();


void GUI_pagesStorageInit(void)
{
  GUI.pages[0] = &page_0;
}
