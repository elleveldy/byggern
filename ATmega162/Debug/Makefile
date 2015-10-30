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
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../ADC.c \
../ByggernGruppe48H2015.c \
../can.c \
../canjoy.c \
../font.c \
../gui.c \
../joystick.c \
../main.c \
../mcp2515.c \
../menu.c \
../oled.c \
../snake.c \
../SPI.c \
../timer.c \
../uart.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
ADC.o \
ByggernGruppe48H2015.o \
can.o \
canjoy.o \
font.o \
gui.o \
joystick.o \
main.o \
mcp2515.o \
menu.o \
oled.o \
snake.o \
SPI.o \
timer.o \
uart.o

OBJS_AS_ARGS +=  \
ADC.o \
ByggernGruppe48H2015.o \
can.o \
canjoy.o \
font.o \
gui.o \
joystick.o \
main.o \
mcp2515.o \
menu.o \
oled.o \
snake.o \
SPI.o \
timer.o \
uart.o

C_DEPS +=  \
ADC.d \
ByggernGruppe48H2015.d \
can.d \
canjoy.d \
font.d \
gui.d \
joystick.d \
main.d \
mcp2515.d \
menu.d \
oled.d \
snake.d \
SPI.d \
timer.d \
uart.d

C_DEPS_AS_ARGS +=  \
ADC.d \
ByggernGruppe48H2015.d \
can.d \
canjoy.d \
font.d \
gui.d \
joystick.d \
main.d \
mcp2515.d \
menu.d \
oled.d \
snake.d \
SPI.d \
timer.d \
uart.d

OUTPUT_FILE_PATH +=ByggernGruppe48H2015.elf

OUTPUT_FILE_PATH_AS_ARGS +=ByggernGruppe48H2015.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler































./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega162 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
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
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="ByggernGruppe48H2015.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega162  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "ByggernGruppe48H2015.elf" "ByggernGruppe48H2015.hex"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "ByggernGruppe48H2015.elf" "ByggernGruppe48H2015.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "ByggernGruppe48H2015.elf" > "ByggernGruppe48H2015.lss"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "ByggernGruppe48H2015.elf" "ByggernGruppe48H2015.srec"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-size.exe" "ByggernGruppe48H2015.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "ByggernGruppe48H2015.elf" "ByggernGruppe48H2015.a" "ByggernGruppe48H2015.hex" "ByggernGruppe48H2015.lss" "ByggernGruppe48H2015.eep" "ByggernGruppe48H2015.map" "ByggernGruppe48H2015.srec" "ByggernGruppe48H2015.usersignatures"
	