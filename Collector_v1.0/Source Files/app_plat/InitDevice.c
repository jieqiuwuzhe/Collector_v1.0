//=========================================================
// src/InitDevice.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!
//=========================================================

// USER INCLUDES
#include "InitDevice.h"

// USER PROTOTYPES
// USER FUNCTIONS

// $[Library includes]
#include "../../Header Files/app_plat/bsp.h"
// [Library includes]$

//==============================================================================
// enter_DefaultMode_from_RESET
//==============================================================================
extern void enter_DefaultMode_from_RESET(void) {
	// $[Config Calls]
	HFXO_enter_DefaultMode_from_RESET();
	LFXO_enter_DefaultMode_from_RESET();
	CMU_enter_DefaultMode_from_RESET();
	ADC0_enter_DefaultMode_from_RESET();
	DMA_enter_DefaultMode_from_RESET();
	RTC_enter_DefaultMode_from_RESET();
	USART0_enter_DefaultMode_from_RESET();
	USART2_enter_DefaultMode_from_RESET();
	UART0_enter_DefaultMode_from_RESET();
	LEUART0_enter_DefaultMode_from_RESET();
	WDOG_enter_DefaultMode_from_RESET();
	I2C0_enter_DefaultMode_from_RESET();
	TIMER0_enter_DefaultMode_from_RESET();
	TIMER1_enter_DefaultMode_from_RESET();
	TIMER2_enter_DefaultMode_from_RESET();
	LETIMER0_enter_DefaultMode_from_RESET();
	PORTIO_enter_DefaultMode_from_RESET();
	// [Config Calls]$

}

//================================================================================
// HFXO_enter_DefaultMode_from_RESET
//================================================================================
extern void HFXO_enter_DefaultMode_from_RESET(void) {

}

//================================================================================
// LFXO_enter_DefaultMode_from_RESET
//================================================================================
extern void LFXO_enter_DefaultMode_from_RESET(void) {

	// $[Use oscillator source]
	CMU->CTRL = (CMU->CTRL & ~_CMU_CTRL_LFXOMODE_MASK) | CMU_CTRL_LFXOMODE_XTAL;
	// [Use oscillator source]$

	// $[LFXO Boost Percent]
	CMU->CTRL = (CMU->CTRL & ~_CMU_CTRL_LFXOBOOST_MASK)
			| CMU_CTRL_LFXOBOOST_100PCENT;
	// [LFXO Boost Percent]$

	// $[REDLFXO Boost]
	// [REDLFXO Boost]$

}

//================================================================================
// CMU_enter_DefaultMode_from_RESET
//================================================================================
extern void CMU_enter_DefaultMode_from_RESET(void) {

	//外部32.768K保留
	CMU_OscillatorEnable(cmuOsc_LFXO, true, true);

	//关闭外部高频晶振
	CMU_OscillatorEnable(cmuOsc_HFXO, false, true);

	//HFRCO设置成14M
	CMU_HFRCOBandSet(cmuHFRCOBand_14MHz);

	/* Select LFXO as clock source for LFACLK */
	CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO); //LFA采用外部低频晶振

	/* Using HFXO as high frequency clock, HFCLK */
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFRCO);//HFCLK采用高频RC

	//HFPER不分频，直接继承14M
	CMU_ClockDivSet(cmuClock_HFPER, cmuClkDiv_1);

	CMU_ClockDivSet(cmuClock_CORE, cmuClkDiv_1);

	/* Enable peripheral clock */
	CMU_ClockEnable(cmuClock_HFPER, true);

	CMU_ClockEnable(cmuClock_CORE, true);

	// $[LF clock tree setup]
	/* Enable LF clocks */
	CMU_ClockEnable(cmuClock_CORELE, true);
	CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO);
	CMU_ClockSelectSet(cmuClock_LFB, cmuSelect_LFXO);
	// [LF clock tree setup]$

	// $[Peripheral Clock enables]
	/* Enable clock for ADC0 */
	CMU_ClockEnable(cmuClock_ADC0, true);

	/* Enable clock for DMA */
	CMU_ClockEnable(cmuClock_DMA, true);

	/* Enable clock for I2C0 */
	CMU_ClockEnable(cmuClock_I2C0, true);

	/* Enable clock for LETIMER0 */
	CMU_ClockEnable(cmuClock_LETIMER0, true);

	/* Enable clock for LEUART0 */
	CMU_ClockEnable(cmuClock_LEUART0, true);

	/* Enable clock for RTC */
	CMU_ClockEnable(cmuClock_RTC, true);

	/* Enable clock for TIMER0 */
	CMU_ClockEnable(cmuClock_TIMER0, true);

	/* Enable clock for TIMER1 */
	CMU_ClockEnable(cmuClock_TIMER1, true);

	/* Enable clock for TIMER2 */
	CMU_ClockEnable(cmuClock_TIMER2, true);

	/* Enable clock for UART0 */
	CMU_ClockEnable(cmuClock_UART0, true);

	/* Enable clock for USART0 */
	CMU_ClockEnable(cmuClock_USART0, true);

	/* Enable clock for USART2 */
	CMU_ClockEnable(cmuClock_USART2, true);

	/* Enable clock for GPIO by default */
	CMU_ClockEnable(cmuClock_GPIO, true);

	// [Peripheral Clock enables]$

}

//================================================================================
// ADC0_enter_DefaultMode_from_RESET
//================================================================================
extern void ADC0_enter_DefaultMode_from_RESET(void) {

	// $[ADC_Init]
	ADC_Init_TypeDef init = ADC_INIT_DEFAULT;
	ADC_InitScan_TypeDef scanInit = ADC_INITSCAN_DEFAULT;

	init.ovsRateSel = false;//关闭过采样
	init.timebase = ADC_TimebaseCalc(0);
	init.prescale = ADC_PrescaleCalc(7000000, 0);

	ADC_Init(ADC0, &init);
	// [ADC_Init]$

	// $[ADC_InitScan]
	scanInit.reference = adcRefVDD;//3.31V
	scanInit.input     = ADC_SCANCTRL_INPUTMASK_CH4 |	//轮询通道CH4、CH5、CH6(PD4\PD5\PD6)
	                     ADC_SCANCTRL_INPUTMASK_CH5 |
	                     ADC_SCANCTRL_INPUTMASK_CH6;
	scanInit.resolution = adcRes12Bit;//12位分辨率
	// [ADC_InitScan]$
	ADC_InitScan(ADC0, &scanInit);

}


//================================================================================
// DMA_enter_DefaultMode_from_RESET
//================================================================================

extern void DMA_enter_DefaultMode_from_RESET(void) {
	DMA_Init_TypeDef       dmaInit;
	DMA_CfgDescr_TypeDef   descrCfg;
	DMA_CfgChannel_TypeDef chnlCfg;

	/* DMA控制器配置 */
	dmaInit.hprot        = 0;
	dmaInit.controlBlock = dmaControlBlock;
	DMA_Init(&dmaInit);

	/* DMA通道配置 */
	chnlCfg.highPri   = false;
	chnlCfg.enableInt = false;
	chnlCfg.select    = DMAREQ_ADC0_SCAN;
	chnlCfg.cb        = NULL;
	DMA_CfgChannel(DMA_CHANNEL, &chnlCfg);

	/* DMA通道描述符配置 */
	descrCfg.dstInc  = dmaDataInc4;
	descrCfg.srcInc  = dmaDataIncNone;
	descrCfg.size    = dmaDataSize4;
	descrCfg.arbRate = dmaArbitrate1;
	descrCfg.hprot   = 0;
	DMA_CfgDescr(DMA_CHANNEL, true, &descrCfg);
}

//================================================================================
// ACMP0_enter_DefaultMode_from_RESET
//================================================================================
extern void ACMP0_enter_DefaultMode_from_RESET(void) {

	// $[ACMP Initialization]
	// [ACMP Initialization]$

	// $[ACMP Channel config]
	// [ACMP Channel config]$

}

//================================================================================
// ACMP1_enter_DefaultMode_from_RESET
//================================================================================
extern void ACMP1_enter_DefaultMode_from_RESET(void) {

	// $[ACMP Initialization]
	// [ACMP Initialization]$

	// $[ACMP Channel config]
	// [ACMP Channel config]$

}

//================================================================================
// DAC0_enter_DefaultMode_from_RESET
//================================================================================
extern void DAC0_enter_DefaultMode_from_RESET(void) {

	// $[DAC Initialization]
	// [DAC Initialization]$

	// $[DAC Channel 0 config]
	// [DAC Channel 0 config]$

	// $[DAC Channel 1 config]
	// [DAC Channel 1 config]$

}

//================================================================================
// RTC_enter_DefaultMode_from_RESET
//================================================================================
extern void RTC_enter_DefaultMode_from_RESET(void) {

	// $[RTC_Init]
	RTC_Init_TypeDef init = RTC_INIT_DEFAULT;

	init.debugRun = 0;
	init.comp0Top = 1;

	RTC_Init(&init);
	// [RTC_Init]$

}

//================================================================================
// USART0_enter_DefaultMode_from_RESET-WEIHU
//================================================================================
extern void USART0_enter_DefaultMode_from_RESET(void) {

	// $[USART_InitAsync]
	USART_InitAsync_TypeDef initasync = USART_INITASYNC_DEFAULT;

	initasync.baudrate = 115200;
	initasync.databits = usartDatabits8;
	initasync.parity = usartNoParity;
	initasync.stopbits = usartStopbits1;
	initasync.oversampling = usartOVS16;
#if defined( USART_INPUT_RXPRS ) && defined( USART_CTRL_MVDIS )
	initasync.mvdis = 0;
	initasync.prsRxEnable = 0;
	initasync.prsRxCh = 0;
#endif

	USART_InitAsync(USART0, &initasync);
	// [USART_InitAsync]$

	// $[USART_InitSync]
	// [USART_InitSync]$

	// $[USART_InitPrsTrigger]
	USART_PrsTriggerInit_TypeDef initprs = USART_INITPRSTRIGGER_DEFAULT;

	initprs.rxTriggerEnable = 0;
	initprs.txTriggerEnable = 0;
	initprs.prsTriggerChannel = usartPrsTriggerCh0;

	USART_InitPrsTrigger(USART0, &initprs);
	// [USART_InitPrsTrigger]$

}

//================================================================================
// USART1_enter_DefaultMode_from_RESET
//================================================================================
extern void USART1_enter_DefaultMode_from_RESET(void) {

	// $[USART_InitAsync]
	// [USART_InitAsync]$

	// $[USART_InitSync]
	// [USART_InitSync]$

	// $[USART_InitPrsTrigger]
	// [USART_InitPrsTrigger]$

}

//================================================================================
// USART2_enter_DefaultMode_from_RESET-RF4460
//================================================================================
extern void USART2_enter_DefaultMode_from_RESET(void) {

	// $[USART_InitAsync]
	USART_InitSync_TypeDef rfinit = USART_INITSYNC_DEFAULT;

	rfinit.baudrate = 1000000;
	rfinit.msbf = 1;

	USART_InitSync(USART2, &rfinit);

	USART2->ROUTE =USART_ROUTE_CLKPEN |  USART_ROUTE_RXPEN | USART_ROUTE_TXPEN | USART_ROUTE_LOCATION_LOC1 ;

	GPIO_PinModeSet(SPI_MOSI_PORT, SPI_MOSI_PIN, gpioModePushPull, 1);
	GPIO_PinModeSet(SPI_MISO_PORT, SPI_MISO_PIN, gpioModeInput, 0);
	GPIO_PinModeSet(SPI_SCLK_PORT, SPI_SCLK_PIN, gpioModePushPull, 1);
	GPIO_PinModeSet(SPI_CS_PORT, SPI_CS_PIN, gpioModePushPull, 1);
	GPIO_PinModeSet(RF_SDN_PORT, RF_SDN_PIN, gpioModePushPull, 0);
	GPIO_PinModeSet(RF_nIRQ_PORT, RF_nIRQ_PIN, gpioModeInput, 0);


	// [USART_InitAsync]$
}

