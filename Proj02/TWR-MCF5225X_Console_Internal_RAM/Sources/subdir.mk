################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/DIP_lib.c" \
"../Sources/DMA_lib.c" \
"../Sources/LED_lib.c" \
"../Sources/PB_lib.c" \
"../Sources/RNG_lib.c" \
"../Sources/TWR-MCF5225X_sysinit.c" \
"../Sources/console_io_cf.c" \
"../Sources/exceptions.c" \
"../Sources/main.c" \
"../Sources/uart_support.c" \

C_SRCS += \
../Sources/DIP_lib.c \
../Sources/DMA_lib.c \
../Sources/LED_lib.c \
../Sources/PB_lib.c \
../Sources/RNG_lib.c \
../Sources/TWR-MCF5225X_sysinit.c \
../Sources/console_io_cf.c \
../Sources/exceptions.c \
../Sources/main.c \
../Sources/uart_support.c \

OBJS += \
./Sources/DIP_lib_c.obj \
./Sources/DMA_lib_c.obj \
./Sources/LED_lib_c.obj \
./Sources/PB_lib_c.obj \
./Sources/RNG_lib_c.obj \
./Sources/TWR-MCF5225X_sysinit_c.obj \
./Sources/console_io_cf_c.obj \
./Sources/exceptions_c.obj \
./Sources/main_c.obj \
./Sources/uart_support_c.obj \

OBJS_QUOTED += \
"./Sources/DIP_lib_c.obj" \
"./Sources/DMA_lib_c.obj" \
"./Sources/LED_lib_c.obj" \
"./Sources/PB_lib_c.obj" \
"./Sources/RNG_lib_c.obj" \
"./Sources/TWR-MCF5225X_sysinit_c.obj" \
"./Sources/console_io_cf_c.obj" \
"./Sources/exceptions_c.obj" \
"./Sources/main_c.obj" \
"./Sources/uart_support_c.obj" \

C_DEPS += \
./Sources/DIP_lib_c.d \
./Sources/DMA_lib_c.d \
./Sources/LED_lib_c.d \
./Sources/PB_lib_c.d \
./Sources/RNG_lib_c.d \
./Sources/TWR-MCF5225X_sysinit_c.d \
./Sources/console_io_cf_c.d \
./Sources/exceptions_c.d \
./Sources/main_c.d \
./Sources/uart_support_c.d \

OBJS_OS_FORMAT += \
./Sources/DIP_lib_c.obj \
./Sources/DMA_lib_c.obj \
./Sources/LED_lib_c.obj \
./Sources/PB_lib_c.obj \
./Sources/RNG_lib_c.obj \
./Sources/TWR-MCF5225X_sysinit_c.obj \
./Sources/console_io_cf_c.obj \
./Sources/exceptions_c.obj \
./Sources/main_c.obj \
./Sources/uart_support_c.obj \

C_DEPS_QUOTED += \
"./Sources/DIP_lib_c.d" \
"./Sources/DMA_lib_c.d" \
"./Sources/LED_lib_c.d" \
"./Sources/PB_lib_c.d" \
"./Sources/RNG_lib_c.d" \
"./Sources/TWR-MCF5225X_sysinit_c.d" \
"./Sources/console_io_cf_c.d" \
"./Sources/exceptions_c.d" \
"./Sources/main_c.d" \
"./Sources/uart_support_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/DIP_lib_c.obj: ../Sources/DIP_lib.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/DIP_lib.args" -o "Sources/DIP_lib_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/DMA_lib_c.obj: ../Sources/DMA_lib.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/DMA_lib.args" -o "Sources/DMA_lib_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/LED_lib_c.obj: ../Sources/LED_lib.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/LED_lib.args" -o "Sources/LED_lib_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/PB_lib_c.obj: ../Sources/PB_lib.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/PB_lib.args" -o "Sources/PB_lib_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/RNG_lib_c.obj: ../Sources/RNG_lib.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/RNG_lib.args" -o "Sources/RNG_lib_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/TWR-MCF5225X_sysinit_c.obj: ../Sources/TWR-MCF5225X_sysinit.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/TWR-MCF5225X_sysinit.args" -o "Sources/TWR-MCF5225X_sysinit_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/console_io_cf_c.obj: ../Sources/console_io_cf.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/console_io_cf.args" -o "Sources/console_io_cf_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/exceptions_c.obj: ../Sources/exceptions.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/exceptions.args" -o "Sources/exceptions_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/main.args" -o "Sources/main_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/uart_support_c.obj: ../Sources/uart_support.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/uart_support.args" -o "Sources/uart_support_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


