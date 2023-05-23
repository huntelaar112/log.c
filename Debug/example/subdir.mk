################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../example/main.c 

C_DEPS += \
./example/main.d 

OBJS += \
./example/main.o 


# Each subdirectory must supply rules for building sources it contributes
example/%.o: ../example/%.c example/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-example

clean-example:
	-$(RM) ./example/main.d ./example/main.o

.PHONY: clean-example