//================================================================================
// UART0_enter_DefaultMode_from_RESET-GPRS
//================================================================================
extern void UART0_enter_DefaultMode_from_RESET(void) {

	// $[UART_InitAsync]
	USART_InitAsync_TypeDef initasync = USART_INITASYNC_DEFAULT;

	initasync.baudrate = 9600;

	USART_InitAsync(UART0, &initasync);
	// [UART_InitAsync]$
	NVIC_ClearPendingIRQ(UART0_RX_IRQn);
	NVIC_EnableIRQ(UART0_RX_IRQn);
	NVIC_EnableIRQ(UART0_TX_IRQn);
	UART0->IEN = UART_IEN_TXC | UART_IEN_RXDATAV;//打开发送和接受中断

	GPIO_PinModeSet(TX_GPRS_PORT, TX_GPRS_PIN, gpioModePushPull, 1);
	GPIO_PinModeSet(RX_GPRS_PORT, RX_GPRS_PIN, gpioModeInputPull, 1);

	UART0->ROUTE |=  UART_ROUTE_TXPEN | UART_ROUTE_RXPEN | UART_ROUTE_LOCATION_LOC0;
	// [USART_InitPrsTrigger]$

}

//================================================================================
// LEUART0_enter_DefaultMode_from_RESET-GPS
//================================================================================
extern void LEUART0_enter_DefaultMode_from_RESET(void) {

	// $[LEUART0 initialization]
	LEUART_Init_TypeDef initleuart = LEUART_INIT_DEFAULT;

	initleuart.enable = leuartEnable;
	initleuart.baudrate = 9600;
	initleuart.databits = leuartDatabits8;
	initleuart.parity = leuartNoParity;
	initleuart.stopbits = leuartStopbits1;

	LEUART_Reset(LEUART0);
	LEUART_Init(LEUART0, &initleuart);

	/* Enable GPIO for LEUART0.  */
	GPIO_PinModeSet(TX_GPS_PORT, TX_GPS_PIN, gpioModePushPull,   1);
	GPIO_PinModeSet(RX_GPS_PORT, RX_GPS_PIN, gpioModeInputPull, 1);

	NVIC_ClearPendingIRQ(LEUART0_IRQn);
	NVIC_EnableIRQ(LEUART0_IRQn);
	LEUART0->IEN = LEUART_IEN_RXDATAV | LEUART_IEN_TXC ; //打开接收中断与发送完成中断

	LEUART0->ROUTE = LEUART_ROUTE_TXPEN | LEUART_ROUTE_RXPEN | LEUART_ROUTE_LOCATION_LOC2;

	// [LEUART0 initialization]$

}

//================================================================================
// LEUART1_enter_DefaultMode_from_RESET
//================================================================================
extern void LEUART1_enter_DefaultMode_from_RESET(void) {

	// $[LEUART1 initialization]
	// [LEUART1 initialization]$

}

//================================================================================
// VCMP_enter_DefaultMode_from_RESET
//================================================================================
extern void VCMP_enter_DefaultMode_from_RESET(void) {
}

//================================================================================
// WDOG_enter_DefaultMode_from_RESET
//================================================================================
extern void WDOG_enter_DefaultMode_from_RESET(void) {

	// $[CMU_ClockEnable]
	/* Enable LE clock for CPU access to BURTC registers */
	CMU_ClockEnable(cmuClock_CORELE, true);
	// [CMU_ClockEnable]$

	// $[CMU_OscillatorEnable]
	CMU_OscillatorEnable(cmuOsc_LFRCO, true, true);
	// [CMU_OscillatorEnable]$

	// $[WDOG_Init]
	WDOG_Init_TypeDef watchdogInit = WDOG_INIT_DEFAULT;

	watchdogInit.debugRun = 0;
	watchdogInit.clkSel = wdogClkSelULFRCO;//1K频率
	watchdogInit.perSel = wdogPeriod_2k; //2K时钟周期，大约2s
	watchdogInit.swoscBlock = 0;
	watchdogInit.em4Block = 0;
	watchdogInit.lock = 0;
	watchdogInit.em3Run = 0;
	watchdogInit.em2Run = 0;
	WDOG_Init(&watchdogInit);
	// [WDOG_Init]$

}

