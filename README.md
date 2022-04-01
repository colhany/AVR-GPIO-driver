# AVR-GPIO-driver
Simple GPIO driver for ATMEGA32 AVR microcontroller.

Can be modified to work with other AVR microcontrollers, by changing the gpio registers' addresses and offset.

Funtions:

  1.GPIO_Init(&PORT_NAME, PIN_NUMBER, DIRECTION)
      
      Initializes the pin as input or output, pass INPUT or OUTPUT as direction.
      
  2.GPIO_Write(&PORT_NAME, PIN_NUMBER, SIGNAL)
      
      Writes a HIGH or LOW signal on the output pin.
      
  3.GPIO_Read(&PORT_NAME, PIN_NUMBER)
      
      Reads the signal applied on an input pin, returns 0 or 1.
      
  4.GPIO_Pullup(&PORT_NAME, PIN_NUMBER, STATUS)
      
      Turns internal pullup resistors on or off for a specific input pin, pass ON or OFF as status.
  
  **Calling the GPIO_Write function on an input pin would result in activating or deactivating the internal pullup resistors of this pin**
