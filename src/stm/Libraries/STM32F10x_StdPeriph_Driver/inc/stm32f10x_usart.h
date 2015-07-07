/*
 * Author: Copyright (C) STMicroelectronics
 *                                              MCD Application Team            Date:   04/06/2009
 *
 * This file is part of Nitrokey.
 *
 * Nitrokey is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * Nitrokey is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Nitrokey. If not, see <http://www.gnu.org/licenses/>.
 */

/* Define to prevent recursive inclusion ------------------------------------- */
#ifndef __STM32F10x_USART_H
#define __STM32F10x_USART_H

/* Includes ------------------------------------------------------------------ */
#include "stm32f10x.h"

/** @addtogroup StdPeriph_Driver
  * @{
  */

/** @addtogroup USART
  * @{
  */

/** @defgroup USART_Exported_Types
  * @{
  */

/**
  * @brief  USART Init Structure definition
  */

typedef struct
{
    uint32_t USART_BaudRate;
    uint16_t USART_WordLength;
    uint16_t USART_StopBits;
    uint16_t USART_Parity;
    uint16_t USART_Mode;
    uint16_t USART_HardwareFlowControl;
} USART_InitTypeDef;

/**
  * @brief  USART Clock Init Structure definition
  */

typedef struct
{
    uint16_t USART_Clock;
    uint16_t USART_CPOL;
    uint16_t USART_CPHA;
    uint16_t USART_LastBit;
} USART_ClockInitTypeDef;

/**
  * @}
  */

/** @defgroup USART_Exported_Constants
  * @{
  */

#define IS_USART_ALL_PERIPH(PERIPH) (((*(uint32_t*)&(PERIPH)) == USART1_BASE) || \
                                     ((*(uint32_t*)&(PERIPH)) == USART2_BASE) || \
                                     ((*(uint32_t*)&(PERIPH)) == USART3_BASE) || \
                                     ((*(uint32_t*)&(PERIPH)) == UART4_BASE) || \
                                     ((*(uint32_t*)&(PERIPH)) == UART5_BASE))
#define IS_USART_123_PERIPH(PERIPH) (((*(uint32_t*)&(PERIPH)) == USART1_BASE) || \
                                     ((*(uint32_t*)&(PERIPH)) == USART2_BASE) || \
                                     ((*(uint32_t*)&(PERIPH)) == USART3_BASE))
#define IS_USART_1234_PERIPH(PERIPH) (((*(uint32_t*)&(PERIPH)) == USART1_BASE) || \
                                      ((*(uint32_t*)&(PERIPH)) == USART2_BASE) || \
                                      ((*(uint32_t*)&(PERIPH)) == USART3_BASE) || \
                                      ((*(uint32_t*)&(PERIPH)) == UART4_BASE))
/** @defgroup USART_Word_Length
  * @{
  */

#define USART_WordLength_8b                  ((uint16_t)0x0000)
#define USART_WordLength_9b                  ((uint16_t)0x1000)

#define IS_USART_WORD_LENGTH(LENGTH) (((LENGTH) == USART_WordLength_8b) || \
                                      ((LENGTH) == USART_WordLength_9b))
/**
  * @}
  */

/** @defgroup USART_Stop_Bits
  * @{
  */

#define USART_StopBits_1                     ((uint16_t)0x0000)
#define USART_StopBits_0_5                   ((uint16_t)0x1000)
#define USART_StopBits_2                     ((uint16_t)0x2000)
#define USART_StopBits_1_5                   ((uint16_t)0x3000)
#define IS_USART_STOPBITS(STOPBITS) (((STOPBITS) == USART_StopBits_1) || \
                                     ((STOPBITS) == USART_StopBits_0_5) || \
                                     ((STOPBITS) == USART_StopBits_2) || \
                                     ((STOPBITS) == USART_StopBits_1_5))
/**
  * @}
  */

/** @defgroup USART_Parity
  * @{
  */

#define USART_Parity_No                      ((uint16_t)0x0000)
#define USART_Parity_Even                    ((uint16_t)0x0400)
#define USART_Parity_Odd                     ((uint16_t)0x0600)
#define IS_USART_PARITY(PARITY) (((PARITY) == USART_Parity_No) || \
                                 ((PARITY) == USART_Parity_Even) || \
                                 ((PARITY) == USART_Parity_Odd))
