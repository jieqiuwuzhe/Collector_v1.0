//=========================================================
// inc/InitDevice.h: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!
//=========================================================
#ifndef __INIT_DEVICE_H__
#define __INIT_DEVICE_H__

// USER CONSTANTS
// USER PROTOTYPES

// $[Mode Transition Prototypes]
extern void enter_DefaultMode_from_RESET(void);
// [Mode Transition Prototypes]$

// $[Config(Per-Module Mode)Transition Prototypes]
extern void HFXO_enter_DefaultMode_from_RESET(void);
extern void LFXO_enter_DefaultMode_from_RESET(void);
extern void CMU_enter_DefaultMode_from_RESET(void);
extern void ADC0_enter_DefaultMode_from_RESET(void);
extern void DMA_enter_DefaultMode_from_RESET();
extern void ACMP0_enter_DefaultMode_from_RESET(void);
extern void ACMP1_enter_DefaultMode_from_RESET(void);
extern void DAC0_enter_DefaultMode_from_RESET(void);
extern void RTC_enter_DefaultMode_from_RESET(void);
extern void USART0_enter_DefaultMode_from_RESET(void);
extern void USART1_enter_DefaultMode_from_RESET(void);
extern void USART2_enter_DefaultMode_from_RESET(void);
extern void UART0_enter_DefaultMode_from_RESET(void);
extern void LEUART0_enter_DefaultMode_from_RESET(void);
extern void LEUART1_enter_DefaultMode_from_RESET(void);
extern void VCMP_enter_DefaultMode_from_RESET(void);
extern void WDOG_enter_DefaultMode_from_RESET(void);
extern void I2C0_enter_DefaultMode_from_RESET(void);
extern void TIMER0_enter_DefaultMode_from_RESET(void);
extern void TIMER1_enter_DefaultMode_from_RESET(void);
extern void TIMER2_enter_DefaultMode_from_RESET(void);
extern void LETIMER0_enter_DefaultMode_from_RESET(void);
extern void PCNT0_enter_DefaultMode_from_RESET(void);
extern void PCNT1_enter_DefaultMode_from_RESET(void);
extern void PCNT2_enter_DefaultMode_from_RESET(void);
extern void PRS_enter_DefaultMode_from_RESET(void);
extern void EBI_enter_DefaultMode_from_RESET(void);
extern void PORTIO_enter_DefaultMode_from_RESET(void);
// [Config(Per-Module Mode)Transition Prototypes]$

// $[User-defined pin name abstraction]

#define ADC0_CH4_PIN        (4)
#define ADC0_CH4_PORT       (gpioPortD)

#define ADC0_CH5_PIN        (5)
#define ADC0_CH5_PORT       (gpioPortD)

#define ADC0_CH6_PIN        (6)
#define ADC0_CH6_PORT       (gpioPortD)

#define BATADC_PIN          (5)
#define BATADC_PORT         (gpioPortD)

#define BATCTRL_PIN         (13)
#define BATCTRL_PORT        (gpioPortC)

#define CAPADC_PIN          (4)
#define CAPADC_PORT         (gpioPortD)

#define FLASH_CS_PIN        (3)
#define FLASH_CS_PORT       (gpioPortD)

#define FLASH_RST_PIN       (11)
#define FLASH_RST_PORT      (gpioPortA)

#define FLASH_SCK_PIN       (2)
#define FLASH_SCK_PORT      (gpioPortD)

#define FLASH_SI_PIN        (0)
#define FLASH_SI_PORT       (gpioPortD)

#define FLASH_SO3_PIN       (10)
#define FLASH_SO3_PORT      (gpioPortA)

#define FLASH_SO_PIN        (1)
#define FLASH_SO_PORT       (gpioPortD)

#define FLASH_WP_PIN        (9)
#define FLASH_WP_PORT       (gpioPortA)

#define GPIO_SWO_PIN        (15)
#define GPIO_SWO_PORT       (gpioPortC)

#define GPRSCTRL_PIN        (14)
#define GPRSCTRL_PORT       (gpioPortC)

#define HFXO_N_PIN          (14)
#define HFXO_N_PORT         (gpioPortB)

#define HFXO_P_PIN          (13)
#define HFXO_P_PORT         (gpioPortB)

#define I2C0_SCL_PIN        (1)
#define I2C0_SCL_PORT       (gpioPortA)

#define I2C0_SDA_PIN        (0)
#define I2C0_SDA_PORT       (gpioPortA)

#define LEUART0_RX_PIN      (15)
#define LEUART0_RX_PORT     (gpioPortE)

#define LEUART0_TX_PIN      (14)
#define LEUART0_TX_PORT     (gpioPortE)

#define LFXO_N_PIN          (8)
#define LFXO_N_PORT         (gpioPortB)

#define RF_GPIO0_PIN        (2)
#define RF_GPIO0_PORT       (gpioPortC)

#define RF_GPIO1_PIN        (3)
#define RF_GPIO1_PORT       (gpioPortC)

#define RF_GPIO2_PIN        (4)
#define RF_GPIO2_PORT       (gpioPortC)

#define RF_GPIO3_PIN        (5)
#define RF_GPIO3_PORT       (gpioPortC)

#define RF_MISO_PIN         (4)
#define RF_MISO_PORT        (gpioPortB)

#define RF_MOSI_PIN         (3)
#define RF_MOSI_PORT        (gpioPortB)

#define RF_NIRQ_PIN         (1)
#define RF_NIRQ_PORT        (gpioPortC)

#define RF_NSEL_PIN         (6)
#define RF_NSEL_PORT        (gpioPortB)

#define RF_SCLK_PIN         (5)
#define RF_SCLK_PORT        (gpioPortB)

#define RF_SDN_PIN          (0)
#define RF_SDN_PORT         (gpioPortC)

#define RTCSCL_PIN          (1)
#define RTCSCL_PORT         (gpioPortA)

#define RTCSDA_PIN          (0)
#define RTCSDA_PORT         (gpioPortA)

#define RX_GPRS_PIN         (7)
#define RX_GPRS_PORT        (gpioPortF)

#define RX_GPS_PIN          (15)
#define RX_GPS_PORT         (gpioPortE)

#define RX_WEIHU_PIN        (11)
#define RX_WEIHU_PORT       (gpioPortE)

#define SUNADC_PIN          (6)
#define SUNADC_PORT         (gpioPortD)

#define TIMER1_CC0_PIN      (13)
#define TIMER1_CC0_PORT     (gpioPortC)

#define TX_GPRS_PIN         (6)
#define TX_GPRS_PORT        (gpioPortF)

#define TX_GPS_PIN          (14)
#define TX_GPS_PORT         (gpioPortE)

#define TX_WEIHU_PIN        (10)
#define TX_WEIHU_PORT       (gpioPortE)

#define UART0_RX_PIN        (7)
#define UART0_RX_PORT       (gpioPortF)

#define UART0_TX_PIN        (6)
#define UART0_TX_PORT       (gpioPortF)

#define USART0_RX_PIN       (11)
#define USART0_RX_PORT      (gpioPortE)

#define USART0_TX_PIN       (10)
#define USART0_TX_PORT      (gpioPortE)

#define USART2_CLK_PIN      (5)
#define USART2_CLK_PORT     (gpioPortB)

#define USART2_CS_PIN       (6)
#define USART2_CS_PORT      (gpioPortB)

#define USART2_RX_PIN       (4)
#define USART2_RX_PORT      (gpioPortB)

#define USART2_TX_PIN       (3)
#define USART2_TX_PORT      (gpioPortB)

#define WDT_PIN             (10)
#define WDT_PORT            (gpioPortC)

// [User-defined pin name abstraction]$

#endif
