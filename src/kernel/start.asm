;Diese Datei enthält die start Funktion, die den Stack initialisiert und den Kernel aufruft.

SECTION .multiboot
%define MB_MAGIC 0x1BADB002
%define MB_FLAGS 0x0
%define MB_CHECKSUM -(MB_MAGIC + MB_FLAGS)

; Der Multiboot-Header
ALIGN 4
dd MB_MAGIC
dd MB_FLAGS
dd MB_CHECKSUM

SECTION .text

EXTERN init
GLOBAL start

start:
    ; Stack initialisieren
    mov esp, kernel_stack

    call init

    jmp $

SECTION .bss
resb 8192
kernel_stack:
