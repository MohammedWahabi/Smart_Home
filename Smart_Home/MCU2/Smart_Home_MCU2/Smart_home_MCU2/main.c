/*
 * Smart_home_MCU2.c
 *
 * Created: 6/12/2021 2:46:01 PM
 * Author : ArtDeco
 */ 


#include "SPI.h"
#define F_CPU 16000000
#include <util/delay.h>
#include "Smart_Home.h"
int main(void)
{
    
	uint8 rx_data = 0;
	uint8 tx_data = 0;
	
	/*Init LED*/
	DIO_SetPinDir(DIO_PORTC , DIO_PIN1 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTC , DIO_PIN2 , DIO_PIN_OUTPUT);
	/*SPI Slave init*/
	SPI_Slave_Init();
	
	
	
    while (1) 
    {
		rx_data = SPI_TranSiver(tx_data);
		
		switch (rx_data)
		{
			
			case Blue:
			DIO_SetPinValue(DIO_PORTC , DIO_PIN1 , DIO_PIN_HIGH);
			DIO_SetPinValue(DIO_PORTC , DIO_PIN2 , DIO_PIN_LOW);
			rx_data=0;
			break;
			
			case Red: 
			DIO_SetPinValue(DIO_PORTC , DIO_PIN2 , DIO_PIN_HIGH);
			DIO_SetPinValue(DIO_PORTC , DIO_PIN1 , DIO_PIN_LOW);
			rx_data=0;
			break;
			
			
		}
    }
}

