BUILD_DIR?=build/
ASM?=nasm
ASMFLAGS=-f obj
CC16?=/usr/bin/watcom/binl/wcc
CFLAGS16?=-4 -d3 -s -wx -ms -zl -zq -za99
LD16?=/usr/bin/watcom/binl/wlink

SRC_C=$(wildcard *.c)
SRC_ASM=$(wildcard *.asm)
OBJ_C=$(patsubst %.c, $(BUILD_DIR)/stage2/c/%.obj, $(SRC_C))
OBJ_ASM=$(patsubst %.asm, $(BUILD_DIR)/stage2/asm/%.obj, $(SRC_ASM))

.PHONY: all stage2 clean always

all: stage2

stage2: $(BUILD_DIR)/stage2.bin

$(BUILD_DIR)/stage2.bin: $(OBJ_C) $(OBJ_ASM)
	$(LD16) NAME $(BUILD_DIR)/stage2.bin FILE \{ $(OBJ_C) $(OBJ_ASM) \} OPTION MAP=$(BUILD_DIR)/stage2.map @linker.lnk

$(BUILD_DIR)/stage2/c/%.obj: %.c always
	$(CC16) $(CFLAGS16) -fo=$@ $<

$(BUILD_DIR)/stage2/asm/%.obj: %.asm always
	$(ASM) $(ASMFLAGS) -o $@ $<

always:
	mkdir -p $(BUILD_DIR)/stage2/c
	mkdir -p $(BUILD_DIR)/stage2/asm

clean:
	rm -f $(BUILD_DIR)/stage2.bin
