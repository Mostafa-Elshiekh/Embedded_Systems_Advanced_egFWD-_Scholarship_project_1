#include "TIVAC_GPIO_DRIVER.h"



/*==========================================================*/
/*******************gobles variables in c********************/
/*==========================================================*/
void(*gP_IRQ_CALLBACK)(void)=NULL;


/*==============================================================*/
/**********************Private FuncionsPrototyps ************************/
/*==============================================================*/
void Enable_Clock_GPIO(GPIO_TypeDef *GPIOx);
void Enable_NVIC_GPIO_IRQ(GPIO_TypeDef *GPIOx);




/*=============Private Funcions Definitions==================*/

/**=================================================================
 * @Fn -                    -Enable_Clock_GPIO
 * @brief -                 -Enable the clock for GPIOx x can be(A...F)
 * @param [in] -            -GPIOx : where x can be (1..5)
 * @retval -                -none
 */
/**================================================================= */
void Enable_Clock_GPIO(GPIO_TypeDef *GPIOx)
{
		if(GPIOx == GPIOA) //enable clock for GPIOA
		{
			RCC_GPIOA_CLOCK_EN();
		}
		else if(GPIOx == GPIOB) //enable clock for GPIOB
		{
		RCC_GPIOB_CLOCK_EN();
		}
		else if(GPIOx == GPIOC) //enable clock for GPIOC
		{
		RCC_GPIOB_CLOCK_EN();
		}
		else if(GPIOx == GPIOD) //enable clock for GPIOD
		{
		RCC_GPIOD_CLOCK_EN();
		}
		else if(GPIOx == GPIOE) //enable clock for GPIOE
		{
		RCC_GPIOE_CLOCK_EN();
		}
		else if(GPIOx == GPIOF) //enable clock for GPIOF
		{
		RCC_GPIOF_CLOCK_EN();
		}
}

/**=================================================================
 * @Fn -                    -Enable_NVIC_GPIO_IRQ
 * @brief -                 -Enable the IRQ for GPIOx x can be(A...E)
 * @param [in] -            -GPIOx : where x can be (A..E)
 * @retval -                -none
 */
/**================================================================= */
void Enable_NVIC_GPIO_IRQ(GPIO_TypeDef *GPIOx)
{
		if(GPIOx == GPIOA) //enable clock for GPIOA
		{
			NVIC_ENABLE_IRQ0();
		}
		else if(GPIOx == GPIOB) //enable clock for GPIOB
		{
			NVIC_ENABLE_IRQ1();
		}
		else if(GPIOx == GPIOC) //enable clock for GPIOC
		{
			NVIC_ENABLE_IRQ2();
		}
		else if(GPIOx == GPIOD) //enable clock for GPIOD
		{
			NVIC_ENABLE_IRQ3();
		}
		else if(GPIOx == GPIOE) //enable clock for GPIOE
		{
			NVIC_ENABLE_IRQ4();
		}
		else if(GPIOx == GPIOF) //enable clock for GPIOF
		{
			NVIC_ENABLE_IRQ30();
		}
}
/*==========================================================*/




/*==========================================================*/
/*****************MCAL_GPIO_APIs definations ****************/
/*==========================================================*/


/**=================================================================
 * @Fn -                    -MCAL_GPIO_Init
 * @brief -                 -Initialize the GPIOx PINy according specified parameters in PinConfig
 * @param [in] -            -GPIOx : where x can be (A..F depending on device used)
 * @param [in] -            -PinConfig pointer to a GPIO_Pin_Configure_t structure that contains
 * @retval -                -none
 * note -                   -TivaC MCU has GPIO A,B,C,D,E,F Modules
 */
