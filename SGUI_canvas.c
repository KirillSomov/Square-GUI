
#include "SGUI_canvas.h"


#ifdef USE_CANVAS


// ������� �����
void	GUI_createCanvas(uint16_t		X0,	uint16_t	X1,			// X-���������� ������
                      uint16_t		Y0,	uint16_t	Y1,			// Y-���������� ������
                      uint16_t		border,								// ������ ������
                      uint16_t		mainColor,						// �������� ���� ������
                      uint16_t		borderColor,					// ���� ������
                      Pen_Weight	penWeight,						// ������� ����
                      uint16_t		penColor,							// ���� ����
                      void				(*action)(void))			// ������� ���������� � ������
{
  GUI.objList.ObjCanvasList[GUI.objList.ObjCanvasNum].X0	=	X0;
  GUI.objList.ObjCanvasList[GUI.objList.ObjCanvasNum].X1	=	X1;
  GUI.objList.ObjCanvasList[GUI.objList.ObjCanvasNum].Y0	=	Y0;
  GUI.objList.ObjCanvasList[GUI.objList.ObjCanvasNum].Y1	=	Y1;
  GUI.objList.ObjCanvasList[GUI.objList.ObjCanvasNum].border			=	border;
  GUI.objList.ObjCanvasList[GUI.objList.ObjCanvasNum].mainColor		=	mainColor;
  GUI.objList.ObjCanvasList[GUI.objList.ObjCanvasNum].borderColor	=	borderColor;
  GUI.objList.ObjCanvasList[GUI.objList.ObjCanvasNum].penWeight		=	penWeight;
  GUI.objList.ObjCanvasList[GUI.objList.ObjCanvasNum].penColor		=	penColor;
  GUI.objList.ObjCanvasList[GUI.objList.ObjCanvasNum].action			=	action;
  
  GUI_drawFilledFrame(X0, X1, Y0, Y1, border, mainColor, borderColor);		// ��������� ������
  
  GUI.objList.ObjCanvasNum++;
}

// �������� �����
void	GUI_canvasClear(uint8_t canvasNum)
{
  LCD_drawFilledRectangle(GUI.objList.ObjCanvasList[canvasNum].X0+GUI.objList.ObjCanvasList[canvasNum].border,
                          GUI.objList.ObjCanvasList[canvasNum].X1-GUI.objList.ObjCanvasList[canvasNum].border,
                          GUI.objList.ObjCanvasList[canvasNum].Y0+GUI.objList.ObjCanvasList[canvasNum].border,
                          GUI.objList.ObjCanvasList[canvasNum].Y1-GUI.objList.ObjCanvasList[canvasNum].border,
                          0xFFFF);
}

// ������� ���� ���� ������
void	GUI_canvasChangePenColor(uint8_t canvasNum, uint16_t newPenColor)
{
  GUI.objList.ObjCanvasList[canvasNum].penColor	=	newPenColor;
}

// 
void	GUI_canvasSetPenEraser(uint8_t canvasNum)
{
  GUI.objList.ObjCanvasList[canvasNum].penColor	=	0xFFFF;
}

// ��������� ����� �� ������
void	GUI_drawPoint(Pen_Weight penWeight, uint16_t pointColor)
{
  // ��������� �����
  switch(penWeight)
  {
    case Pen_fine:
      LCD_drawPixel(GUI.touchPoint.X, GUI.touchPoint.Y, pointColor);
      break;
    case Pen_small:
      LCD_drawFilledRectangle(GUI.touchPoint.X-1, GUI.touchPoint.X+1, GUI.touchPoint.Y-1, GUI.touchPoint.Y+1, pointColor);
      break;
    case Pen_medium:
      LCD_drawFilledRectangle(GUI.touchPoint.X-2, GUI.touchPoint.X-2, GUI.touchPoint.Y-1, GUI.touchPoint.Y+1, pointColor);
      LCD_drawFilledRectangle(GUI.touchPoint.X-1, GUI.touchPoint.X+1, GUI.touchPoint.Y-2, GUI.touchPoint.Y+2, pointColor);
      LCD_drawFilledRectangle(GUI.touchPoint.X+2, GUI.touchPoint.X+1, GUI.touchPoint.Y-2, GUI.touchPoint.Y-2, pointColor);
      break;
    case Pen_broad:
      LCD_drawFilledRectangle(GUI.touchPoint.X-3, GUI.touchPoint.X-3, GUI.touchPoint.Y-1, GUI.touchPoint.Y+1, pointColor);
      LCD_drawFilledRectangle(GUI.touchPoint.X-2, GUI.touchPoint.X-2, GUI.touchPoint.Y-2, GUI.touchPoint.Y+2, pointColor);
      LCD_drawFilledRectangle(GUI.touchPoint.X-1, GUI.touchPoint.X+1, GUI.touchPoint.Y-3, GUI.touchPoint.Y+3, pointColor);
      LCD_drawFilledRectangle(GUI.touchPoint.X+2, GUI.touchPoint.X+2, GUI.touchPoint.Y-2, GUI.touchPoint.Y+2, pointColor);
      LCD_drawFilledRectangle(GUI.touchPoint.X+3, GUI.touchPoint.X+3, GUI.touchPoint.Y-1, GUI.touchPoint.Y+1, pointColor);
      break;
    case Pen_extraBroad:
      LCD_drawFilledRectangle(GUI.touchPoint.X-6, GUI.touchPoint.X-6, GUI.touchPoint.Y-2, GUI.touchPoint.Y+2, pointColor);
      LCD_drawFilledRectangle(GUI.touchPoint.X-5, GUI.touchPoint.X-5, GUI.touchPoint.Y-4, GUI.touchPoint.Y+4, pointColor);
      LCD_drawFilledRectangle(GUI.touchPoint.X-4, GUI.touchPoint.X-3, GUI.touchPoint.Y-5, GUI.touchPoint.Y+5, pointColor);
      LCD_drawFilledRectangle(GUI.touchPoint.X-2, GUI.touchPoint.X+2, GUI.touchPoint.Y-6, GUI.touchPoint.Y+6, pointColor);
      LCD_drawFilledRectangle(GUI.touchPoint.X+3, GUI.touchPoint.X+4, GUI.touchPoint.Y-5, GUI.touchPoint.Y+5, pointColor);
      LCD_drawFilledRectangle(GUI.touchPoint.X+5, GUI.touchPoint.X+5, GUI.touchPoint.Y-4, GUI.touchPoint.Y+4, pointColor);
      LCD_drawFilledRectangle(GUI.touchPoint.X+6, GUI.touchPoint.X+6, GUI.touchPoint.Y-2, GUI.touchPoint.Y+2, pointColor);
      break;
  }		
}

#endif
