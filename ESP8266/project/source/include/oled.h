//////////////////////////////////////////////////////////////////////////////////////////////////////	 
//This program is for learning only,Not to be used for any other purpose 
//without the permission of the author
//Testing Hardware:Raspberry PI 3 Model B and B+,  basic frequency:1GHz
//QDtech-OLED liquid crystal driver for Raspberry PI
//xiaofeng@ShenZhen QDtech co.,LTD
//Company Website:www.qdtft.com
//Taobao Website:http://qdtech.taobao.com
//wiki Technology Website:http://www.lcdwiki.com
//We provide technical support,Any technical questions are welcome to 
//exchange and study at any time
//Fixed telephone (fax):+86 0755-23594567 
//cell-phone:15989313508(Mr Feng)
//E-mail:lcdwiki01@gmail.com    support@lcdwiki.com    goodtft@163.com
//Technical Support QQ:3002773612  3002778157
//Technical Exchange QQ group:324828016
//Date:2018/9/6
//Version:V1.0
//Copyright reserved, piracy must be investigated
//Copyright(C) ShenZhen QDtech co.,LTD 2018-2028
//All rights reserved
/****************************************************************************************************
//This program uses the bcm2835 gpio library,
//so the pin definition using BCM coding
//=====================================power supply wiring===========================================//
// OLED Module                Raspberry PI    
//    VCC        connect       DC 5V/3.3V      //OLED power positive, Physical pin 1,2,4
//    GND        connect          GND          //OLED power ground,Physical pin 6,9,14,20,25,30,34,39
//======================================data line wiring=============================================//
//The default data bus type for this module is 4-wire SPI
// OLED Module                Raspberry PI 
//    MOSI       connect       19(bcm:10)      //OLED spi write signal
//======================================control line wiring==========================================//
// OLED Module                Raspberry PI 
//    CS         connect       24(bcm:8)       //OLED chip selection control signal
//    RES        connect        5(bcm:3)       //OLED reset control signal
//    DC         connect        3(bcm:2)       //OLED data or command selection control signal
//    CLK        connect       23(bcm:11)      //OLED spi colck signal
//========================================touch screen wiring========================================//
//This module has no touch function,so it don't need touch screen wiring
*****************************************************************************************************/	
/****************************************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*****************************************************************************************************/	
#ifndef __OLED_H
#define __OLED_H			  	 
#include <bcm2835.h>
 
//--------------OLED parameter definition ---------------------
#define PAGE_SIZE    8          //page size
#define XLevelL		 0x02       //column low address
#define XLevelH		 0x10       //column high address
#define YLevel       0xB0       //page address
#define	Brightness	 0xFF 
#define WIDTH 	     128        //oled screen width
#define HEIGHT 	     64	        //oled screen height

//-------------Write commands and data definitions-------------------
#define OLED_CMD     0	//write command
#define OLED_DATA    1	//write data
   						  
//-----------------OLED module pin definition----------------
#define OLED_CS   8   //chip selection control signal  bcm:8
#define OLED_DC   2   //data or command selection control signal bcm:2
#define OLED_RST  3   //reset control signal  bcm:3

//-----------------OLED module pin operation definition---------------- 
#define OLED_CS_Clr()  bcm2835_gpio_write(OLED_CS,LOW)
#define OLED_CS_Set()  bcm2835_gpio_write(OLED_CS,HIGH)

#define OLED_DC_Clr()  bcm2835_gpio_write(OLED_DC,LOW)
#define OLED_DC_Set()  bcm2835_gpio_write(OLED_DC,HIGH)
 					   
#define OLED_RST_Clr()  bcm2835_gpio_write(OLED_RST,LOW)
#define OLED_RST_Set()  bcm2835_gpio_write(OLED_RST,HIGH)
						 
//---------------OLED module control function-----------------------
void OLED_WR_Byte(uint8_t dat,uint8_t cmd);     							   		    
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Set_Pos(uint8_t x, uint8_t y);
void OLED_Reset(void);
void OLED_Init_GPIO(void);	   							   		    
void OLED_Init(void);
void OLED_Set_Pixel(uint8_t x, uint8_t y,uint8_t color);
void OLED_Display(void);
void OLED_Clear(uint8_t dat);  
#endif
