#include "stdio.h"
#include "stdint.h"


//GPIOs BASE ADDRESS
#define GPIO_PORT_A_BASE_ADD            0x40004000
#define GPIO_PORT_B_BASE_ADD            0x40005000
#define GPIO_PORT_C_BASE_ADD            0x40006000
#define GPIO_PORT_D_BASE_ADD            0x40007000
#define GPIO_PORT_E_BASE_ADD            0x40024000
#define GPIO_PORT_F_BASE_ADD  					0x40025000


//TIMERs BASE ADDRESS
#define TIMER0_BASE_ADD                 0x40030000
#define TIMER1_BASE_ADD            			0x40031000
#define TIMER2_BASE_ADD            			0x40032000
#define TIMER3_BASE_ADD           		  0x40033000
#define TIMER4_BASE_ADD            			0x40034000
#define TIMER5_BASE_ADD  		 			 			0x40035000


//SYSTEM CONTROL BASE ADDRESS
#define SYSTEM_CTL_BASE_ADD             0x400FE000



//PORTF REGISTERS

#define SYSCTL_RCGC2_R        					(*((volatile unsigned long*)0x400FE108))//control register enable GOIP
	

#define GPIOF_DIR_REG         					*((volatile unsigned long*)0x40025400)
#define GPIOF_DATA_REG        					*((volatile unsigned long*)0x400253FC)	//write on pin
#define GPIOF_DEN_R     		  					*((volatile unsigned long*)0x04002551C) //enable pin 
#define GPIOF_GPIODR2R        					*((volatile unsigned long*)0x040025500) //GPIO 2-mA Drive Select
#define GPIOF_GPIODR4R        					*((volatile unsigned long*)0x040025504) //GPIO 4-mA Drive Select
#define GPIOF_GPIODR8R        					*((volatile unsigned long*)0x040025500) //GPIO 8-mA Drive Select

	
//RCC
#define RCG2                     				*((volatile unsigned long*)0x400FE108)     
#define SYSCT_RCGC_CLK_ENABLE    				*((volatile unsigned long*)0x400FE608)    
/*Register 59: 16/32-Bit General-Purpose Timer Run Mode Clock Gating Control
(RCGCTIMER), offset 0x604
The RCGCTIMER register provides software the capability to enable and disable 16/32-bit timer
modules in Run mode. When enabled, a module is provided a clock and accesses to module registers
are allowed.*/
#define SYSCT_RCGCTIMER_CLK_ENABLE    	*((volatile unsigned long*)0x400FE604)     



//NVIC RIGISTERS
#define EN0                     				(*((volatile unsigned long*)0xE000E100))
#define EN2                     				(*((volatile unsigned long*)0xE000E108))


//IRQ 
#define IRQ_PORTF              					30
#define TIMER0A_IRQ           				 	19
#define TIMER0B_IRQ            					20
	


/*==========================================================*/
/*********************CLOCK ENABLE MACROS*******************/
/*==========================================================*/
//NVIC IRQs ENABLE
#define NVIC_ENABLE_IRQ30()    					(EN0 |=(1<<IRQ_PORTF))   /*Enable PORTF   Interrupt IRQ30 */
#define NVIC_ENABLE_IRQ19()    					(EN0 |=(1<<TIMER0A_IRQ)) /*Enable TIMER0A Interrupt IRQ19 */
#define NVIC_ENABLE_IRQ20()    					(EN0 |=(1<<TIMER0B_IRQ)) /*Enable TIMER0B Interrupt IRQ20 */




