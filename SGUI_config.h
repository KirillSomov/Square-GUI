
#ifndef SGUI_CONFIG_H
#define SGUI_CONFIG_H


#include "stddef.h"


#define SGUI_pageStorageCreate(pageId, labelAmount, buttonAmount, pictureAmount, canvasAmount);\
Object_Label ObjLabelList_##pageId[labelAmount] = {0};\
Object_Button ObjButtonList_##pageId[buttonAmount] = {0};\
Object_Picture ObjPictureList_##pageId[pictureAmount] = {0};\
Object_Canvas ObjCanvasList_##pageId[canvasAmount] = {0};\
Page_t page_##pageId = {0, {0, 0, 0, 0,\
                          ObjLabelList_##pageId,\
                          ObjButtonList_##pageId,\
                          ObjPictureList_##pageId,\
                          ObjCanvasList_##pageId}, NULL};


#define SGUI_pagesStorageCreate(pagesAmount);\
Page_t *pagesStorage[pagesAmount] = {NULL};


#define SGUI_guiStorageCreate();\
GUI_t GUI = {0, 0, {0, 0}, 0, pagesStorage};


void GUI_pagesStorageInit(void);


#endif
