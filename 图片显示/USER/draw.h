#ifndef __PIC_H
#define __PIC_H
//#include "draw.h"
//#include "pander.h"
#include "lcd.h"

void draw_bmp(int right,int up,u8 *bmp_pic);
void draw_pic(int right,int up,const unsigned char*pic);
#endif