/**================================================================= */
void MCAL_GPIO_Init( GPIO_TypeDef *GPIOx , GPIO_Pin_Configure_t *Pin_Config )
{
	
	     Enable_Clock_GPIO(GPIOx);
	    
		
			/********************pin is input************************/
			if(Pin_Config->GPIO_MODE==GPIO_MODE_OUTPUT) 
	    {
						GPIOx->GPIODIR |=(1<<(Pin_Config->GPIO_Pin_Number)); //MAKE Pin number AS OUTPUT PIN 
					
				
						if(Pin_Config->GPIO_OUTPUT_SPEED==GPIO_OUTPUT_SPEED_2mA)//GPIO 2-mA Drive Select (GPIODR2R)
						{
							GPIOx->GPIODR2R |=(1<<Pin_Config->GPIO_Pin_Number);
						}
						else if(Pin_Config->GPIO_OUTPUT_SPEED==GPIO_OUTPUT_SPEED_4mA)//GPIO 2-mA Drive Select (GPIODR4R)
						{
								GPIOx->GPIODR4R |=(1<<Pin_Config->GPIO_Pin_Number);
						}
						else if(Pin_Config->GPIO_OUTPUT_SPEED==GPIO_OUTPUT_SPEED_8mA)//GPIO 2-mA Drive Select (GPIODR8R)
						{
								GPIOx->GPIODR8R |=(1<<Pin_Config->GPIO_Pin_Number);
						}
			}
			
			/********************pin is input************************/
			else if(Pin_Config->GPIO_MODE==GPIO_MODE_INPUT)
			{
						GPIOx->GPIODIR &=~(1<<(Pin_Config->GPIO_Pin_Number)); //MAKE Pin number AS input PIN 
						
						if(Pin_Config->GPIO_PullUp==GPIO_PullUp_Enable)
						{
							GPIOx->GPIOPUR = 0x11; // enable pullup resistors on PF4,PF0    
						}					
		 }
				
		GPIOx->GPIODEN |=(1<<(Pin_Config->GPIO_Pin_Number)); //The digital functions for the corresponding pin are enabled
	

}


/**=================================================================
 * @Fn -                    -MCAL_GPIO_Write_Pin
 * @brief -                 -Initialize the GPIOx PINy according specified parameters in PinConfig
 * @param [in] -            -GPIOx : where x can be (A..F depending on device used)
 * @param [in] -            -PinConfig pointer to a GPIO_Pin_Configure_t structure that contains
 * @retval -                -none
 * note -                   -TivaC MCU has GPIO A,B,C,D,E,F Modules
 */
/**================================================================= */
void MCAL_GPIO_Write_Pin( GPIO_TypeDef *GPIOx , uint8_t Pin_Number ,Pin_status Value)
{
	if(Value == Pin_Low)
	{
				 GPIOF_DATA_REG &=~(1<<Pin_Number);
	}
	else if(Value == Pin_High)
	{
		 GPIOF_DATA_REG |=(1<<Pin_Number);
	}
}

/**=================================================================
 * @Fn -                    -MCAL_GPIO_Read_Pin
 * @brief -                 -Read Specific PIN
 * @param [in] -            -GPIOx : where x can be (A..F)
 * @param [in] -            -PinNumber :
 * @retval -                -the input pin value (tow values based on Pin_status enum)
 * note -                   -none
 */
/**================================================================= */
Pin_status MCAL_GPIO_Read_Pin( GPIO_TypeDef *GPIOx , uint8_t Pin_Number)
{
	if( ((GPIOF_DATA_REG & (1<<Pin_Number))>>Pin_Number)== Pin_Low)
	{
				 return Pin_Low;
	}
	else if( (GPIOF_DATA_REG & (1<<Pin_Number)>>Pin_Number) == Pin_High )
	{
		  return Pin_High;
	}
}

/**=================================================================
 * @Fn -                    -MCAL_GPIO_Write_Port
 * @brief -                 -Write on specific port
 * @param [in] -            -GPIOx : where x can be (A..F)
 * @param [in] -            -Vlaue to write on this port
 * @retval -                -none
 * note -                   -none
 */
/**================================================================= */
void MCAL_GPIO_Write_Port( GPIO_TypeDef *GPIOx ,Port_status Value)
{
	GPIOF_DATA_REG = (uint8_t) Value;
}


/**=================================================================
 * @Fn -                    -MCAL_GPIO_Read_Port
 * @brief -                 -Read Specific port
 * @param [in] -            -GPIOx : where x can be (A..F)
 * @param [in] -            -Vlaue to write on this port
 * @retval -                -none
 * note -                   -none
 */
/**================================================================= */
uint8_t MCAL_GPIO_Read_Port( GPIO_TypeDef *GPIOx)
{
	return  (uint8_t) GPIOF_DATA_REG;
}


