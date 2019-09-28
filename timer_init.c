#include "C:/Keil/labware/inc/tm4c123gh6pm.h"
#include "stdint.h"

void Timer_Init (void){
	
	SYSCTL_RCGCTIMER_R |= 1;   //clock for the timer0
	SYSCTL_RCGCGPIO_R |=2;     //clock for PORTB
	
	GPIO_PORTB_DIR_R &= ~0x40;     //PB6 input
	GPIO_PORTB_DEN_R |= 0x40;      //PB6 digital enable
	GPIO_PORTB_AFSEL_R |= 0x40;    //alternative function for PB6
	GPIO_PORTB_PCTL_R &= ~0x0F000000;    //reset all the PCTL bits
	GPIO_PORTB_PCTL_R |= 0x07000000;     //timer
	
	TIMER0_CTL_R &= ~1;         //disable timer
	TIMER0_CFG_R = 4;           //timerA periodic mode
	TIMER0_TAMR_R = 0x17;       //capture mode; edge time mode; count up
	TIMER0_CTL_R &= 0x00;       //capture at the positive edge
	TIMER0_CTL_R |= 1;          //enable timer
	
}
