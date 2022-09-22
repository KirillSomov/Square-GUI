
#ifndef SGUI_PICTURE_H
#define SGUI_PICTURE_H


typedef struct
{
  const unsigned char  *picture;
  unsigned short	x;
  unsigned short	y;
  unsigned short	w;
  unsigned short	h;
  unsigned short	rx;
  unsigned short	ry;
  unsigned short	frameWidth;
  unsigned short	frameColor;
  //void 			(*action)(void);
}Object_Picture;


void	SGUI_drawPicture(unsigned short page, unsigned short	picId);
void	SGUI_createPicture(unsigned short page,
                         unsigned char *picture,
                         unsigned short	x, unsigned short	y,
                         unsigned short	w, unsigned short	h,
                         unsigned short	rx, unsigned short ry,
                         unsigned short	frameWidth,
                         unsigned short	frameColor);


#endif
