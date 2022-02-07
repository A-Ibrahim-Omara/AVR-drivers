################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/DIO_Program.c \
../Src/GI_Program.c \
../Src/SERVO_Program.c \
../Src/TIMER1_Program.c \
../Src/main.c 

OBJS += \
./Src/DIO_Program.o \
./Src/GI_Program.o \
./Src/SERVO_Program.o \
./Src/TIMER1_Program.o \
./Src/main.o 

C_DEPS += \
./Src/DIO_Program.d \
./Src/GI_Program.d \
./Src/SERVO_Program.d \
./Src/TIMER1_Program.d \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


