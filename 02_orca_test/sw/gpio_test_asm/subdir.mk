SRCS += \
sw/gpio_test_asm/main.S

OBJS += \
sw_out/main.o

DEPS += \
sw_out/main.d

CCF	= -march=rv32i -mabi=ilp32

sw_out/%.o: sw/gpio_test_asm/%.S
	@echo 'Building file: $<'
	riscv-none-embed-as -c $(CCF) -o "$@" "$<"
	@echo 'Finished building file: $<'
