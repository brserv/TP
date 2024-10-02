
# Compiler
CC = arm-none-eabi-gcc

# Linker
LD = arm-none-eabi-gcc

# Flags
CFLAGS = -mcpu=cortex-m4 -c
LDFLAGS = -mcpu=cortex-m4 -T STM32F446RETX_FLASH.ld --specs=nosys.specs

# Source files
SRC_ASM = startup_stm32f446retx.s
SRC_C = main.c

# Object files
OBJ_ASM = $(SRC_ASM:.s=.o)
OBJ_C = $(SRC_C:.c=.o)

# Output files
TARGET_ELF = STM32F446.elf
TARGET_BIN = STM32F446.bin

all: $(TARGET_BIN)

$(TARGET_BIN): $(TARGET_ELF)
	@echo "Generating binary file..."
	@arm-none-eabi-objcopy -O binary $(TARGET_ELF) $(TARGET_BIN)
	@echo "Binary file generated: $(TARGET_BIN)"

$(TARGET_ELF): $(OBJ_ASM) $(OBJ_C)
	@echo "Linking..."
	@$(LD) $(LDFLAGS) -o $(TARGET_ELF) $(OBJ_ASM) $(OBJ_C)
	@echo "Executable file generated: $(TARGET_ELF)"

$(OBJ_ASM): $(SRC_ASM)
	@echo "Compiling assembly file: $<"
	@$(CC) $(CFLAGS) $< -o $@

$(OBJ_C): $(SRC_C)
	@echo "Compiling C file: $<"
	@$(CC) $(CFLAGS) $< -o $@

clean:
	@echo "Cleaning up..."
	@rm -f $(OBJ_ASM) $(OBJ_C) $(TARGET_ELF) $(TARGET_BIN)
	@echo "Cleaned up."
