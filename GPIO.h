/*
 * GPIO.h
 * GPIO driver for ATMEGA32
 * Created: 10/11/2021 11:20:42 PM
 * Author: Hany Hamza
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>

#ifndef _AVR_IO_H_

#define PORTA (*(volatile uint8_t  *)(0x3B))
#define PORTB (*(volatile uint8_t  *)(0x38))
#define PORTC (*(volatile uint8_t  *)(0x35))
#define PORTD (*(volatile uint8_t  *)(0x32))

#endif

//register offsets
#define DDR(PORT) PORT - 1
#define PIN(PORT) PORT - 2

enum signal{LOW, HIGH};
enum direction{INPUT, OUTPUT};
enum status{OFF, ON};

//Pass PORT name as a pointer, ex. &PORTA
void GPIO_Init(volatile uint8_t * port, char pin, enum direction dir);
void GPIO_Write(volatile uint8_t * port, char pin, enum signal sig);
char GPIO_Read(volatile uint8_t * port, char pin);
void GPIO_Pullup(volatile uint8_t * port, char pin, enum status stat);

#endif