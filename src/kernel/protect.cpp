/*Diese Datei enthält die Klassen und Funktionen die
  für die eigenarten des Protected Mode zuständig sind.
  (GDT, IDT, PIC, IRQ)
*/

#include <protect.h>
#include <screen.h>

typedef unsigned char  UCHAR; 
typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int   uint32_t;
typedef          int   size_t; 


#define PACKED __attribute__((packed))

extern "C" void gdt_flush(unsigned int);

struct gdt_entry_struct
{
   uint16_t limit_low;           // Die "lower" 16 bits des Limits
   uint16_t base_low;            // Die "lower" 16 bits der Basis
   uint8_t  base_middle;         // Die folgenden 8 bits
   uint8_t  access;
   uint8_t  granularity;
   uint8_t  base_high;
}PACKED;
typedef struct gdt_entry_struct gdt_entry_t; 


struct gdt_ptr_struct
{
   uint16_t limit;               // Die "upper" 16 bits der selector limits.
   uint32_t base;                // Die Adresse der ersten gdt_entry_t Struktur.
}
PACKED;
typedef struct gdt_ptr_struct gdt_ptr_t; 

gdt_ptr_t gp;

using namespace kernel;

 gdt_entry_t gdt_entries[5];

void GDT::SetEntry(uint32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran)
{
   gdt_entries[num].base_low    = (base & 0xFFFF);
   gdt_entries[num].base_middle = (base >> 16) & 0xFF;
   gdt_entries[num].base_high   = (base >> 24) & 0xFF;

   gdt_entries[num].limit_low   = (limit & 0xFFFF);
   gdt_entries[num].granularity = (limit >> 16) & 0x0F;

   gdt_entries[num].granularity |= gran & 0xF0;
   gdt_entries[num].access      = access;
   
}


void GDT::Init()
{
    gp.limit = (sizeof(gdt_entry_t) * 5) - 1;
    gp.base  = (uint32_t)&gdt_entries;

    SetEntry(0, 0, 0, 0, 0);                // Null segment
    SetEntry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
    SetEntry(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment
    SetEntry(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment
    SetEntry(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment

     gdt_flush((unsigned int)&gp);

}