/**
  * @}
  */

/** @defgroup USART_Mode
  * @{
  */

#define USART_Mode_Rx                        ((uint16_t)0x0004)
#define USART_Mode_Tx                        ((uint16_t)0x0008)
#define IS_USART_MODE(MODE) ((((MODE) & (uint16_t)0xFFF3) == 0x00) && ((MODE) != (uint16_t)0x00))
/**
  * @}
  */

/** @defgroup USART_Hardware_Flow_Control
  * @{
  */
#define USART_HardwareFlowControl_None       ((uint16_t)0x0000)
#define USART_HardwareFlowControl_RTS        ((uint16_t)0x0100)
#define USART_HardwareFlowControl_CTS        ((uint16_t)0x0200)
#define USART_HardwareFlowControl_RTS_CTS    ((uint16_t)0x0300)
#define IS_USART_HARDWARE_FLOW_CONTROL(CONTROL)\
                              (((CONTROL) == USART_HardwareFlowControl_None) || \
                               ((CONTROL) == USART_HardwareFlowControl_RTS) || \
                               ((CONTROL) == USART_HardwareFlowControl_CTS) || \
                               ((CONTROL) == USART_HardwareFlowControl_RTS_CTS))
#define IS_USART_PERIPH_HFC(PERIPH, HFC) ((((*(uint32_t*)&(PERIPH)) != UART4_BASE) && \
                                          ((*(uint32_t*)&(PERIPH)) != UART5_BASE)) \
                                          || ((HFC) == USART_HardwareFlowControl_None))
/**
  * @}
  */

/** @defgroup USART_Clock
  * @{
  */
#define USART_Clock_Disable                  ((uint16_t)0x0000)
#define USART_Clock_Enable                   ((uint16_t)0x0800)
#define IS_USART_CLOCK(CLOCK) (((CLOCK) == USART_Clock_Disable) || \
                               ((CLOCK) == USART_Clock_Enable))
/**
  * @}
  */

/** @defgroup USART_Clock_Polarity
  * @{
  */

#define USART_CPOL_Low                       ((uint16_t)0x0000)
#define USART_CPOL_High                      ((uint16_t)0x0400)
#define IS_USART_CPOL(CPOL) (((CPOL) == USART_CPOL_Low) || ((CPOL) == USART_CPOL_High))

/**
  * @}
  */

/** @defgroup USART_Clock_Phase
  * @{
  */

#define USART_CPHA_1Edge                     ((uint16_t)0x0000)
#define USART_CPHA_2Edge                     ((uint16_t)0x0200)
#define IS_USART_CPHA(CPHA) (((CPHA) == USART_CPHA_1Edge) || ((CPHA) == USART_CPHA_2Edge))

/**
  * @}
  */

/** @defgroup USART_Last_Bit
  * @{
  */

#define USART_LastBit_Disable                ((uint16_t)0x0000)
#define USART_LastBit_Enable                 ((uint16_t)0x0100)
#define IS_USART_LASTBIT(LASTBIT) (((LASTBIT) == USART_LastBit_Disable) || \
                                   ((LASTBIT) == USART_LastBit_Enable))
/**
  * @}
  */

/** @defgroup USART_Interrupt_definition
  * @{
  */

#define USART_IT_PE                          ((uint16_t)0x0028)
#define USART_IT_TXE                         ((uint16_t)0x0727)
#define USART_IT_TC                          ((uint16_t)0x0626)
#define USART_IT_RXNE                        ((uint16_t)0x0525)
#define USART_IT_IDLE                        ((uint16_t)0x0424)
#define USART_IT_LBD                         ((uint16_t)0x0846)
#define USART_IT_CTS                         ((uint16_t)0x096A)
#define USART_IT_ERR                         ((uint16_t)0x0060)
#define USART_IT_ORE                         ((uint16_t)0x0360)
#define USART_IT_NE                          ((uint16_t)0x0260)
#define USART_IT_FE                          ((uint16_t)0x0160)
#define IS_USART_CONFIG_IT(IT) (((IT) == USART_IT_PE) || ((IT) == USART_IT_TXE) || \
                               ((IT) == USART_IT_TC) || ((IT) == USART_IT_RXNE) || \
                               ((IT) == USART_IT_IDLE) || ((IT) == USART_IT_LBD) || \
                               ((IT) == USART_IT_CTS) || ((IT) == USART_IT_ERR))
