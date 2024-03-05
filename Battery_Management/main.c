#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_adc.h"
#include "i2c_lcd.h"
#include "delay.h"
#include "kalman.h"
#include "stdio.h"
void RCC_Config(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA| RCC_APB2Periph_ADC1, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
}
void GPIO_Config(){
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void ADC_Config(){
	ADC_InitTypeDef ADC_InitStruct;
	
	ADC_InitStruct.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStruct.ADC_NbrOfChannel = 1;
	ADC_InitStruct.ADC_ScanConvMode = DISABLE;
	ADC_InitStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;
	
	ADC_Init(ADC1, &ADC_InitStruct);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);
	ADC_Cmd(ADC1, ENABLE);
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

int main(){
	char szBuff[10];
	RCC_Config();
	GPIO_Config();
	ADC_Config();
	Delay_Init();
	I2C_LCD_Init();
	I2C_LCD_Clear();
	I2C_LCD_BackLight(1);
	I2C_LCD_Puts(" ---Battery---");
	I2C_LCD_NewLine();
	I2C_LCD_Puts("----------------");
	uint16_t val, sum, valUpdate;
	float analogVoltage = 0;
	float lastAnalogVoltage = 0;
	uint8_t temp1, temp2;
	uint8_t volume = 0;
	SimpleKalmanFilter(1, 1, 0.001);
	Delay_Ms(1000);
	I2C_LCD_Clear();
	while(1){
		//for(int i=0; i< 10; i++){
			val = ADC_GetConversionValue(ADC1);
			//Delay_Us(10);
			//sum+=val;
		//}
		//sum = sum/10;
		valUpdate = (float)updateEstimate((float)val);
		//analogVoltage = (((float)sum / 4095.0) * (3.3 - 2.3) + 2.3) + 0.8;
		analogVoltage = 0.0011*valUpdate - 0.0142;
		temp1 = analogVoltage*10;
		temp2 = lastAnalogVoltage*10;
		if((temp1 - temp2) != 0){
			lastAnalogVoltage = analogVoltage;
			I2C_LCD_Clear();
			if(analogVoltage >= 3.9){
				sendString_XY(1,0,"Good");
			}
			else if(analogVoltage >= 3.6){
				sendString_XY(1,0,"Poor");
			}
			else{
				sendString_XY(1,0,"Low");
			}
			sprintf(szBuff,"%0.1fV",analogVoltage);
			sendString_XY(1,12,szBuff);
			I2C_LCD_NewLine();
			volume = (4.1 - analogVoltage)/0.07;
			for(int i = 0; i <= (16 - volume); i++){
				sendVal_XY(2,i,0xFF);
			}
		}
		sum = 0;
	}
}