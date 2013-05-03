/*
 * bsp.h
 *
 * Main interface to BSP code
 *
 * Copyright (c) 2012, Oleg Tsaregorodtsev
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef BSP_H_
#define BSP_H_

/* Includes ------------------------------------------------------------------*/
#include "common.h"
#include "cpu.h"
#include "bsp_config.h"
#include "powermanager.h"

/* Exported defines ----------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
bool BSP_IsPowerSourceConnected(void);
bool BSP_IsCharging(void);

void BSP_InitPowerManager(void);
void BSP_InitPowerSourcesSense(void);
void BSP_StartPowerManagerADC(ADC_Source_Typedef ADC_Source);
u32 BSP_GetLast_ADC_Result_mV(void);

void BSP_PowerEnable(void);
void BSP_PowerDisable(void);

void BSP_Keypad_Init(void);
bool BSP_Keypad_GetKeyStatus(KEY_Typedef key);

void Disp_GPIO_Init();

void SD_LowLevel_DeInit(void);
void SD_LowLevel_Init(void);
uint8_t SD_Detect(void);

void Vibrator_Init(void);
void Vibrator_Disable(void);
void Vibrator_Enable(void);

void USB_OTG_BSP_DeInit(void);
void BSP_USBD_MSC_Init(void);

/* MM */

void *ccm_malloc(size_t size);
void *ccm_zalloc(size_t size);
void ccm_free(void *mem);
void ccm_calloc(size_t n, size_t elem_size);

#endif /* BSP_H_ */