#define IS_USART_GET_IT(IT) (((IT) == USART_IT_PE) || ((IT) == USART_IT_TXE) || \
                            ((IT) == USART_IT_TC) || ((IT) == USART_IT_RXNE) || \
                            ((IT) == USART_IT_IDLE) || ((IT) == USART_IT_LBD) || \
                            ((IT) == USART_IT_CTS) || ((IT) == USART_IT_ORE) || \
                            ((IT) == USART_IT_NE) || ((IT) == USART_IT_FE))
#define IS_USART_CLEAR_IT(IT) (((IT) == USART_IT_TC) || ((IT) == USART_IT_RXNE) || \
                               ((IT) == USART_IT_LBD) || ((IT) == USART_IT_CTS))
#define IS_USART_PERIPH_IT(PERIPH, USART_IT) ((((*(uint32_t*)&(PERIPH)) != UART4_BASE) && \
                                              ((*(uint32_t*)&(PERIPH)) != UART5_BASE)) \
                                              || ((USART_IT) != USART_IT_CTS))
/**
  * @}
  */

/** @defgroup USART_DMA_Requests
  * @{
  */

#define USART_DMAReq_Tx                      ((uint16_t)0x0080)
#define USART_DMAReq_Rx                      ((uint16_t)0x0040)
#define IS_USART_DMAREQ(DMAREQ) ((((DMAREQ) & (uint16_t)0xFF3F) == 0x00) && ((DMAREQ) != (uint16_t)0x00))

/**
  * @}
  */

/** @defgroup USART_WakeUp_methods
  * @{
  */

#define USART_WakeUp_IdleLine                ((uint16_t)0x0000)
#define USART_WakeUp_AddressMark             ((uint16_t)0x0800)
#define IS_USART_WAKEUP(WAKEUP) (((WAKEUP) == USART_WakeUp_IdleLine) || \
                                 ((WAKEUP) == USART_WakeUp_AddressMark))
/**
  * @}
  */

/** @defgroup USART_LIN_Break_Detection_Length
  * @{
  */

#define USART_LINBreakDetectLength_10b      ((uint16_t)0x0000)
#define USART_LINBreakDetectLength_11b      ((uint16_t)0x0020)
#define IS_USART_LIN_BREAK_DETECT_LENGTH(LENGTH) \
                               (((LENGTH) == USART_LINBreakDetectLength_10b) || \
                                ((LENGTH) == USART_LINBreakDetectLength_11b))
/**
  * @}
  */

/** @defgroup USART_IrDA_Low_Power
  * @{
  */

#define USART_IrDAMode_LowPower              ((uint16_t)0x0004)
#define USART_IrDAMode_Normal                ((uint16_t)0x0000)
#define IS_USART_IRDA_MODE(MODE) (((MODE) == USART_IrDAMode_LowPower) || \
                                  ((MODE) == USART_IrDAMode_Normal))
/**
  * @}
  */

/** @defgroup USART_Flags
  * @{
  */

#define USART_FLAG_CTS                       ((uint16_t)0x0200)
#define USART_FLAG_LBD                       ((uint16_t)0x0100)
#define USART_FLAG_TXE                       ((uint16_t)0x0080)
#define USART_FLAG_TC                        ((uint16_t)0x0040)
#define USART_FLAG_RXNE                      ((uint16_t)0x0020)
#define USART_FLAG_IDLE                      ((uint16_t)0x0010)
#define USART_FLAG_ORE                       ((uint16_t)0x0008)
#define USART_FLAG_NE                        ((uint16_t)0x0004)
#define USART_FLAG_FE                        ((uint16_t)0x0002)
#define USART_FLAG_PE                        ((uint16_t)0x0001)
#define IS_USART_FLAG(FLAG) (((FLAG) == USART_FLAG_PE) || ((FLAG) == USART_FLAG_TXE) || \
                             ((FLAG) == USART_FLAG_TC) || ((FLAG) == USART_FLAG_RXNE) || \
                             ((FLAG) == USART_FLAG_IDLE) || ((FLAG) == USART_FLAG_LBD) || \
                             ((FLAG) == USART_FLAG_CTS) || ((FLAG) == USART_FLAG_ORE) || \
                             ((FLAG) == USART_FLAG_NE) || ((FLAG) == USART_FLAG_FE))

