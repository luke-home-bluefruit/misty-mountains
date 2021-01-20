#ifndef __STM32F767xx_H
#define __STM32F767xx_H

#include <stdint.h>

typedef struct
{
  uint32_t CR;
  uint32_t PLLCFGR;
} RCC_TypeDef;

static RCC_TypeDef mock_RCC;
#define RCC (&mock_RCC)

#endif