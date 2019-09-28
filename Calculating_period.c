#include "C:/Keil/labware/inc/tm4c123gh6pm.h"
#include "stdint.h"

float Calculated_signal_period (){
	
	float period;
	float Rise_edge[2];
	int i;
	
	for (i=0; i <2; i++){
		while((TIMER0_RIS_R & 4) == 0);
		Rise_edge[i] = TIMER0_TAR_R;
		TIMER0_ICR_R = 4;
	}
	
	if (Rise_edge[1] < Rise_edge[0]){
		
		Rise_edge[1] = Rise_edge[1] - (0x0000FFFF - Rise_edge[0]);
	
	}
	
	period = Rise_edge[1] - Rise_edge[0];

	
	return (period && 0x00FFFFFF);

}