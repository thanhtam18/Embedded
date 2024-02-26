
#ifndef _SPI_H_
#define _SPI_H_

#include "stm32f10x.h"

#define SPIx						SPI2
#define RCC_SPI					RCC_APB1Periph_SPI2
#define RCC_SPI_GPIO		RCC_APB2Periph_GPIOB

#define SPI_SCK					GPIO_Pin_13
#define SPI_MISO				GPIO_Pin_14
#define SPI_MOSI				GPIO_Pin_15
#define SPI_GPIO 				GPIOB

#define MFRC522_SS_GPIO		GPIOB
#define MFRC522_SS_PIN		GPIO_Pin_12
#define MFRC522_SS_RCC		RCC_APB2Periph_GPIOB

#define SDCard_SS_GPIO		GPIOB
#define SDCard_SS_PIN		GPIO_Pin_11
#define SDCard_SS_RCC		RCC_APB2Periph_GPIOB

#define MFRC522_CS_LOW					GPIO_ResetBits(MFRC522_SS_GPIO, MFRC522_SS_PIN);
#define MFRC522_CS_HIGH					GPIO_SetBits(MFRC522_SS_GPIO, MFRC522_SS_PIN);

#define SDCard_CS_LOW					GPIO_ResetBits(SDCard_SS_GPIO, SDCard_SS_PIN);
#define SDCard_CS_HIGH					GPIO_SetBits(SDCard_SS_GPIO, SDCard_SS_PIN);

void SPI_Config(void);
uint8_t SPI_Send(uint8_t data);

void MFRC522_InitPin(void);
void SDCard_InitPin(void);
#endif
