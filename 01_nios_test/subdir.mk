C_SRCS += \
sw/startup.S \
sw/main.c \
sw/vectors.c \
drv/src/gpio.c

OBJS += \
sw_out/startup.o \
sw_out/main.o \
sw_out/vectors.o \
sw_out/gpio.o

C_DEPS += \
sw_out/startup.d \
sw_out/main.d \
sw_out/vectors.d \
sw_out/gpio.d

sw_out/%.o: sw/%.S
	@echo 'Building file: $<'
	nios2-elf-as -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

sw_out/%.o: sw/%.c
	@echo 'Building file: $<'
	nios2-elf-gcc -O2 -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

sw_out/%.o: drv/src/%.c
	@echo 'Building file: $<'
	nios2-elf-gcc -O2 -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
