/*
 * rtc.c
 *
 *  Created on: 2026. 5. 29.
 *      Author: YDG
 */

#include "rtc.h"


static RTC_HandleTypeDef hrtc;



bool rtcInit(void)
{
  bool ret = true;

  __HAL_RCC_GPIOC_CLK_ENABLE();

  hrtc.Instance = RTC;
  hrtc.Init.HourFormat        = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv      = 127;
  hrtc.Init.SynchPrediv       = 255;
  hrtc.Init.OutPut            = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity    = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType        = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc)    != HAL_OK)
  {
    Error_Handler();
  }


  return ret;
}

uint32_t rtcBackupRegRead(uint32_t index)
{
  return HAL_RTCEx_BKUPRead(&hrtc, index);
}
void rtcBackupRegWrite(uint32_t index, uint32_t data)
{
  HAL_RTCEx_BKUPWrite(&hrtc, index, data);
}





void HAL_RTC_MspInit(RTC_HandleTypeDef* rtcHandle)
{

  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(rtcHandle->Instance==RTC)
  {
  /* USER CODE BEGIN RTC_MspInit 0 */

  /* USER CODE END RTC_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
    PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* RTC clock enable */
    __HAL_RCC_RTC_ENABLE();
  /* USER CODE BEGIN RTC_MspInit 1 */

  /* USER CODE END RTC_MspInit 1 */
  }
}
