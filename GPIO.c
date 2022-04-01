/*
 * GPIO.c
 * GPIO driver for ATMEGA32
 * Created: 10/11/2021 11:20:54 PM
 * Author: Hany Hamza
 */ 

#include "GPIO.h"

void GPIO_Init(volatile uint8_t * port, char pin, enum direction dir)
{
	if(dir == INPUT)
		*(DDR(port)) &= ~(1 << pin);
	else if(dir == OUTPUT)
		*(DDR(port)) |= (1 << pin);
}

void GPIO_Write(volatile uint8_t * port, char pin, enum signal sig)
{
	if(sig == LOW)
		*(port) &= ~(1 << pin);
	else if(sig == HIGH)
		*(port) |= (1 << pin);
}

char GPIO_Read(volatile uint8_t * port, char pin)
{
	char temp;
	temp = (*(PIN(port)) & (1 << pin)) >> pin;
	return temp;
}

void GPIO_Pullup(volatile uint8_t * port, char pin, enum status stat)
{
	if(stat == OFF)
		*(port) &= ~(1 << pin);
	else if(stat == ON)
		*(port) |= (1 << pin);
}