CXX=arm-none-eabi-g++
OBJCOPY=arm-none-eabi-objcopy
OPTIONS=-mcpu=cortex-m7+nofp --specs=nosys.specs -Wall -Wextra -g

.PHONY: all
all: counter

counter: counter.cpp
	$(CXX) $(OPTIONS) -T STM32F767ZITx_FLASH.ld startup_stm32f767xx.s counter.cpp -o counter.elf
	$(OBJCOPY) -O binary "counter.elf" "counter.bin"
	
.PHONY: clean
clean:
	@rm counter.elf
	@rm counter.bin
