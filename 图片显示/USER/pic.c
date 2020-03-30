#include "draw.h"
#include "pander.h"
#include "lcd.h"
//extern const unsigned char gImage_pander[];
void draw_pic(int right,int up,const unsigned char *pic)	
{
	    unsigned char pic_high,pic_wide;
	    int x,y;
      pic_high=pic[4];
			pic_wide=pic[2];
			for(x=0;x<pic_wide;x++)
		  for(y=0;y<pic_high;y++)
			LCD_Fast_DrawPoint(x+right,y+up,pic[8+(y*pic_wide+x)*2]+pic[(y*pic_wide+x)*2+9]*256);
}

void draw_bmp(int right,int up,u8 *bmp_pic)
{
		 unsigned char BMP_high,BMP_wide;
		 int x,y;
	   BMP_wide=bmp_pic[0x12];
	   BMP_high=bmp_pic[0x16];
	    for(x=0;x<BMP_wide;x++)
		  for(y=0;y<BMP_high;y++)
	    LCD_Fast_DrawPoint(x+right,BMP_high-y+up,bmp_pic[54+(y*BMP_wide+x)*2]+bmp_pic[(y*BMP_wide+x)*2+55]*2*256);//×2为什么？？观察数据得来
			//LCD_Fast_DrawPoint(x+right,y+up,bmp_pic[bmp_pic[1078+(y*BMP_wide+x)*2]]+bmp_pic[bmp_pic[1078+(y*BMP_wide+x)*2]+1]*256);
}
