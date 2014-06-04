
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"


#define LED_RED_ON  			0x02
#define LED_RED_OFF 			0x00
#define LED_RED_PIN 			GPIO_PIN_1


int main(void)
{
				//enable 
        // 
				ROM_SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
				//enable clock for PORTF
        ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
				//initialisation pins as output
        ROM_GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, LED_RED_PIN);
        
				while(1)
        {
						GPIOPinWrite(GPIO_PORTF_BASE, LED_RED_PIN, LED_RED_ON);
            SysCtlDelay(3000000);
						
						GPIOPinWrite(GPIO_PORTF_BASE, LED_RED_PIN, LED_RED_OFF);
						SysCtlDelay(1500000);
							    
        }
}
