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
../Display \
../Communication


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../Communication/can.c \
../Communication/canjoy.c \
../Communication/mcp2515.c \
../Communication/SPI.c \
../Communication/uart.c \
../Display/font.c \
../Display/gui.c \
../Display/oled.c \
../eeprom.c \
../game.c \
../input.c \
../main.c \
../menu.c \
../snake.c \
../sram.c \
../timer.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
Communication/can.o \
Communication/canjoy.o \
Communication/mcp2515.o \
Communication/SPI.o \
Communication/uart.o \
Display/font.o \
Display/gui.o \
Display/oled.o \
eeprom.o \
game.o \
input.o \
main.o \
menu.o \
snake.o \
sram.o \
timer.o

OBJS_AS_ARGS +=  \
Communication/can.o \
Communication/canjoy.o \
Communication/mcp2515.o \
Communication/SPI.o \
Communication/uart.o \
Display/font.o \
Display/gui.o \
Display/oled.o \
eeprom.o \
game.o \
input.o \
main.o \
menu.o \
snake.o \
sram.o \
timer.o

C_DEPS +=  \
Communication/can.d \
Communication/canjoy.d \
Communication/mcp2515.d \
Communication/SPI.d \
Communication/uart.d \
Display/font.d \
Display/gui.d \
Display/oled.d \
eeprom.d \
game.d \
input.d \
main.d \
menu.d \
snake.d \
sram.d \
timer.d

C_DEPS_AS_ARGS +=  \
Communication/can.d \
Communication/canjoy.d \
Communication/mcp2515.d \
Communication/SPI.d \
Communication/uart.d \
Display/font.d \
Display/gui.d \
Display/oled.d \
eeprom.d \
game.d \
input.d \
main.d \
menu.d \
snake.d \
sram.d \
timer.d

OUTPUT_FILE_PATH +=ByggernGruppe48H2015.elf

OUTPUT_FILE_PATH_AS_ARGS +=ByggernGruppe48H2015.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler

































Communication/%.o: ../Communication/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=4915200  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega162 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Display/%.o: ../Display/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=4915200  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega162 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=4915200  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega162 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
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
	