/**=================================================================
 * @Fn -                    -MCAL_GPIO_Toggle_Pin
 * @brief -                 -toggle specific pin
 * @param [in] -            -GPIOx : where x can be (A..F)
* @param [in] -             -Pin_Number : pin number which you want toggle it this ref based on @ref GPIO_PINS_define
 * @retval -                -none
 * note -                   -none
 */
/**================================================================= */
void MCAL_GPIO_Toggle_Pin(GPIO_TypeDef *GPIOx , uint8_t Pin_Number)
{
	GPIOF_DATA_REG ^=(1<<Pin_Number);
}

/**=================================================================
 * @Fn -                    -MCAL_GPIO_Toggle_Port
 * @brief -                 -toggle specific port
 * @param [in] -            -GPIOx : where x can be (A..F)
 * @retval -                -none
 * note -                   -none
 */
/**================================================================= */
void MCAL_GPIO_Toggle_Port(GPIO_TypeDef *GPIOx)
{
	GPIOF_DATA_REG ^=(0xFF);
}


/**=================================================================
 * @Fn -                    -MCAL_GPIO_Lock_Port
 * @brief -                 -Writing 0x4C4F.434B to the GPIOLOCK register unlocks the GPIOCR registe
 * @param [in] -            -GPIOx : where x can be (A..F) , which the port i want to lock it
 * @retval -                -none
 * note -                   -none
 */
/**================================================================= */
void MCAL_GPIO_Lock_Port(GPIO_TypeDef *GPIOx)
{
  GPIOx->GPIOLOCK = GPIO_LOCK_KEY ;
}

/**=================================================================
 * @Fn -                    -MCAL_GPIO_UnLock_Port
 * @brief -                 -Writing any other value to the GPIOLOCK register re-enables the locked state
 * @param [in] -            -GPIOx : where x can be (A..F) , which the port i want to UnLock it
 * @retval -                -none
 * note -                   -none
 */
/**================================================================= */
void MCAL_GPIO_UnLock_Port(GPIO_TypeDef *GPIOx)
{
	  GPIOx->GPIOLOCK = GPIO_UnLOCK_KEY ;
}


/*==============================================================*/
/*****************MCAL_GPIO_EXTI_APIs Definations***************/
/*==============================================================*/



void MCAL_GPIO_EXTI_Init(GPIO_TypeDef *GPIOx ,uint8_t Pin_number ,void(*P_IRQ_CALLBACK)(void))
{

  GPIO_Pin_Configure_t Pin_cfg;
	Pin_cfg.GPIO_MODE = GPIO_MODE_INPUT;
	Pin_cfg.GPIO_PullUp=GPIO_PullUp_Enable;
	Pin_cfg.GPIO_Pin_Number = Pin_number;
	
	MCAL_GPIO_Init(GPIOx,&Pin_cfg);
	
	Enable_NVIC_GPIO_IRQ(GPIOx);
	
	gP_IRQ_CALLBACK=P_IRQ_CALLBACK;
	
	/*The GPIOIM register is the interrupt mask register. Setting a bit in the GPIOIM register allows
	interrupts that are generated by the corresponding pin to be sent to the interrupt controller on the
	combined interrupt signal*/
	GPIOx->GPIOIM |=(1<<Pin_number); 
	
	/*The GPIOIS register is the interrupt sense register. Setting a bit in the GPIOIS register configures
	the corresponding pin to detect levels, while clearing a bit configures the corresponding pin to detect
	edges. All bits are cleared by a reset.*/
	
	GPIOx->GPIOIS |=(1<<Pin_number);//The level on the corresponding pin is detected (level-sensitive).
	
	/*The GPIOIEV register is the interrupt event register. Setting a bit in the GPIOIEV register configures
	the corresponding pin to detect rising edges or high levels, depending on the corresponding bit
	value in the GPIO Interrupt Sense (GPIOIS) register*/
	
	GPIOx->GPIOIEV |=(1<<Pin_number); //A rising edge or a High level on the corresponding pin triggers an interrupt
}





/*==============================================================*/
/*********************************ISR****************************/
/*==============================================================*/
void GPIOF_Handler(void)
{
	//gP_IRQ_CALLBACK(); //Set The C Function() , this function will be send from app layer by user
}
















