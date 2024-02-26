#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"
#include "stdio.h"
#include "spi.h"
#include "mfrc522.h"
#include "delay.h"
#include "ff.h"

#define TX_Pin GPIO_Pin_9
#define RX_Pin GPIO_Pin_10
#define UART_GPIO GPIOA



void delay(){
	int i = 1000000;
	while(i){i-=1;}
	i = 1000000;
	while(i){i-=1;}
	i = 1000000;
	while(i){i-=1;}
}
void UART1_Init();
void UART_SendChar(USART_TypeDef *USARTx, char data);
void UART_SendString(USART_TypeDef *USARTx, char *str);
void Led13_Init(void);

int main(){
	Led13_Init();
	UART1_Init();
	SPI_Config();
	Delay_Init();
	MFRC522_Init();
	SDCard_InitPin();
	UART_SendString(USART1, "RFID");
	uint8_t CardID[5];
	char szBuff[11];
	FATFS FatFs;		/* FatFs work area needed for each volume */
	FIL Fil;			/* File object needed for each open file */
	UINT bw;
	FRESULT fr;
	
	f_mount(&FatFs, "", 0);		/* Give a work area to the default drive */
	fr = f_open(&Fil, "Hello.txt", FA_WRITE | FA_CREATE_ALWAYS);	/* Create a file */
	if (fr == FR_OK) {
		f_write(&Fil, "Hello World", 11, &bw);	/* Write data to the file */
		fr = f_close(&Fil);							/* Close the file */
		if (fr == FR_OK && bw == 11) {		/* Lights green LED if data written well */
			while (1) {
				GPIO_SetBits(GPIOC, GPIO_Pin_13);
				Delay_Ms(100);
				GPIO_ResetBits(GPIOC, GPIO_Pin_13);
				Delay_Ms(100);
			}
		}
	}
	while(1){
		if (MFRC522_Check(CardID) == MI_OK) {
			sprintf(szBuff, "%02X%02X%02X%02X%02X", CardID[0], CardID[1], CardID[2], CardID[3], CardID[4]);
			GPIO_SetBits(GPIOC, GPIO_Pin_13);
			delay();
			GPIO_ResetBits(GPIOC, GPIO_Pin_13);
			UART_SendString(USART1, szBuff);
		}
	}
}

void UART1_Init(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1, ENABLE);
	GPIO_InitTypeDef GPIOInitStruct;
	
	GPIOInitStruct.GPIO_Pin = RX_Pin;
	GPIOInitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIOInitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIOInitStruct);
	
	GPIOInitStruct.GPIO_Pin = TX_Pin;
	GPIOInitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIOInitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIOInitStruct);
	
	USART_InitTypeDef USARTInitStruct;
	
	USARTInitStruct.USART_BaudRate = 9600;
	USARTInitStruct.USART_WordLength = USART_WordLength_8b;
	USARTInitStruct.USART_StopBits = USART_StopBits_1;
	USARTInitStruct.USART_Parity = USART_Parity_No;
	USARTInitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USARTInitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1, &USARTInitStruct);
	USART_Cmd(USART1,ENABLE);
}

void UART_SendChar(USART_TypeDef *USARTx, char data){
	USARTx->DR = 0x00;
	USART_SendData(USARTx, data);
	
	while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE)==RESET);
}

void UART_SendString(USART_TypeDef *USARTx, char *str){
	while(*str != '\0')
		{
		UART_SendChar(USARTx, *str);
		str++;
		}
}

void Led13_Init(void) {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef gpioInit;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	gpioInit.GPIO_Mode=GPIO_Mode_Out_PP;
	gpioInit.GPIO_Speed=GPIO_Speed_50MHz;
	gpioInit.GPIO_Pin=GPIO_Pin_13;
	GPIO_Init(GPIOC, &gpioInit);
}


