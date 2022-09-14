
#ifndef SGUI_CANVAS_H
#define SGUI_CANVAS_H

#ifdef USE_CANVAS

#include "stm32f4xx.h"


// ������� ����
typedef enum
{
  Pen_fine	=	0,
  Pen_small,
  Pen_medium,
  Pen_broad,
  Pen_extraBroad
}Pen_Weight;
 

// ��������� ������� �����
typedef struct
{
  uint16_t		X0;						// ���������� ������
  uint16_t		X1;
  uint16_t		Y0;
  uint16_t		Y1;
  uint16_t		border;				// ������ ������
  uint16_t		mainColor;		// ���� ������
  uint16_t		borderColor;	// ���� ������
  uint16_t		penColor;			// ���� ����
  Pen_Weight	penWeight;		// ������� ����
  
  // �������� �� ������� �� ���� ������
  void (*action)(void);
}Object_Canvas;
 
 
void	GUI_createCanvas(uint8_t page,
                      uint16_t		X0,	uint16_t	X1,			// X-���������� ������	// ������� �����
                      uint16_t		Y0,	uint16_t	Y1,			// Y-���������� ������
                      uint16_t		border,								// ������ ������
                      uint16_t		mainColor,						// �������� ���� ������
                      uint16_t		borderColor,					// ���� ������
                      Pen_Weight	penWeight,						// ������� ����
                      uint16_t		penColor,							// ���� ����
                      void				(*action)(void));			// ������� ���������� � ������
void	GUI_canvasClear(uint8_t page, uint8_t canvasNum);								// �������� �����
void	GUI_canvasChangePenColor(uint8_t page,
                                uint8_t	canvasNum,
                              uint16_t	newPenColor);		// ������� ���� ���� ������
void	GUI_canvasSetPenEraser(uint8_t page, uint8_t	canvasNum);				//
void	GUI_canvasDrawPoint(uint8_t page,
                            Pen_Weight	penWeight,
                            uint16_t	pointColor);			// ��������� ����� �� ������

#endif

#endif