//================================================================================
// I2C0_enter_DefaultMode_from_RESET
//================================================================================
extern void I2C0_enter_DefaultMode_from_RESET(void) {

	  /* Using  (SDA) and  (SCL) */
	  GPIO_PinModeSet(RTCSCL_PORT,  RTCSCL_PIN, gpioModeWiredAndPullUpFilter, 1);
	  GPIO_PinModeSet(RTCSDA_PORT, RTCSDA_PIN, gpioModeWiredAndPullUpFilter, 1);

	// $[I2C0 initialization]
	I2C_Init_TypeDef init = I2C_INIT_DEFAULT;

	  /* Enable pins at location 1 */
	 I2C0->ROUTE = I2C_ROUTE_SDAPEN | I2C_ROUTE_SCLPEN | I2C_ROUTE_LOCATION_LOC0 ;

	I2C_Init(I2C0, &init);
	// [I2C0 initialization]$

}

//================================================================================
// TIMER0_enter_DefaultMode_from_RESET
//================================================================================
extern void TIMER0_enter_DefaultMode_from_RESET(void) {

	gSystemInfo.ms_tick = 0;

	 TIMER_Init_TypeDef timerInit =
	  {
	    .enable     = false,
	    .debugRun   = true,
	    .prescale   = timerPrescale2,//2分频，7M
	    .clkSel     = timerClkSelHFPerClk,
	    .fallAction = timerInputActionNone,
	    .riseAction = timerInputActionNone,
	    .mode       = timerModeUp,
	    .dmaClrAct  = false,
	    .quadModeX4 = false,
	    .oneShot    = false,
	    .sync       = false,
	  };

	 TIMER_IntEnable(TIMER0, TIMER_IF_OF);

	 TIMER_TopSet(TIMER0, 7000);//7M，每7K次代表1ms

	 TIMER_Init(TIMER0, &timerInit);

	 NVIC_EnableIRQ(TIMER0_IRQn);
}

//================================================================================
// TIMER1_enter_DefaultMode_from_RESET
//================================================================================
extern void TIMER1_enter_DefaultMode_from_RESET(void) {

	// $[TIMER1 initialization]
	TIMER_Init_TypeDef init = TIMER_INIT_DEFAULT;

	init.enable = 0;//初始化完成后不使能
	init.debugRun = 1;
	init.clkSel = timerClkSelHFPerClk;//14M
	init.prescale = timerPrescale2;   //2分频,7M
	init.fallAction = timerInputActionNone;
	init.riseAction = timerInputActionNone;
	init.mode = timerModeUp;
	init.quadModeX4 = 0;
	init.dmaClrAct = 0;
	init.oneShot = 0;
	init.sync = 0;

	// [TIMER1 initialization]$

	// $[TIMER1 CC0 init]
	TIMER_InitCC_TypeDef initCC0 = TIMER_INITCC_DEFAULT;

	initCC0.edge = timerEdgeBoth;
	initCC0.mode = timerCCModePWM;
	initCC0.eventCtrl = timerEventEveryEdge;
	initCC0.cofoa = timerOutputActionNone;
	initCC0.cufoa = timerOutputActionNone;
	initCC0.cmoa = timerOutputActionToggle;
	initCC0.prsInput = false;
	initCC0.filter = false;
	initCC0.coist = false;
	initCC0.outInvert = false;

	TIMER_InitCC(TIMER1, 0, &initCC0);
	// [TIMER1 CC0 init]$

	/* Route CC0 to location 0 (PC13) and enable pin */
	TIMER1->ROUTE |= (TIMER_ROUTE_CC0PEN | TIMER_ROUTE_LOCATION_LOC0);

	/* Set Top Value */
	TIMER_TopSet(TIMER1, 7000000/PWM_FREQ); //PWM频率设定，此处7M是timer1时钟频率

	/* Set compare value starting at 0 - it will be incremented in the interrupt handler */
	TIMER_CompareBufSet(TIMER1, 0, ((7000000/PWM_FREQ)*50/100));

	/* Enable overflow interrupt */
//	TIMER_IntEnable(TIMER1, TIMER_IF_OF);

	/* Enable TIMER0 interrupt vector in NVIC */
//	NVIC_EnableIRQ(TIMER1_IRQn);

	TIMER_Init(TIMER1, &init);


	TIMER1->CMD = 0b01;

}

//================================================================================
// TIMER2_enter_DefaultMode_from_RESET
//================================================================================
extern void TIMER2_enter_DefaultMode_from_RESET(void) {


}

//================================================================================
// LETIMER0_enter_DefaultMode_from_RESET
//================================================================================
extern void LETIMER0_enter_DefaultMode_from_RESET(void) {

}

