#include "ClocksDriver.h"

#include "stm32f767xx.h"

namespace Drivers
{

uint16_t ClocksDriver::m_HSI;


void ClocksDriver::SetClockControlRegister(uint32_t data)
{
  RCC->CR = data;
}

void ClocksDriver::SetPLLConfigurationRegister(uint32_t data)
{
  RCC->PLLCFGR = data;
}

bool ClocksDriver::GetPLLReady()
{
  return (RCC->CR >> 25) & 1;
}

void ClocksDriver::SetPLLEnable(bool enabled)
{
  const uint32_t maskedBits = RCC->CR & ~(1 << 25);
  RCC->CR = maskedBits | ((enabled ? 0 : 1) << 25);
}

uint16_t ClocksDriver::GetPLLM()
{
  return (RCC->PLLCFGR & 0x0000003F);
}

uint16_t ClocksDriver::GetPLLN()
{
  return (RCC->PLLCFGR & 0x00007FC0) >> 6;
}

uint16_t ClocksDriver::GetPLLP()
{
  const uint16_t encodedPLLP = (RCC->PLLCFGR & 0x00030000) >> 16;
  switch (encodedPLLP)
  {
    case 0:
      return 2;
    case 1:
      return 4;
    case 2:
      return 6;
    case 3:
      return 8;
  }
  return 0;
}

void ClocksDriver::SetHSI(uint32_t HSI)
{
  m_HSI = HSI;
}

uint32_t ClocksDriver::GetClockFrequency()
{
  return m_HSI * (GetPLLN() / GetPLLM()) / GetPLLP();
}

}