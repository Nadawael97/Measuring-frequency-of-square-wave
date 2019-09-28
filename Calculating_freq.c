#include "C:/Keil/labware/inc/tm4c123gh6pm.h"
#include "stdint.h"
#include "functions.h"

void SystemInit(){};	
float calculated_freq = 0;
	
int main (void){
  
	Timer_Init();
	
	while (1){
		//OUTPUT_signal();
		calculated_freq = (1/ (Calculated_signal_period ()));
	}
}

