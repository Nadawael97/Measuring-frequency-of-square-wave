#include "stdint.h"

void Timer_Init(void);
void PORTF_Init(void);
float Calculated_signal_period (void);
void SysTick_Init(void);
void SysTick_Wait(uint32_t);
void SysTick_Wait1ms(int);