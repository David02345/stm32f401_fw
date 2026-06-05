/*
 * reset.c
 *
 *  Created on: 2026. 5. 29.
 *      Author: YDG
 */

#include "reset.h"
#include "rtc.h"


static uint32_t reset_count = 0;

bool resetInit(void)
{
  bool ret = true;

  if (RCC->CSR & (1<<26)) // 리셋 감지 레지스터
  {
    rtcBackupRegWrite(1, rtcBackupRegRead(1) + 1); // 자기 자신 읽고 1 더한 후 쓰기 (Increment)
    delay(500); // 500ms 안에 누른 횟수 세기
    reset_count = rtcBackupRegRead(1);
  }
  rtcBackupRegWrite(1, 0); // 시작 초기화

  return ret;
}

uint32_t resetGetCount(void)
{
  return reset_count;
}
