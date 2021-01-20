#pragma once
#include <cstdint>

namespace Drivers
{

class ClocksDriver
{
private:
  static uint16_t _HSI;

public:
  static void SetClockControlRegister(uint32_t data);
  static void SetPLLConfigurationRegister(uint32_t data);

  static bool GetPLLReady();
  static void SetPLLEnable(bool enabled);

  static uint16_t GetPLLM();
  static uint16_t GetPLLN();
  static uint16_t GetPLLP();

  static void SetHSI(uint16_t HSI);

  static uint16_t GetClockFrequency();
};

}