//================================================================================
// PCNT0_enter_DefaultMode_from_RESET
//================================================================================
extern void PCNT0_enter_DefaultMode_from_RESET(void) {

}

//================================================================================
// PCNT1_enter_DefaultMode_from_RESET
//================================================================================
extern void PCNT1_enter_DefaultMode_from_RESET(void) {

}

//================================================================================
// PCNT2_enter_DefaultMode_from_RESET
//================================================================================
extern void PCNT2_enter_DefaultMode_from_RESET(void) {

}

//================================================================================
// PRS_enter_DefaultMode_from_RESET
//================================================================================
extern void PRS_enter_DefaultMode_from_RESET(void) {

}

//================================================================================
// EBI_enter_DefaultMode_from_RESET
//================================================================================
extern void EBI_enter_DefaultMode_from_RESET(void) {

}

//================================================================================
// PORTIO_enter_DefaultMode_from_RESET
//================================================================================
extern void PORTIO_enter_DefaultMode_from_RESET(void) {


	// $[Port B Configuration]

	/* Pin PB3 is configured to Push-pull */
	GPIO->P[1].MODEL = (GPIO->P[1].MODEL & ~_GPIO_P_MODEL_MODE3_MASK)
			| GPIO_P_MODEL_MODE3_PUSHPULL;

	/* Pin PB4 is configured to Input enabled */
	GPIO->P[1].MODEL = (GPIO->P[1].MODEL & ~_GPIO_P_MODEL_MODE4_MASK)
			| GPIO_P_MODEL_MODE4_INPUT;

	/* Pin PB5 is configured to Push-pull */
	GPIO->P[1].MODEL = (GPIO->P[1].MODEL & ~_GPIO_P_MODEL_MODE5_MASK)
			| GPIO_P_MODEL_MODE5_PUSHPULL;

	/* Pin PB6 is configured to Push-pull */
	GPIO->P[1].MODEL = (GPIO->P[1].MODEL & ~_GPIO_P_MODEL_MODE6_MASK)
			| GPIO_P_MODEL_MODE6_PUSHPULL;
	// [Port B Configuration]$

	// $[Port C Configuration]

	/* Pin PC0 is configured to Push-pull */
	GPIO->P[2].MODEL = (GPIO->P[2].MODEL & ~_GPIO_P_MODEL_MODE0_MASK)
			| GPIO_P_MODEL_MODE0_PUSHPULL;

	/* Pin PC1 is configured to Input enabled */
	GPIO->P[2].MODEL = (GPIO->P[2].MODEL & ~_GPIO_P_MODEL_MODE1_MASK)
			| GPIO_P_MODEL_MODE1_INPUT;

	/* Pin PC2 is configured to Push-pull */
	GPIO->P[2].MODEL = (GPIO->P[2].MODEL & ~_GPIO_P_MODEL_MODE2_MASK)
			| GPIO_P_MODEL_MODE2_PUSHPULL;

	/* Pin PC3 is configured to Input enabled */
	GPIO->P[2].MODEL = (GPIO->P[2].MODEL & ~_GPIO_P_MODEL_MODE3_MASK)
			| GPIO_P_MODEL_MODE3_INPUT;

	/* Pin PC4 is configured to Push-pull */
	GPIO->P[2].MODEL = (GPIO->P[2].MODEL & ~_GPIO_P_MODEL_MODE4_MASK)
			| GPIO_P_MODEL_MODE4_PUSHPULL;

	/* Pin PC5 is configured to Push-pull */
	GPIO->P[2].MODEL = (GPIO->P[2].MODEL & ~_GPIO_P_MODEL_MODE5_MASK)
			| GPIO_P_MODEL_MODE5_PUSHPULL;

	/* Pin PC10 is configured to Push-pull */
	GPIO->P[2].MODEH = (GPIO->P[2].MODEH & ~_GPIO_P_MODEH_MODE10_MASK)
			| GPIO_P_MODEH_MODE10_PUSHPULL;

	/* Pin PC14 is configured to Push-pull */
	GPIO->P[2].MODEH = (GPIO->P[2].MODEH & ~_GPIO_P_MODEH_MODE14_MASK)
			| GPIO_P_MODEH_MODE14_PUSHPULL;
	// [Port C Configuration]$

	// $[Port D Configuration]
	// [Port D Configuration]$

	// $[Port E Configuration]

	/* Pin PE10 is configured to Push-pull */
	GPIO->P[4].MODEH = (GPIO->P[4].MODEH & ~_GPIO_P_MODEH_MODE10_MASK)
			| GPIO_P_MODEH_MODE10_PUSHPULL;

	/* Pin PE11 is configured to Input enabled */
	GPIO->P[4].MODEH = (GPIO->P[4].MODEH & ~_GPIO_P_MODEH_MODE11_MASK)
			| GPIO_P_MODEH_MODE11_INPUT;

	/* Pin PE14 is configured to Push-pull */
	GPIO->P[4].MODEH = (GPIO->P[4].MODEH & ~_GPIO_P_MODEH_MODE14_MASK)
			| GPIO_P_MODEH_MODE14_PUSHPULL;

	/* Pin PE15 is configured to Input enabled */
	GPIO->P[4].MODEH = (GPIO->P[4].MODEH & ~_GPIO_P_MODEH_MODE15_MASK)
			| GPIO_P_MODEH_MODE15_INPUT;
	// [Port E Configuration]$

	// $[Port F Configuration]

	/* Pin PF6 is configured to Push-pull */
	GPIO->P[5].MODEL = (GPIO->P[5].MODEL & ~_GPIO_P_MODEL_MODE6_MASK)
			| GPIO_P_MODEL_MODE6_PUSHPULL;

	/* Pin PF7 is configured to Input enabled */
	GPIO->P[5].MODEL = (GPIO->P[5].MODEL & ~_GPIO_P_MODEL_MODE7_MASK)
			| GPIO_P_MODEL_MODE7_INPUT;
	// [Port F Configuration]$

	// $[Route Configuration]

	/* Module GPIO is configured to location 1 */
	GPIO->ROUTE = (GPIO->ROUTE & ~_GPIO_ROUTE_SWLOCATION_MASK)
			| GPIO_ROUTE_SWLOCATION_LOC1;

	/* Enable signals SWO */
	GPIO->ROUTE |= GPIO_ROUTE_SWOPEN;

	/* Enable signals SCL, SDA */
	I2C0->ROUTE |= I2C_ROUTE_SCLPEN | I2C_ROUTE_SDAPEN;

	/* Module LEUART0 is configured to location 2 */
	LEUART0->ROUTE = (LEUART0->ROUTE & ~_LEUART_ROUTE_LOCATION_MASK)
			| LEUART_ROUTE_LOCATION_LOC2;

	/* Enable signals RX, TX */
	LEUART0->ROUTE |= LEUART_ROUTE_RXPEN | LEUART_ROUTE_TXPEN;

	/* Enable signals RX, TX */
	UART0->ROUTE |= UART_ROUTE_RXPEN | UART_ROUTE_TXPEN;

	/* Enable signals RX, TX */
	USART0->ROUTE |= USART_ROUTE_RXPEN | USART_ROUTE_TXPEN;

	/* Module USART2 is configured to location 1 */
	USART2->ROUTE = (USART2->ROUTE & ~_USART_ROUTE_LOCATION_MASK)
			| USART_ROUTE_LOCATION_LOC1;

	/* Enable signals CLK, CS, RX, TX */
	USART2->ROUTE |= USART_ROUTE_CLKPEN | USART_ROUTE_CSPEN | USART_ROUTE_RXPEN
			| USART_ROUTE_TXPEN;
	// [Route Configuration]$

	  //PWM发生引脚
	  GPIO_PinModeSet(gpioPortC, 13, gpioModePushPull, 0);


	  //设置8025T的秒级脉冲引脚（PA15）为中断
	  GPIO_PinModeSet(gpioPortA, 15, gpioModeInput, 1);
	  //打开GPIO奇中断
	   NVIC_EnableIRQ(GPIO_ODD_IRQn);
	   //设置PA15为下降沿中断方式
	   GPIO_IntConfig(gpioPortA, 15, false, true, true);

	   //4460的GPIO2为下降沿中断
	   NVIC_EnableIRQ(GPIO_EVEN_IRQn);
	   GPIO_IntConfig(gpioPortC, 2, false, true, true);

}

