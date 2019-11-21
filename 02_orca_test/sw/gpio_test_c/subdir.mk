SRCS += \
sw/boot.S \
sw/gpio_test_c/main.c \
drv/src/gpio.c \
drv/src/delay.c \

OBJS += \
sw_out/boot.o \
sw_out/main.o \
sw_out/gpio.o \
sw_out/delay.o \

DEPS += \
sw_out/main.d \
sw_out/gpio.d \
sw_out/delay.d \

CCF	= -march=rv32i -mabi=ilp32

sw_out/%.o: sw/gpio_test_c/%.c
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
