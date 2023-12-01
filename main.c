/*
 * EmbeddedFinalProject.c
 *
 * Created: 11/26/2023 8:56:07 AM
 * Author : tim
 */ 

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart_hal.h"
#include "timer1_hal.h"
#include "timer0_hal.h"
//#include <Wire.h>
#include "SPI.h"
#include "Adafruit_GFX.h"

//#include "XPT2046_Touchscreen.h"

#define TFT_CS   10
#define TFT_DC   8

int main(void) {
	
	uart_init(9600, 0);
	
	pwn_init();
	
	sei();
	
	tft.begin();  // Initialize TFT LCD screen
	tft.setRotation(1);
	tft.fillScreen(ILI9341_BLACK);
	
	servo_set(0, 180);
	
	int16_t i = 0;
	
	while(1) {
		for (i = 0; i <= 180; i++) {
			servo_set(i, 180);
			_delay_ms(40);
		}
		for (i = 180; i >= 0; i--) {
			servo_set(i, 180);
			_delay_ms(40);
		}
	}
}

