/*
 ================================================================================================
 Name        : mini_project_4.c

 Author      : Hassan Sabry Ahmed Shahin

 Description : Measure the distance using the Ultrasonic sensor
  	  	  	   HC-SR04 using ATmega32 microcontroller.

 Date        : Apr 20, 2023
 ================================================================================================
 */

#include "ultrasonic.h"
#include "lcd.h"
#include <avr/io.h> /* To use the SREG register */
#include <util/delay.h>


int main()
{

	uint16 ultrasonic_distance=0;

	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	/* Initialize both the LCD and ULTRASONIC driver */
	LCD_init();
	Ultrasonic_init();


	/*to display distance on LCD*/
	LCD_displayString("Distance=");
	LCD_moveCursor(0,13);
	LCD_displayString("cm");

	while(1)
	{
		/*to get distance value from ultrasonic function*/
		ultrasonic_distance=Ultrasonic_readDistance();


		if(ultrasonic_distance<10){

			/*to display distance at the same position*/
			LCD_moveCursor(0,9);

			/*to display distance according to ultrasonic sensor*/
			LCD_intgerToString(ultrasonic_distance);

			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		if(ultrasonic_distance<100){

			/*to display distance at the same position*/
			LCD_moveCursor(0,9);

			/*to display distance according to ultrasonic sensor*/
			LCD_intgerToString(ultrasonic_distance);

			/* In case the digital value is two or one digits print space in the next digit place */				LCD_displayCharacter(' ');
			LCD_displayCharacter(' ');
		}
		if(ultrasonic_distance>=100){

			/*to display distance at the same position*/
			LCD_moveCursor(0,9);

			/*to display distance according to ultrasonic sensor*/
			LCD_intgerToString(ultrasonic_distance);
		}




	}
}
