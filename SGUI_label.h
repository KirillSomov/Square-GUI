
#ifndef SGUI_LABEL_H
#define SGUI_LABEL_H


typedef struct
{
  unsigned short	x0;
  unsigned short	y0;
  unsigned short	x1;
  unsigned short	y1;
  unsigned short	rx;
  unsigned short	ry;
  unsigned short	frameWidth;
  unsigned short	labelColor;
  unsigned short	frameColor;
  char *str;
  unsigned short	fontSize;
  //const struct fontInfo *fontInfoStruct;
  unsigned short	fontColor;
  unsigned short	textMarginX;
  unsigned short	textMarginY;
  void 			(*action)(void);
  
  unsigned short	textLenght;
}Object_Label;


void	SGUI_drawLabel(unsigned short page, unsigned short	labelId);
void	SGUI_createLabel(unsigned short page,
                      unsigned short	x0,	unsigned short	y0,
                      unsigned short	x1,	unsigned short	y1,
                      unsigned short	rx, unsigned short	ry,
                      unsigned short	frameWidth,
                      unsigned short	labelColor,
                      unsigned short	frameColor,
                      char			*str,
                      unsigned short	fontSize,
                      unsigned short	textColor,
          //const struct fontInfo *fontInfoStruct,
                      unsigned short	textMarginX,
                      unsigned short	textMarginY,
                      void			(*action)(void));
void SGUI_labelSetText(unsigned short page,
                       unsigned short labelId,
                       char *str,
                       unsigned short	fontSize,
                       unsigned short fontColor/*,
            const struct fontInfo *fontInfoStruct*/);
void	SGUI_labelChangeColor(unsigned short page,
                            unsigned short	labelId,
                            unsigned short	labelColor);


#endif
