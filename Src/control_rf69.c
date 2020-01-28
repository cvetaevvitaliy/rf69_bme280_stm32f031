#include <control_rf69.h>

#include "stm32f0xx_hal.h"

extern SPI_HandleTypeDef hspi1;


#define GPIO_PORT_NSS   GPIOA
#define GPIO_PIN_NSS    GPIO_PIN_4

#define GPIO_PORT_DIO0  GPIOA
#define GPIO_PIN_DIO0   GPIO_PIN_0


volatile uint32_t tick_time = 0;
volatile uint16_t time_temp = 0;
//volatile uint32_t time_temp2 = 0;


void noInterrupts(){
    HAL_NVIC_DisableIRQ(EXTI0_1_IRQn);
}


void interrupts(){
    HAL_NVIC_EnableIRQ(EXTI0_1_IRQn);
}



void RFM69_SetCSPin(bool state){
      
    if (state==HIGH)
      HAL_GPIO_WritePin(GPIO_PORT_NSS,GPIO_PIN_NSS,GPIO_PIN_SET);
    else
      HAL_GPIO_WritePin(GPIO_PORT_NSS,GPIO_PIN_NSS,GPIO_PIN_RESET);    
}


bool RFM69_ReadDIO0Pin(){
      return HAL_GPIO_ReadPin(GPIO_PORT_DIO0,GPIO_PIN_DIO0);
}


uint8_t SPI_transfer8(uint8_t data){

    if (HAL_OK == HAL_SPI_TransmitReceive(&hspi1, &data, &data, 1, 1000)) {
        return data;
    }
    return 0;
}


void Serialprint(char* data){
    

}

bool Timeout_IsTimeout1(){
  

    if((HAL_GetTick()-tick_time) > time_temp)
      return 1;
    else 
      return 0;
}


void Timeout_SetTimeout1(uint16_t time){
    
    time_temp=time;
    tick_time =  HAL_GetTick();

}

