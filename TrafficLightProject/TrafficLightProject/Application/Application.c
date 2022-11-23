#include "Application.h"

volatile uint8_t PedMode = 0;
volatile uint8_t PedModeSwitch = 0;
volatile uint8_t Overflows=0;
volatile uint8_t GreenLEDFlag =0;
volatile uint8_t YellowLEDFlag =0;
volatile uint8_t RedLEDFlag =0;

void AppInit(void)
{

	LED_init(PORT_A,0);
	LED_init(PORT_A,1);
	LED_init(PORT_A,2);
	LED_init(PORT_B,0);
	LED_init(PORT_B,1);
	LED_init(PORT_B,2);
	Timer_init(Timer0,Normal_Mode,1024,12);
	ExternalInterrupt_init(INT0,RISING);
}
	void AppStart(void)
	{
		//Start of Normal Mode Loop
		while(PedMode == 0){
			//Car Green Light is on and Pedestrian Red Light is on and that goes for 5 seconds while waiting for any pedestrian to push the button
			LED_off(PORT_A,1);LED_on(PORT_A,0);LED_on(PORT_B,2);LED_off(PORT_B,1);LED_off(PORT_B,0);LED_off(PORT_A,2);
			GreenLEDFlag=1;YellowLEDFlag=0;RedLEDFlag=0;
			TimerStart(Timer0,1024,12);
			while (Overflows<20){if (PedMode == 1){break;}}
			TimerStop(0);
			Overflows=0;
			if(PedMode == 1){break;}
			//Car Yellow Light and Pedestrian Yellow Light are both flashing for 5 seconds while waiting for any pedestrian to push the button
			LED_off(PORT_A,0);LED_off(PORT_B,2);LED_off(PORT_B,0);LED_off(PORT_A,2);
			GreenLEDFlag=0;YellowLEDFlag=1;RedLEDFlag=0;
			TimerStart(Timer0,1024,12);
			for(uint8_t BlinkingCounter=0;BlinkingCounter<5;BlinkingCounter++){
				LED_toggle(PORT_A,1);
				LED_toggle(PORT_B,1);
				while (Overflows<4){if (PedMode == 1){break;}}
				Overflows=0;
				if(PedMode == 1){break;}
			}
			TimerStop(0);
			Overflows=0;
			if(PedMode == 1){break;}
			//Car Red Light is On and Pedestrian Green Light is On for 5 seconds while waiting for any pedestrian to push the button
			LED_off(PORT_A,1);LED_on(PORT_A,2);LED_on(PORT_B,0);LED_off(PORT_B,1);LED_off(PORT_B,2);LED_off(PORT_A,0);
			GreenLEDFlag=0;YellowLEDFlag=0;RedLEDFlag=1;
			TimerStart(Timer0,1024,12);
			while (Overflows<20){if (PedMode == 1){break;}}
			TimerStop(0);
			Overflows=0;
			if(PedMode == 1){break;}
			//Car Yellow Light and Pedestrian Yellow Light is flashing and Green Pedestrian Light is still On while waiting for any pedestrian to push the button
			LED_off(PORT_A,0);LED_off(PORT_B,2);LED_off(PORT_B,0);LED_off(PORT_A,2);
			GreenLEDFlag=0;YellowLEDFlag=1;RedLEDFlag=0;
			TimerStart(Timer0,1024,12);
			for(uint8_t BlinkingCounter=0;BlinkingCounter<5;BlinkingCounter++){
				LED_toggle(PORT_A,1);
				LED_toggle(PORT_B,1);
				while (Overflows<4){if (PedMode == 1){break;}}
				Overflows=0;
				if(PedMode == 1){break;}
			}
			TimerStop(0);
			Overflows=0;
			if(PedMode == 1){break;}
			
		}
		//Start of Pedestrian Mode
		if (PedMode == 1)
		{
			//Check if button is pressed during a Red light
			if(RedLEDFlag){
				//Car Red Light Stays On and Green Pedestrian Light as well for 5 seconds
				LED_off(PORT_A,1);LED_on(PORT_A,2);LED_on(PORT_B,0);LED_off(PORT_B,1);LED_off(PORT_B,2);LED_off(PORT_A,0);
				TimerStart(Timer0,1024,12);
				while (Overflows<20);
				TimerStop(0);
				Overflows=0;
				//Car Yellow Light Starts flashing as well as Pedestrian Yellow Light for 5 seconds while keeping the Green Pedestrian Light On
				LED_off(PORT_A,0);LED_off(PORT_B,2);LED_on(PORT_B,0);LED_off(PORT_A,2);
				TimerStart(Timer0,1024,12);
				for(uint8_t BlinkingCounter=0;BlinkingCounter<5;BlinkingCounter++){
					LED_toggle(PORT_A,1);
					LED_toggle(PORT_B,1);
					while (Overflows<4);
					Overflows=0;
				}
				TimerStop(0);
				Overflows=0;
				PedMode=0;
			}
			else{
				//Car Yellow Light and Pedestrian Yellow Light start flashing and Red Pedestrian Light is On for 5 seconds
				LED_off(PORT_A,1);LED_on(PORT_B,2);LED_off(PORT_B,1);LED_off(PORT_B,0);LED_off(PORT_A,2);
				TimerStart(Timer0,1024,12);
				for(uint8_t BlinkingCounter=0;BlinkingCounter<5;BlinkingCounter++){
					LED_toggle(PORT_A,1);
					LED_toggle(PORT_B,1);
					while (Overflows<4);
					Overflows=0;
				}
				TimerStop(0);
				Overflows=0;
				//Car Red Light is On and Green Pedestrian Light is On for 5 seconds
				LED_off(PORT_A,1);LED_on(PORT_B,0);LED_off(PORT_B,1);LED_off(PORT_B,2);LED_on(PORT_A,2);LED_off(PORT_A,0);
				TimerStart(Timer0,1024,12);
				while (Overflows<20);
				TimerStop(0);
				Overflows=0;
				//Car Yellow Light and Pedestrian Yellow Light start flashing for 5 seconds while maintaining the Green pedestrian Light
				LED_off(PORT_A,0);LED_off(PORT_B,2);LED_on(PORT_B,0);LED_off(PORT_A,2);
				TimerStart(Timer0,1024,12);
				for(uint8_t BlinkingCounter=0;BlinkingCounter<5;BlinkingCounter++){
					LED_toggle(PORT_A,1);
					LED_toggle(PORT_B,1);
					while (Overflows<4);
					Overflows=0;
				}
				TimerStop(0);
				Overflows=0;
				PedMode=0;
			}
		}
	}

ISR(INT0_vect){
	PedMode = 1;
}
ISR(TIMER0_OVF_vect){
	Overflows++;
	TimerStop(0);
	TimerStart(Timer0,1024,12);
}

