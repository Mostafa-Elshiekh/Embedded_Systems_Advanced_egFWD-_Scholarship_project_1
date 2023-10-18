#include "TIVAC_DEVICE_HEADER.h"
#include "TIVAC_GPIO_DRIVER.h"



typedef struct
{
    volatile uint32_t GPTMCFG;
    volatile uint32_t GPTMTAMR;
    volatile uint32_t GPTMTBMR;
    volatile uint32_t GPTMCTL;
    volatile uint32_t GPTMSYNC;
    uint32_t reserved1;
    volatile uint32_t GPTMIMR;
    volatile uint32_t GPTMRIS;
    volatile uint32_t GPTMMIS;
    volatile uint32_t GPTMICR;
    volatile uint32_t GPTMTAILR;
    volatile uint32_t GPTMTBILR;
    volatile uint32_t GPTMTAMATCHR;
    volatile uint32_t GPTMTAMBTCHR;
    volatile uint32_t GPTMTAPR;
    volatile uint32_t GPTMTBPR;
    volatile uint32_t GPTMTAPMR;
    volatile uint32_t GPTMTBPMR;
    volatile uint32_t GPTMTAR;
    volatile uint32_t GPTMTBR;
    volatile uint32_t GPTMTAV;
    volatile uint32_t GPTMTBV;
    volatile uint32_t GPTMTCPD;
    volatile uint32_t GPTMTAPS;
    volatile uint32_t GPTMTBPS;
    volatile uint32_t GPTMTAPV;
    volatile uint32_t GPTMTBPV;
    uint32_t reserved2[918];
    volatile uint32_t GPTMPP;
}TIMER_TypeDef;




#define TIMER0                  ((TIMER_TypeDef*)(TIMER0_BASE_ADD))
#define TIMER1                  ((TIMER_TypeDef*)(TIMER1_BASE_ADD))
#define TIMER2                  ((TIMER_TypeDef*)(TIMER2_BASE_ADD))
#define TIMER3                  ((TIMER_TypeDef*)(TIMER3_BASE_ADD))
#define TIMER4                  ((TIMER_TypeDef*)(TIMER4_BASE_ADD))   
#define TIMER5                  ((TIMER_TypeDef*)(TIMER5_BASE_ADD))




typedef struct
{
	uint8_t TIMER_MODE;       // Specifies the TIEMR MODE (ons-shot or periodic) to be configured.
	//This parameter must be set based on @ref TIEMR_MODE
	
	uint8_t TIMER_USE;       // Specifies the TIEMR USE (individual or concatenated) to be configured.
	//This parameter must be set based on @ref TIEMR_USE
	
	uint8_t TIMER_COUNT_DIR;// Specifies the TIEMR COUNT DIRECTION (up or down) to be configured.
	//This parameter must be set based on @ref TIMER_COUNT_DIR
	
	uint8_t TIMER_PRESCALER;// Specifies the TIEMR PRESCALLER (value of prescaller ) to be configured.
	//This parameter must be set based on @ref TIMER_PRESCALER
	
	uint32_t TIMER_COUNTS_IN_mS; //you should pass this value in the application layer same in (up count or down)
	
	
	void(*P_IRQ_CALLBACK)(void); //Set The C Function() , this function will be send from app layer by user
	
}TIMER_CONFIGRATIONS;


//@ref TIEMR_MODE
#define TIEMR_MODE_ONE_SHOT        0
#define TIEMR_MODE_PERIODIC        1

//@ref TIEMR_USE
#define TIEMR_USE_INDIVIDUAL       0
#define TIEMR_USE_CONCATENATED     1

//@ref TIMER_COUNT_DIR
#define TIMER_COUNT_DIR_UP         0
#define TIMER_COUNT_DIR_DOWN       1


//@ref TIMER_PRESCALER
#define TIMER_PRESCALER_1           0
#define TIMER_PRESCALER_10          9
#define TIMER_PRESCALER_20         19
#define TIMER_PRESCALER_30         29
#define TIMER_PRESCALER_40         39
#define TIMER_PRESCALER_50         49
#define TIMER_PRESCALER_60         59
#define TIMER_PRESCALER_70         69
#define TIMER_PRESCALER_80         79
#define TIMER_PRESCALER_90         89
#define TIMER_PRESCALER_100        99
#define TIMER_PRESCALER_110       109
#define TIMER_PRESCALER_120       119
#define TIMER_PRESCALER_130       129
#define TIMER_PRESCALER_140       139
#define TIMER_PRESCALER_150       149
#define TIMER_PRESCALER_160       159
#define TIMER_PRESCALER_170       169
#define TIMER_PRESCALER_180       179
#define TIMER_PRESCALER_190       189
#define TIMER_PRESCALER_200       199
#define TIMER_PRESCALER_210       209
#define TIMER_PRESCALER_220       219
#define TIMER_PRESCALER_230       229
#define TIMER_PRESCALER_240       239
#define TIMER_PRESCALER_250       249
#define TIMER_PRESCALER_251       250
#define TIMER_PRESCALER_252       251
#define TIMER_PRESCALER_253       252
#define TIMER_PRESCALER_254       253
#define TIMER_PRESCALER_255       254
#define TIMER_PRESCALER_256       255






/*==========================================================*/
/********************CLOCK ENABLE MACROS*********************/
/*==========================================================*/
//Enable and provide a clock to 16/32-bit general-purpose timer module x in Run mode
#define RCC_TIMER0_CLOCK_EN()             (SYSCT_RCGCTIMER_CLK_ENABLE |=(1<<0)) 
#define RCC_TIMER1_CLOCK_EN()             (SYSCT_RCGCTIMER_CLK_ENABLE |=(1<<1)) 
#define RCC_TIMER2_CLOCK_EN()             (SYSCT_RCGCTIMER_CLK_ENABLE |=(1<<2)) 
#define RCC_TIMER3_CLOCK_EN()             (SYSCT_RCGCTIMER_CLK_ENABLE |=(1<<3)) 
#define RCC_TIMER4_CLOCK_EN()             (SYSCT_RCGCTIMER_CLK_ENABLE |=(1<<4)) 
#define RCC_TIMER5_CLOCK_EN()             (SYSCT_RCGCTIMER_CLK_ENABLE |=(1<<5)) 



/*==========================================================*/
/******************MCAL_TIMER_APIs prototyps*****************/
/*==========================================================*/

void MCAL_TIMER_Init(TIMER_TypeDef *TIMERx ,TIMER_CONFIGRATIONS * timer_config);
void MCAL_TIMER_START(TIMER_TypeDef *TIMERx);

























