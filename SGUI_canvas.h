
#ifndef SGUI_CANVAS_H
#define SGUI_CANVAS_H


typedef enum
{
  Pen_fine = 1,
  Pen_small = 2,
  Pen_medium = 4,
  Pen_broad = 8,
  Pen_extraBroad = 16
}Pen_Weight;


typedef struct
{
  unsigned short	x0;
  unsigned short	y0;
  unsigned short	x1;
  unsigned short	y1;
}CanvasActiveWindow_t;


typedef struct
{
  unsigned short	x0;
  unsigned short	y0;
  unsigned short	x1;
  unsigned short	y1;
  unsigned short	rx;
  unsigned short	ry;  
  unsigned short	frameWidth;
  unsigned short	canvasColor;
  unsigned short	frameColor;
  unsigned short	penColor;
  Pen_Weight	penWeight;
  CanvasActiveWindow_t activeWindow;

  void (*action)(void);
}Object_Canvas;
 
 
void SGUI_drawCanvas(unsigned short page, unsigned short	canvasId);
void SGUI_createCanvas(unsigned short page,
                       unsigned short	x0,	unsigned short	y0,
                       unsigned short	x1,	unsigned short	y1,
                       unsigned short	rx,	unsigned short	ry,
                       unsigned short	frameWidth,
                       unsigned short	canvasColor,
                       unsigned short	frameColor,
                       unsigned short	penWeight,
                       unsigned short	penColor,
                       void (*action)(void));
void SGUI_canvasClear(unsigned short page, unsigned short canvasId);
void SGUI_canvasChangePenColor(unsigned short page,
                               unsigned short canvasId,
                               unsigned short color);
void SGUI_canvasSetPenEraser(unsigned short page, unsigned short	canvasId);
void SGUI_canvasDrawPoint(unsigned short page, unsigned short	canvasId);


#endif
