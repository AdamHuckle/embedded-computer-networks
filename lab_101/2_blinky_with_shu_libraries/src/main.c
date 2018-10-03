/*
 * main.c
 *
 * this is the main blinky application (this code is dependent on the
 * extra shu libraries such as the pinmappings list and the clock configuration
 * library)
 *
 * author:    Dr. Alex Shenfield
 * date:      01/09/2018
 * purpose:   55-604481 embedded computer networks : lab 101
 */

// include the hal drivers
#include "stm32f7xx_hal.h"

// include the shu bsp libraries for the stm32f7 discovery board
#include "pinmappings.h"
#include "clock.h"
#include "gpio.h"

// map the led to GPIO PI1 (again, this is the inbuilt led)
gpio_pin_t Red = {PI_1, GPIOI, GPIO_PIN_1};
gpio_pin_t Yellow = {PB_14, GPIOB, GPIO_PIN_14};
gpio_pin_t Green = {PB_15, GPIOB, GPIO_PIN_15};
// this is the main method
int main()
{
  // we need to initialise the hal library and set up the SystemCoreClock 
  // properly
  HAL_Init();
  init_sysclk_216MHz();
  
  // initialise the gpio pins
  init_gpio(Red, OUTPUT);
  init_gpio(Yellow, OUTPUT);
	init_gpio(Green, OUTPUT);
  // loop forever ...
  while(1)
  {
    
	// Stage 1 Red Only 
    write_gpio (Red, HIGH);		// turn the red led on 
		write_gpio (Yellow, LOW);		// turn the Yellow led off
		write_gpio (Green, LOW);		// turn the Green led off
		
  // wait for 1 second
    HAL_Delay(1500);		// delay for 1.5 second 
		
	// Stage 2 Red and Yellow 
    write_gpio (Red, HIGH);		// turn the red led on 
		write_gpio (Yellow, HIGH);		// turn the Yellow led on
		write_gpio (Green, LOW);		// turn the Green led off
	
	// wait for 1 second
    HAL_Delay(500);		// delay for 1.5 second 
		
	// Stage 3 Yellow Only 
		write_gpio (Red, LOW);		// turn the red led off 
		write_gpio (Yellow, HIGH);		// turn the Yellow led on
		write_gpio (Green, LOW);		// turn the Green led off

	// wait for 1 second
    HAL_Delay(1000);		// delay for 1.5 second		
		
	// Stage 4 Green Only
		
		write_gpio (Red, LOW);		// turn the red led off 
		write_gpio (Yellow, LOW);		// turn the Yellow led off
		write_gpio (Green, HIGH);		// turn the Green led on
		
	// wait for 1 second
    HAL_Delay(1500);		// delay for 1.5 second		
		
	//Stage 5	Yellow Only 
	
		write_gpio (Red, LOW);		// turn the red led off 
		write_gpio (Yellow, HIGH);		// turn the Yellow led on
		write_gpio (Green, LOW);		// turn the Green led off

// wait for 1 second
    HAL_Delay(1000);		// delay for 1.5 second		
  }
}
