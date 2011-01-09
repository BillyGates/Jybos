;Diese Datei enthält Funktionen zum Umgang mit Interrupts, GDT und IDT.

[global gdt_flush]

gdt_flush:
   mov eax, [esp+4]  ; Pointer zur GDT nehmen
   lgdt [eax]        ; neuen GDT pointer laden

   mov ax, 0x10      ; 0x10 unser Offset in gdt
   mov ds, ax        ; Alle Selektoren laden
   mov es, ax
   mov fs, ax
   mov gs, ax
   mov ss, ax
   jmp 0x08:.flush   ; Far jump!
.flush:
   ret
