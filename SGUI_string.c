
#include "SGUI_string.h"


static char strBuf[64] = {0};


void SGUI_printString(char* string,
                      unsigned short x, unsigned short y,
                      unsigned short size,
                      unsigned short backgroundColor, unsigned short textColor)
{
  char *nl;
  nl = strchr(string, '\n');
  if(!nl)
  {
    SGUI_LCD_printString(string, x, y, size, backgroundColor, textColor);
  }
  while(nl)
  {
    strncpy(strBuf, string, nl-string);
    strBuf[(nl-string)+1] = '\0';
    SGUI_LCD_printString(strBuf, x, y, size, backgroundColor, textColor);
    y+= size;
    if(strchr(nl+1, '\n'))
    {
      nl = strchr(nl+1, '\n');
    }
    else
    {
      SGUI_LCD_printString(nl+1, x, y, size, backgroundColor, textColor);
      nl = 0;
    }
  }
}
