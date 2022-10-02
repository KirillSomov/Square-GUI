
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
    for(unsigned short objButNum = 0; objButNum < objButAmount; objButNum++)
    {
      if((button[objButNum].action != 0) && (button[objButNum].inUsage))
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
          GUI.flag_touch = 0;
          return;
        }
      }
    }
  }
}

static void SGUI_buttonSync(unsigned short dt)
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
}


/*static void SGUI_pictureHandler(void)
{
  unsigned short page = GUI.currentPage;
  Object_Picture *pic = &GUI.pages[page]->objList.ObjPictureList[0];
  unsigned short objPicAmount = GUI.pages[page]->objList.ObjPictureNum;
  
  if(GUI.flag_touch)
  {
    GUI.flag_touch = 0;
    for(unsigned short objPicNum = 0; objPicNum < objPicAmount; objPicNum++)
    {
      if(pic[objPicNum].action != 0)
      {
        if((GUI.touchPoint.x < pic[objPicNum].x) || (GUI.touchPoint.x > (pic[objPicNum].x+pic[objPicNum].w)))
          continue;
        else if((GUI.touchPoint.y < pic[objPicNum].y) || (GUI.touchPoint.y > (pic[objPicNum].y+pic[objPicNum].h)))
          continue;
        else
        {
          if(pic[objPicNum].flag_picWasClicked == 0)
          {
            pic[objPicNum].action();
            pic[objPicNum].flag_picWasClicked = 1;
          }
          return;
        }
      }
    }
  }
}*/


static void SGUI_canvasHandler(void)
{
  unsigned short page = GUI.currentPage;
  Object_Canvas *canvas = &GUI.pages[page]->objList.ObjCanvasList[0];
  unsigned short objCanvasAmount = GUI.pages[page]->objList.ObjCanvasNum;
  
  if(GUI.flag_touch)
  {
    for(unsigned short ObjCanvasId = 0; ObjCanvasId < objCanvasAmount; ObjCanvasId++)
    {
      if((GUI.touchPoint.x < canvas[ObjCanvasId].activeWindow.x0) || (GUI.touchPoint.x > canvas[ObjCanvasId].activeWindow.x1))
        continue;
      else if((GUI.touchPoint.y < canvas[ObjCanvasId].activeWindow.y0) || (GUI.touchPoint.y > canvas[ObjCanvasId].activeWindow.y1))
        continue;
      else
      {
        if(canvas[ObjCanvasId].idle == 0)
        {
          if(canvas[ObjCanvasId].action != 0)
          {
            canvas[ObjCanvasId].action();
          }
          else
          {
            SGUI_canvasDrawPoint(page, ObjCanvasId);
          }
        }
        GUI.flag_touch = 0;
        return;
      }
    }
  }
}

static void SGUI_canvasSync(unsigned short dt)
{
  for(unsigned short objCanvasId = 0; objCanvasId < GUI.pages[GUI.currentPage]->objList.ObjCanvasNum; objCanvasId++)
  {
    if(GUI.pages[GUI.currentPage]->objList.ObjCanvasList[objCanvasId].idle > 0)
    {
      GUI.pages[GUI.currentPage]->objList.ObjCanvasList[objCanvasId].idle -= (signed short)dt;
      if(GUI.pages[GUI.currentPage]->objList.ObjCanvasList[objCanvasId].idle <= 0)
      {
        GUI.pages[GUI.currentPage]->objList.ObjCanvasList[objCanvasId].idle = 0;
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


void	SGUI_idle(unsigned short dt)
{
  GUI.idle = (signed short)dt;
}


bool SGUI_getSampleTouch(unsigned short* x, unsigned short* y)
{
  *x = GUI.touchPoint.x;
  *y = GUI.touchPoint.y;
  return GUI.flag_touch;
}


void SGUI_handler(void)
{		
  SGUI_pageHandler();
  SGUI_buttonHandler();
  SGUI_canvasHandler();
}


void SGUI_sync(unsigned short dt)
{
  if(GUI.idle > 0)
  {
    GUI.idle -= (signed short)dt;
    if(GUI.idle <= 0)
    {
      GUI.idle = 0;
      SGUI_touchHandler();
    }
  }

  SGUI_buttonSync(dt);
  SGUI_canvasSync(dt);

  if(GUI.idle == 0)
  {
    SGUI_touchHandler();
  }
}
