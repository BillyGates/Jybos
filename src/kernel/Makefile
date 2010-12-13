SRCS = $(wildcard *.asm *.c *.cpp *.S)
OBJS = $(addsuffix .o,$(basename $(SRCS)))
 
CC = gcc
CPPC = g++
LD = ld
ASM = nasm

ASFLAGS = -m32
ASMFLAGS = -felf
CFLAGS = -m32 -Wall -g -fno-stack-protector -I include
CPPFLAGS = -m32 -I include -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wall -Wextra -pedantic-errors
LDFLAGS = -melf_i386 -T kernel.ld

all: kernel

kernel: $(OBJS)
	@$(LD) $(LDFLAGS) -o $@ $^

%.o: %.asm
	@$(ASM) $(ASMFLAGS) -o $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $^

%.o: %.cpp
	@$(CPPC) $(CPPFLAGS) -c -o $@ $^

%.o: %.S
	@$(CC) $(ASFLAGS) -c -o $@ $^

clean:
	@rm $(OBJS)

.PHONY: clean all
