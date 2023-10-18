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



//RCC
#define RCG2                     				*((volatile unsigned long*)0x400FE108)     
#define SYSCT_RCGC_CLK_ENABLE    				*((volatile unsigned long*)0x400FE608)    
#define SYSCT_RCGCTIMER_CLK_ENABLE    	*((volatile unsigned long*)0x400FE604)     
#define GPIOF_DATA_REG        					*((volatile unsigned long*)0x400253FC)



//NVIC RIGISTERS
#define EN0                     				(*((volatile unsigned long*)0xE000E100))
#define EN2                     				(*((volatile unsigned long*)0xE000E108))


//IRQ NUMBER FOR GPIOs
#define IRQ_PORTA              					0
#define IRQ_PORTB              					1
#define IRQ_PORTC              					2
#define IRQ_PORTD              					3
#define IRQ_PORTE              					4
#define IRQ_PORTF              					30

//IRQ NUMBER FOR TIMERs
#define TIMER0A_IRQ           				 	19
#define TIMER0B_IRQ            					20
#define TIMER1A_IRQ            					21
#define TIMER1B_IRQ            					22
#define TIMER2A_IRQ            					23
#define TIMER2B_IRQ            					24
	


/*==========================================================*/
/*********************NVIC IRQs ENABLE MACROS*******************/
/*==========================================================*/
//NVIC IRQs ENABLE FOR GPIOs
#define NVIC_ENABLE_IRQ0()    					(EN0 |=(1<<IRQ_PORTA))   /*Enable PORTA Interrupt IRQ0 */
#define NVIC_ENABLE_IRQ1()    					(EN0 |=(1<<IRQ_PORTB))   /*Enable PORTB Interrupt IRQ1 */
#define NVIC_ENABLE_IRQ2()    					(EN0 |=(1<<IRQ_PORTC))   /*Enable PORTC Interrupt IRQ2 */
#define NVIC_ENABLE_IRQ3()    					(EN0 |=(1<<IRQ_PORTD))   /*Enable PORTD Interrupt IRQ3 */
#define NVIC_ENABLE_IRQ4()    					(EN0 |=(1<<IRQ_PORTE))   /*Enable PORTE Interrupt IRQ4 */
#define NVIC_ENABLE_IRQ30()    					(EN0 |=(1<<IRQ_PORTF))   /*Enable PORTF Interrupt IRQ30 */

//NVIC IRQs ENABLE FOR TIMERs
#define NVIC_ENABLE_IRQ19()    					(EN0 |=(1<<TIMER0A_IRQ)) /*Enable TIMER0A Interrupt IRQ19 */
#define NVIC_ENABLE_IRQ20()    					(EN0 |=(1<<TIMER0B_IRQ)) /*Enable TIMER0B Interrupt IRQ20 */
#define NVIC_ENABLE_IRQ21()    					(EN0 |=(1<<TIMER1A_IRQ)) /*Enable TIMER1A Interrupt IRQ21 */
#define NVIC_ENABLE_IRQ22()    					(EN0 |=(1<<TIMER1B_IRQ)) /*Enable TIMER1B Interrupt IRQ22 */
#define NVIC_ENABLE_IRQ23()    					(EN0 |=(1<<TIMER2A_IRQ)) /*Enable TIMER2A Interrupt IRQ23 */
#define NVIC_ENABLE_IRQ24()    					(EN0 |=(1<<TIMER2B_IRQ)) /*Enable TIMER2B Interrupt IRQ24 */