#define IS_USART_CLEAR_FLAG(FLAG) ((((FLAG) & (uint16_t)0xFC9F) == 0x00) && ((FLAG) != (uint16_t)0x00))
#define IS_USART_PERIPH_FLAG(PERIPH, USART_FLAG) ((((*(uint32_t*)&(PERIPH)) != UART4_BASE) &&\
                                                  ((*(uint32_t*)&(PERIPH)) != UART5_BASE)) \
                                                  || ((USART_FLAG) != USART_FLAG_CTS))
#define IS_USART_BAUDRATE(BAUDRATE) (((BAUDRATE) > 0) && ((BAUDRATE) < 0x0044AA21))
#define IS_USART_ADDRESS(ADDRESS) ((ADDRESS) <= 0xF)
#define IS_USART_DATA(DATA) ((DATA) <= 0x1FF)

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup USART_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup USART_Exported_Functions
  * @{
  */

void USART_DeInit (USART_TypeDef * USARTx);

void USART_Init (USART_TypeDef * USARTx, USART_InitTypeDef * USART_InitStruct);
void USART_StructInit (USART_InitTypeDef * USART_InitStruct);

void USART_ClockInit (USART_TypeDef * USARTx, USART_ClockInitTypeDef * USART_ClockInitStruct);
void USART_ClockStructInit (USART_ClockInitTypeDef * USART_ClockInitStruct);

void USART_Cmd (USART_TypeDef * USARTx, FunctionalState NewState);

void USART_ITConfig (USART_TypeDef * USARTx, uint16_t USART_IT, FunctionalState NewState);
void USART_DMACmd (USART_TypeDef * USARTx, uint16_t USART_DMAReq, FunctionalState NewState);
void USART_SetAddress (USART_TypeDef * USARTx, uint8_t USART_Address);

void USART_WakeUpConfig (USART_TypeDef * USARTx, uint16_t USART_WakeUp);

void USART_ReceiverWakeUpCmd (USART_TypeDef * USARTx, FunctionalState NewState);
void USART_LINBreakDetectLengthConfig (USART_TypeDef * USARTx, uint16_t USART_LINBreakDetectLength);
void USART_LINCmd (USART_TypeDef * USARTx, FunctionalState NewState);

void USART_SendData (USART_TypeDef * USARTx, uint16_t Data);

uint16_t USART_ReceiveData (USART_TypeDef * USARTx);

void USART_SendBreak (USART_TypeDef * USARTx);

void USART_SetGuardTime (USART_TypeDef * USARTx, uint8_t USART_GuardTime);

void USART_SetPrescaler (USART_TypeDef * USARTx, uint8_t USART_Prescaler);

void USART_SmartCardCmd (USART_TypeDef * USARTx, FunctionalState NewState);

void USART_SmartCardNACKCmd (USART_TypeDef * USARTx, FunctionalState NewState);
void USART_HalfDuplexCmd (USART_TypeDef * USARTx, FunctionalState NewState);

void USART_IrDAConfig (USART_TypeDef * USARTx, uint16_t USART_IrDAMode);

void USART_IrDACmd (USART_TypeDef * USARTx, FunctionalState NewState);

FlagStatus USART_GetFlagStatus (USART_TypeDef * USARTx, uint16_t USART_FLAG);

void USART_ClearFlag (USART_TypeDef * USARTx, uint16_t USART_FLAG);

ITStatus USART_GetITStatus (USART_TypeDef * USARTx, uint16_t USART_IT);

void USART_ClearITPendingBit (USART_TypeDef * USARTx, uint16_t USART_IT);

#endif /* __STM32F10x_USART_H */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
