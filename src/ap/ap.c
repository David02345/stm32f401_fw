/*
 * ap.c
 *
 *  Created on: 2026. 5. 26.
 *      Author: YDG
 */
#include "ap.h"



void apInit(void)
{
  uartOpen(_DEF_UART1, 57600);  // USB
  uartOpen(_DEF_UART2, 57600);  // UART
}

void apMain(void)
{
  uint32_t pre_time;

  pre_time = millis();
  while(1)
  {
    if(millis() - pre_time >= 1500)
    {
      pre_time = millis();
      ledToggle(_DEF_LED1);
    }
  }
}
