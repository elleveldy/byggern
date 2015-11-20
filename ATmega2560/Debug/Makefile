################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../Communication \
../Drivers


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../Communication/can.c \
../Communication/canjoy.c \
../Communication/mcp2515.c \
../Communication/spi.c \
../Communication/TWI_Master.c \
../Communication/uart.c \
../Drivers/adc.c \
../Drivers/max520.c \
../Drivers/pwm.c \
../Drivers/timer.c \
../main.c \
../game.c \
../ir.c \
../motor.c \
../PI_controller.c \
../servo.c \
../solenoid.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
Communication/can.o \
Communication/canjoy.o \
Communication/mcp2515.o \
Communication/spi.o \
Communication/TWI_Master.o \
Communication/uart.o \
Drivers/adc.o \
Drivers/max520.o \
Drivers/pwm.o \
Drivers/timer.o \
main.o \
game.o \
ir.o \
motor.o \
PI_controller.o \
servo.o \
solenoid.o

OBJS_AS_ARGS +=  \
Communication/can.o \
Communication/canjoy.o \
Communication/mcp2515.o \
Communication/spi.o \
Communication/TWI_Master.o \
Communication/uart.o \
Drivers/adc.o \
Drivers/max520.o \
Drivers/pwm.o \
Drivers/timer.o \
main.o \
game.o \
ir.o \
motor.o \
PI_controller.o \
servo.o \
solenoid.o

C_DEPS +=  \
Communication/can.d \
Communication/canjoy.d \
Communication/mcp2515.d \
Communication/spi.d \
Communication/TWI_Master.d \
Communication/uart.d \
Drivers/adc.d \
Drivers/max520.d \
Drivers/pwm.d \
Drivers/timer.d \
main.d \
game.d \
ir.d \
motor.d \
PI_controller.d \
servo.d \
solenoid.d

C_DEPS_AS_ARGS +=  \
Communication/can.d \
Communication/canjoy.d \
Communication/mcp2515.d \
Communication/spi.d \
Communication/TWI_Master.d \
Communication/uart.d \
Drivers/adc.d \
Drivers/max520.d \
Drivers/pwm.d \
Drivers/timer.d \
main.d \
game.d \
ir.d \
motor.d \
PI_controller.d \
servo.d \
solenoid.d

OUTPUT_FILE_PATH +=Atmega2560.elf

OUTPUT_FILE_PATH_AS_ARGS +=Atmega2560.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler



































Communication/%.o: ../Communication/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=16000000  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega2560 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Drivers/%.o: ../Drivers/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=16000000  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega2560 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=16000000  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega2560 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="Atmega2560.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mrelax -mmcu=atmega2560 -Wl,-u,vfprintf -lprintf_flt -lm  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "Atmega2560.elf" "Atmega2560.hex"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "Atmega2560.elf" "Atmega2560.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "Atmega2560.elf" > "Atmega2560.lss"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "Atmega2560.elf" "Atmega2560.srec"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-size.exe" "Atmega2560.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "Atmega2560.elf" "Atmega2560.a" "Atmega2560.hex" "Atmega2560.lss" "Atmega2560.eep" "Atmega2560.map" "Atmega2560.srec" "Atmega2560.usersignatures"
	