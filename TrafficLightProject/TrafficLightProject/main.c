#include "Application/Application.h"

int main(){
	AppInit();
	while(1){
		AppStart();
		//TimerTestFunction();
		//InterruptTestFunction();
		//DIOTestFunctionForOutput();
		//DIOTestFunctionForInputA();
		//DIOTestFunctionForInputB();
		//DIOTestFunctionForInputC();
		//DIOTestFunctionForInputD();
		//LEDTestFunctionOn();
		//LEDTestFunctionOff();
		//ButtonTestFunction();
		
	}
}
void ButtonTestFunction(){
Button_init(PORT_A,3);
LED_init(PORT_D,4);
if(Button_read(PORT_A,3)==1){
	LED_on(PORT_D,4);
}
else{
	LED_off(PORT_D,4);
}	
}