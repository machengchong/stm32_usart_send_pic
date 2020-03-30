#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "timer.h"
#include "draw.h"
//ALIENTEK Mini STM32开发板范例代码11
//TFTLCD显示实验   
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司 
extern const unsigned char gImage_pander[];
 int main(void)
 { 
	 u32 t;
	delay_init();	    	 //延时函数初始化	  
	uart_init(115200);	 	//串口初始化为115200
 	LCD_Init();		 	
	TIM3_Int_Init(49,7199);
	draw_pic(0,0,gImage_pander);
  	while(1) 
	{		 
		if(USART_RX_STA==1)  //接收到图片数据
		{
			LCD_Clear(0xffff);

			draw_bmp(100,100,USART_RX_BUF);
			//串口显示
			for(t = 0;t<USART1_RECVLEN;t++)
			{
				USART1->DR=USART_RX_BUF[t];
				while((USART1->SR&0X40)==0);//等待发送结束
			}
			USART_RX_STA=0;
	  } 
  }
}
