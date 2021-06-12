/*
 * Smart_Home_MCU1.c
 *
 * Created: 6/12/2021 3:07:46 PM
 * Author : ArtDeco
 */ 


#include "SPI.h"
#include "UART.h"
#include "LCD.h"

#define F_CPU 16000000
#include <util/delay.h>

int main(void)
{
	uint8 User_Input = 0;
	
	LCD_Init();
	UART_Init();	
	SPI_Master_Init();
	SPI_Master_InitTrans();
	_delay_ms(1000);
	
	while (1)
	{
		User_Input = UART_Rx();
		
		
		if(User_Input)
		{
			
			LCD_WriteChar(User_Input);
			SPI_TranSiver(User_Input);
			_delay_ms(750);
			LCD_Clear();
		}
		
		_delay_ms(1000);
	}
}

