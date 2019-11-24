SRCS += \
sw/boot.S \
sw/uart_test_c/main.c \
drv/src/gpio.c \
drv/src/delay.c \
drv/src/uart.c \

OBJS += \
sw_out/boot.o \
sw_out/main.o \
sw_out/gpio.o \
sw_out/delay.o \
sw_out/uart.o \

DEPS += \
sw_out/main.d \
sw_out/gpio.d \
sw_out/delay.d \
sw_out/uart.d \

CCF	= -march=rv32i -mabi=ilp32

sw_out/%.o: sw/uart_test_c/%.c
	@echo 'Building file: $<'
	riscv-none-embed-gcc -O1 -c $(CCF) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building file: $<'

sw_out/%.o: drv/src/%.c
	@echo 'Building file: $<'
	riscv-none-embed-gcc -O1 -c $(CCF) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building file: $<'

sw_out/%.o: sw/%.S
	@echo 'Building file: $<'
	riscv-none-embed-as -c $(CCF) -o "$@" "$<"
	@echo 'Finished building file: $<'
