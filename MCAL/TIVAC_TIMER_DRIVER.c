#include "TIVAC_TIMER_DRIVER.h"

/*2^16 = 65536
16MHz = 16000000 
Maximum delay  = 65536/16000000 = 4.096 millisecond*/



/*==========================================================*/
/*******************gobles variables in c********************/
/*==========================================================*/
void(*gP_Timer_CallBack)(void)=NULL;



/*==============================================================*/
/**********************Private FuncionsPrototyps ************************/
/*==============================================================*/
void Enable_Clock_Timer(TIMER_TypeDef *TIMERx);
void Enable_NVIC_Timer_IRQ(TIMER_TypeDef *TIMERx);
void TIMER0A_Handler(void);



/*==================Private Funcions Definitions====================*/
/**=================================================================
 * @Fn -                    -Enable_Clock_Timer
 * @brief -                 -Enable the clock for TIMERx x can be(0...5)
 * @param [in] -            -TIMERx : where x can be (1..5)
 * @retval -                -none
 */
/**================================================================= */
void Enable_Clock_Timer(TIMER_TypeDef *TIMERx)
{
	if(TIMERx == TIMER0) //enable clock for Timer0
	 {
		 RCC_TIMER0_CLOCK_EN();
	 }
}

/**=================================================================
 * @Fn -                    -Enable_NVIC_Timer_IRQ
 * @brief -                 -Enable the IRC for Timerx x can be(0...5)
 * @param [in] -            -TIMER_TypeDef : where x can be (1..5)
 * @retval -                -none
 */
/**================================================================= */
void Enable_NVIC_Timer_IRQ(TIMER_TypeDef *TIMERx)
{
	if(TIMERx == TIMER0) //enable NVIC IRQ for Timer0
	 {
		 NVIC_ENABLE_IRQ19(); 
	 }
}
/*==========================================================*/




/*==========================================================*/
/***************MCAL_TIMER_APIs Definitions******************/
/*==========================================================*/

/**=================================================================
 * @Fn -                    -MCAL_TIMER_Init
 * @brief -                 -Initialize the TIMER according specified parameters in timer_config
 * @param [in] -            -TIMER_TypeDef : where x can be (1..5)
 * @param [in] -            -timer_config pointer to a TIMER_CONFIGRATIONS structure that contains it
 * @retval -                -none
 */
/**================================================================= */

void MCAL_TIMER_Init(TIMER_TypeDef *TIMERx ,TIMER_CONFIGRATIONS * timer_config)
{
	gP_Timer_CallBack = timer_config->P_IRQ_CALLBACK; //assign the callback which the user will pass it from the app layer
	
	Enable_Clock_Timer(TIMERx);
	Enable_NVIC_Timer_IRQ(TIMERx);
	 
	 
	 if(timer_config->TIMER_USE == TIEMR_USE_INDIVIDUAL)
	 {
		 //For a 16/32-bit timer, this value selects the 16-bit timerconfiguration
		 TIMERx->GPTMCFG = 0x4;
	
		 //For the 16/32-bit GPTM, this field contains the entire 8-bit prescaler
		 //set prescaller
		 TIMERx->GPTMTAPR = timer_config->TIMER_PRESCALER; 
	 }
	 if(timer_config->TIMER_MODE == TIEMR_MODE_PERIODIC && timer_config->TIMER_COUNT_DIR == TIMER_COUNT_DIR_DOWN)
	 {
		 //0x2 Periodic Timer mode and doun
		 TIMERx->GPTMTAMR = 0x02;
	 }
	 TIMERx->GPTMTAILR =  ((timer_config->TIMER_COUNTS_IN_mS)*64) - 1 ;/* TimerA counter starting count down value  */
	 TIMERx->GPTMIMR = (1<<0);        /*enables TimerA time-out  interrupt mask */
}


/**=================================================================
 * @Fn -                    -MCAL_TIMER_START
 * @brief -                 -start the spicfied timer to start counting
 * @param [in] -            -TIMER_TypeDef : where x can be (1..5)
 * @retval -                -none
 */
/**================================================================= */
void MCAL_TIMER_START(TIMER_TypeDef *TIMERx)
{
	
	if(TIMERx==TIMER0)
	{
		/*Timer A is enabled and begins counting or the capture logic is
    enabled based on the GPTMCFG register.*/
		TIMERx->GPTMCTL = 0x01; /* Enable TimerA module */
	}

}



/*==============================================================*/
/*********************************ISR****************************/
/*==============================================================*/
//Creating a Timer Overflow ISR that performs the required functionality
void TIMER0A_Handler(void)
{
		gP_Timer_CallBack(); //Passing the ISR as a callback function from App Layer to Timer driver in MCAL layer

	TIMER0->GPTMICR =0x1; /* Timer1A timeout flag bit clears*/
}