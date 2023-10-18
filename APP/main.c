#include "TIVAC_TIMER_DRIVER.h"



/*==============*global variables============*/
volatile uint8_t flag=0;
uint8_t gOnTime =  2;
uint8_t gOffTime = 2;

volatile uint8_t gCOUNTER1=0;
volatile uint8_t gCOUNTER2=0;

/*=============functions prototype===========*/
void CONTROLE_ON_And_OFF_Time(uint8_t On_Time , uint8_t Off_Time);
void TIMER_CALLBACK(void);



int main()
{

	/*init the gpio pin*/
	GPIO_Pin_Configure_t PinF1_cfg;
	PinF1_cfg.GPIO_MODE = GPIO_MODE_OUTPUT;
	PinF1_cfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_2mA;
	PinF1_cfg.GPIO_Pin_Number = PIN_1;
	MCAL_GPIO_Init(GPIOF,&PinF1_cfg);

	
	/*init the timer0*/
	TIMER_CONFIGRATIONS Timer_CONFIG;
	Timer_CONFIG.TIMER_MODE = TIEMR_MODE_PERIODIC;
	Timer_CONFIG.TIMER_USE = TIEMR_USE_INDIVIDUAL;
	Timer_CONFIG.TIMER_COUNT_DIR = TIMER_COUNT_DIR_DOWN;
	Timer_CONFIG.TIMER_PRESCALER = TIMER_PRESCALER_250;
	Timer_CONFIG.TIMER_COUNTS_IN_mS =1000;
	Timer_CONFIG.P_IRQ_CALLBACK = TIMER_CALLBACK; //Passing the ISR as a callback function from App Layer to Timer driver in MCAL layer
	MCAL_TIMER_Init(TIMER0 , &Timer_CONFIG);
	MCAL_TIMER_START(TIMER0);
	
	
		while(1)
		{

		}
	
}

//Passing the ISR as a callback function from App Layer to Timer driver in MCAL layer
void TIMER_CALLBACK(void)
{
		CONTROLE_ON_And_OFF_Time( gOnTime ,  gOffTime);
}


void CONTROLE_ON_And_OFF_Time(uint8_t On_Time , uint8_t Off_Time)
{
	//TIMER0A_Handler by seconds -->ON_TIME*/
		if(gCOUNTER1 <On_Time && flag ==0)
		{
			 MCAL_GPIO_Write_Pin(GPIOF,PIN_1,Pin_High);
		}
		if(gCOUNTER1==On_Time)
		{
			flag=1;
			gCOUNTER1 =0;
		}
	
	/*TIMER0A_Handler by seconds -->OFF_TIME*/
		if(gCOUNTER2 <Off_Time && flag==1)
		{
			MCAL_GPIO_Write_Pin(GPIOF,PIN_1,Pin_Low);
		} 
	
		if(gCOUNTER2==Off_Time)
		{
			flag=0;
			gCOUNTER2=0;
		}
		
		/*COUNTERS UPDATE*/
		if(flag==0)
		{
			  gCOUNTER1++;
		}
				if(flag==1)
		{
			  gCOUNTER2++;
		}
	
}



void EXTI_CallBack(void)
{
	
}