
#include "SGUI_canvas.h"
#include "SGUI_system.h"
#include "SGUI_page.h"
#include "SGUI_primitives.h"


extern GUI_t GUI;


static void calcActiveWindow(Object_Canvas *canvas)
{
  canvas->activeWindow.x0 = canvas->x0 + canvas->frameWidth + canvas->penWeight;
  canvas->activeWindow.y0 = canvas->y0 + canvas->frameWidth + canvas->penWeight;
  canvas->activeWindow.x1 = canvas->x1 - canvas->frameWidth - canvas->penWeight;
  canvas->activeWindow.y1 = canvas->y1 - canvas->frameWidth - canvas->penWeight;
}


void SGUI_drawCanvas(unsigned short page, unsigned short	canvasId)
{
  Object_Canvas *canvas = &GUI.pages[page]->objList.ObjCanvasList[canvasId];
  
  SGUI_drawFilledFrame(canvas->x0, canvas->y0,
                       canvas->x1, canvas->y1,
                       canvas->rx, canvas->ry,
                       canvas->frameWidth, canvas->frameColor, canvas->canvasColor);
}


void SGUI_createCanvas(unsigned short page,
                       unsigned short	x0,	unsigned short	y0,
                       unsigned short	x1,	unsigned short	y1,
                       unsigned short	rx,	unsigned short	ry,
                       unsigned short	frameWidth,
                       unsigned short	canvasColor,
                       unsigned short	frameColor,
                       unsigned short	penWeight,
                       unsigned short	penColor,
                       void (*action)(void))
{
  Object_Canvas *canvas = &GUI.pages[page]->objList.ObjCanvasList[GUI.pages[page]->objList.ObjCanvasNum];

  canvas->x0 = x0;
  canvas->y0 = y0;
  canvas->x1 = x1;
  canvas->y1 = y1;
  canvas->rx = rx;
  canvas->ry = ry;
  canvas->frameWidth = frameWidth;
  canvas->canvasColor = canvasColor;
  canvas->frameColor = frameColor;
  canvas->penWeight = penWeight;
  canvas->penColor = penColor;
  canvas->action = action;
  canvas->active = true;

  calcActiveWindow(canvas);
  
  GUI.pages[page]->objList.ObjCanvasNum++;
}


void SGUI_canvasClear(unsigned short page, unsigned short canvasId)
{
  Object_Canvas *canvas = &GUI.pages[page]->objList.ObjCanvasList[canvasId];
  
  SGUI_drawFilledFrame(canvas->x0 + canvas->frameWidth, canvas->y0 + canvas->frameWidth,
                       canvas->x1 - canvas->frameWidth, canvas->y1 - canvas->frameWidth,
                       canvas->rx, canvas->ry,
                       0, 0, canvas->canvasColor);
}


void SGUI_canvasSetPenColor(unsigned short page,
                            unsigned short canvasId,
                            unsigned short color)
{
  GUI.pages[page]->objList.ObjCanvasList[canvasId].penColor = color;
}

void SGUI_canvasSetPenWeight(unsigned short page,
                             unsigned short canvasId,
                             unsigned short weight)
{
  GUI.pages[page]->objList.ObjCanvasList[canvasId].penWeight = weight;
  calcActiveWindow(&GUI.pages[page]->objList.ObjCanvasList[canvasId]);
}                            


void SGUI_canvasSetPenEraser(unsigned short page, unsigned short	canvasId)
{
  GUI.pages[page]->objList.ObjCanvasList[canvasId].penColor = GUI.pages[page]->objList.ObjCanvasList[canvasId].canvasColor;
}


void SGUI_canvasDrawPoint(unsigned short page, unsigned short	canvasId)
{
  Object_Canvas *canvas = &GUI.pages[page]->objList.ObjCanvasList[canvasId];
  unsigned short x = 0;
  unsigned short y = 0;

  SGUI_getSampleTouch(&x, &y);
  SGUI_LCD_drawFilledCircle(x, y, canvas->penWeight, canvas->penColor);
}


void SGUI_canvasIdle(unsigned short page, unsigned short	canvasId, unsigned short dt)
{
  GUI.pages[page]->objList.ObjCanvasList[canvasId].idle = (signed short)dt;
}


void SGUI_canvasActive(unsigned short page, unsigned short	canvasId, bool active)
{
  GUI.pages[page]->objList.ObjCanvasList[canvasId].active = active;
}


void SGUI_canvasSetFrameColor(unsigned short page,
                              unsigned short canvasId,
                              unsigned short frameColor)
{
  Object_Button *canvas = &GUI.pages[page]->objList.ObjCanvasList[canvasId];
  
  canvas->frameColor = frameColor;
  
  SGUI_drawFrame(canvas->x0, canvas->y0,
                 canvas->x1, canvas->y1,
                 canvas->rx, canvas->ry,
                 canvas->frameWidth, canvas->frameColor);
}
