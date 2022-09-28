
#include "SGUI_dataTransfer.h"
#include "SGUI_string.h"
#include "string.h"
#include "stdio.h"


static char strBuf[64] = {0};


void SGUI_printString(char* string,
                      unsigned short x, unsigned short y,
                      unsigned short size,
                      signed long backgroundColor, unsigned short textColor)
{
  char *nlL = string;
  char *nlR = 0;
  nlR = strchr(string, '\n');
  if(!nlR)
  {
    SGUI_LCD_printString(string, x, y, size, backgroundColor, textColor);
  }
  while(nlR)
  {
    strncpy(strBuf, nlL, nlR-nlL);
    strBuf[(nlR-nlL)] = '\0';
    SGUI_LCD_printString(strBuf, x, y, size, backgroundColor, textColor);
    nlL = nlR + 1;
    y+= size;
    if(!(nlR = strchr(nlL, '\n')))
    {
      SGUI_LCD_printString(nlL, x, y, size, backgroundColor, textColor);
    }
  }
}


char* SGUI_intToStr(int i)
{
  sprintf(strBuf, "%d", i);
  return strBuf;
}
