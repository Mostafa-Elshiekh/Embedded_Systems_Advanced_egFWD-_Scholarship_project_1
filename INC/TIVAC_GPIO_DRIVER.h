#include "TIVAC_DEVICE_HEADER.h"

#define GPIO_PORTF_DATA_RD      (*(( volatile unsigned long *)0x40025s040)) 
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
	

	
/*==========================================================*/
/*Base Addresses For PERIPHERALS REGISTERS (GPIO)*/
/*==========================================================*/
typedef struct
{
    volatile uint32_t GPIODATA[256];
    volatile uint32_t GPIODIR;
    volatile uint32_t GPIOIS;
    volatile uint32_t GPIOIBE;
    volatile uint32_t GPIOIEV;
    volatile uint32_t GPIOIM;
    volatile uint32_t GPIORIS;
    volatile uint32_t GPIOMIS;
    volatile uint32_t GPIOICR;
    volatile uint32_t GPIOAFSEL;
    uint32_t reserved2[55];
    volatile uint32_t GPIODR2R;
    volatile uint32_t GPIODR4R;
    volatile uint32_t GPIODR8R;
    volatile uint32_t GPIOODR;
    volatile uint32_t GPIOPUR;
    volatile uint32_t GPIOPDR;
    volatile uint32_t GPIOSLR;
    volatile uint32_t GPIODEN;
    volatile uint32_t GPIOLOCK;
    uint32_t GPIOCR;
    volatile uint32_t GPIOAMSEL;
    volatile uint32_t GPIOPCTL;
    volatile uint32_t GPIOADCCTL;
    volatile uint32_t GPIODMACTL;
    uint32_t reserved3[678];
    volatile uint32_t GPIOPeriphID4;
    volatile uint32_t GPIOPeriphID5;
    volatile uint32_t GPIOPeriphID6;
    volatile uint32_t GPIOPeriphID7;
    volatile uint32_t GPIOPeriphID0;
    volatile uint32_t GPIOPeriphID1;
    volatile uint32_t GPIOPeriphID2;
    volatile uint32_t GPIOPeriphID3;
    volatile uint32_t GPIOPCellID0;
    volatile uint32_t GPIOPCellID1;
    volatile uint32_t GPIOPCellID2;
    volatile uint32_t GPIOPCellID3;
}GPIO_TypeDef;



#define GPIOA                            ((GPIO_TypeDef*)(GPIO_PORT_A_BASE_ADD))
#define GPIOB                  					 ((GPIO_TypeDef*)(GPIO_PORT_B_BASE_ADD))
#define GPIOC                            ((GPIO_TypeDef*)(GPIO_PORT_C_BASE_ADD))
#define GPIOD                            ((GPIO_TypeDef*)(GPIO_PORT_D_BASE_ADD))
#define GPIOE                            ((GPIO_TypeDef*)(GPIO_PORT_E_BASE_ADD))
#define GPIOF                            ((GPIO_TypeDef*)(GPIO_PORT_F_BASE_ADD))


/*==========================================================*/
/***********************CLOCK ENABLE MACROS******************/
/*==========================================================*/
#define RCC_GPIOA_CLOCK_EN()             (SYSCT_RCGC_CLK_ENABLE |=(1<<0))
#define RCC_GPIOB_CLOCK_EN()             (SYSCT_RCGC_CLK_ENABLE |=(1<<1))
#define RCC_GPIOC_CLOCK_EN()             (SYSCT_RCGC_CLK_ENABLE |=(1<<2))
#define RCC_GPIOD_CLOCK_EN()             (SYSCT_RCGC_CLK_ENABLE |=(1<<3))
#define RCC_GPIOE_CLOCK_EN()             (SYSCT_RCGC_CLK_ENABLE |=(1<<4))
#define RCC_GPIOF_CLOCK_EN()             (SYSCT_RCGC_CLK_ENABLE |=(1<<5))




typedef struct
{
	uint8_t GPIO_Pin_Number;  // Specifies the GPIO pins to be configured.
	//This parameter must be set based on @ref GPIO_PINS_define
	
	uint8_t GPIO_MODE ;      // Specifies the operation mode for the selected pins
	//this parameter must be set based on @ref GPIO_MODE_define
	
	uint8_t GPIO_PullUp;// Specifies enable or disable pullup
	//this parameter must be set based on @ref GPIO_PullUp

	uint8_t GPIO_OUTPUT_SPEED; // Specifies speed for the selected pins.
	//This parameter can be set based on @ref GPIO_SPEED_define
	
}GPIO_Pin_Configure_t;



//@ref GPIO_PINS_define
#define PIN_0             			0 
#define PIN_1            			 	1 
#define PIN_2                   2 
#define PIN_3                   3
#define PIN_4                   4 
#define PIN_5                  	5
#define PIN_6                   6 
#define PIN_7                   7



//@ref GPIO_MODE_define
#define GPIO_MODE_INPUT         0        
#define GPIO_MODE_OUTPUT        1    

 //@ref GPIO_PullUp
#define GPIO_PullUp_Disable     0        
#define GPIO_PullUp_Enable      1    


//@ref GPIO_SPEED_define
#define GPIO_OUTPUT_SPEED_2mA   0
#define GPIO_OUTPUT_SPEED_4mA   1
#define GPIO_OUTPUT_SPEED_8mA   2


//Pin value
typedef enum{Pin_Low,Pin_High} Pin_status;

//Port value
typedef enum{Port_Low,Port_High} Port_status;

#define GPIO_LOCK_KEY          0x4C4F434B 
#define GPIO_UnLOCK_KEY        0x00 


/*==============================================================*/
/*******************MCAL_GPIO_APIs prototyps ********************/
/*==============================================================*/

void MCAL_GPIO_Init( GPIO_TypeDef *GPIOx , GPIO_Pin_Configure_t *Pin_Config );
void MCAL_GPIO_Write_Pin( GPIO_TypeDef *GPIOx , uint8_t Pin_Number ,Pin_status Value);
Pin_status MCAL_GPIO_Read_Pin( GPIO_TypeDef *GPIOx , uint8_t Pin_Number);
void MCAL_GPIO_Write_Port( GPIO_TypeDef *GPIOx ,Port_status Value);
uint8_t MCAL_GPIO_Read_Port( GPIO_TypeDef *GPIOx);
void MCAL_GPIO_Toggle_Pin( GPIO_TypeDef *GPIOx , uint8_t Pin_Number);
void MCAL_GPIO_Toggle_Port(GPIO_TypeDef *GPIOx);
void MCAL_GPIO_Lock_Port(GPIO_TypeDef *GPIOx);
void MCAL_GPIO_UnLock_Port(GPIO_TypeDef *GPIOx);


/*==============================================================*/
/**********************MCAL_GPIO_EXTI_APIs prototyps*************/
/*==============================================================*/
void MCAL_GPIO_EXTI_Init(GPIO_TypeDef *GPIOx ,uint8_t Pin_number ,void(* P_IRQ_CALLBACK)(void));































