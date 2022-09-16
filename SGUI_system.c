
#include "SGUI_system.h"
#include "SGUI_dataTransfer.h"


static void SGUI_touchHandler(void)
{
  GUI.flag_touch = SGUI_sampleTouch(&GUI.touchPoint.x, &GUI.touchPoint.y);
}


static void SGUI_pageHandler(void)
{
  if(GUI.pages[GUI.currentPage]->pageActionFunc != 0)
  {
    GUI.pages[GUI.currentPage]->pageActionFunc();
  }
}


static void SGUI_buttonHandler(void)
{
  unsigned short page = GUI.currentPage;
  Object_Button *button = &GUI.pages[page]->objList.ObjButtonList[0];
  unsigned short objButAmount = GUI.pages[page]->objList.ObjButtonNum;
  
  if(GUI.flag_touch)
  {
    GUI.flag_touch = 0;
    for(unsigned short objButNum = 0; objButNum < objButAmount; objButNum++)
    {
      if(button[objButNum].action != 0)
      {
        if((GUI.touchPoint.x < button[objButNum].x0) || (GUI.touchPoint.x > button[objButNum].x1))
          continue;
        else if((GUI.touchPoint.y < button[objButNum].y0) || (GUI.touchPoint.y > button[objButNum].y1))
          continue;
        else
        {
          if(button[objButNum].flag_buttonWasClicked == 0)
          {
            button[objButNum].action();
            button[objButNum].flag_buttonWasClicked = 1;
          }
          return;
        }
      }
    }
  }
}


void	SGUI_objectListReset(void)
{
  /*GUI.objList.ObjLabelNum 		= 0;
  GUI.objList.ObjButtonNum 		= 0;
  GUI.objList.ObjCanvasNum		= 0;*/
}


void SGUI_handler(void)
{		
  SGUI_pageHandler();
  SGUI_buttonHandler();
  
  #ifdef OBJ_CANVAS_EN
    if(GUI.flag_touch)
    {
      for(unsigned short objCanvasNum = 0; objCanvasNum < OBJ_CANVAS_AMOUNT; objCanvasNum++)
      {
        if((GUI.touchPoint.X < GUI.objList.ObjCanvasList[objCanvasNum].X0) || (GUI.touchPoint.X > GUI.objList.ObjCanvasList[objCanvasNum].X1))
          continue;
        else if((GUI.touchPoint.Y < GUI.objList.ObjCanvasList[objCanvasNum].Y0) || (GUI.touchPoint.Y > GUI.objList.ObjCanvasList[objCanvasNum].Y1))
          continue;
        else
        {
          GUI_drawPoint(GUI.objList.ObjCanvasList[objCanvasNum].penWeight, GUI.objList.ObjCanvasList[objCanvasNum].penColor);
          
          if(GUI.objList.ObjCanvasList[objCanvasNum].action != 0)
            GUI.objList.ObjCanvasList[objCanvasNum].action();
          GUI.flag_touch				=	0;
          return;
        }
      }
    }
  #endif
}


void SGUI_sync(unsigned short dt)
{
  for(unsigned short objButNum = 0; objButNum < GUI.pages[GUI.currentPage]->objList.ObjButtonNum; objButNum++)
  {
    if(GUI.pages[GUI.currentPage]->objList.ObjButtonList[objButNum].flag_buttonWasClicked == 1)
    {
      GUI.pages[GUI.currentPage]->objList.ObjButtonList[objButNum].timerVal += dt;
      if(GUI.pages[GUI.currentPage]->objList.ObjButtonList[objButNum].timerVal > GUI.pages[GUI.currentPage]->objList.ObjButtonList[objButNum].msDelay)
      {
        GUI.pages[GUI.currentPage]->objList.ObjButtonList[objButNum].timerVal = 0;
        GUI.pages[GUI.currentPage]->objList.ObjButtonList[objButNum].flag_buttonWasClicked = 0;
      }
    }
  }

  SGUI_touchHandler();
}
