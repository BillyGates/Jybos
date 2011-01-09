#ifndef PROTECT_H
#define PROTECT_H

// GDT Flags
#define GDT_FLAG_DATASEGMENT 0x02
#define GDT_FLAG_CODESEGMENT 0x0A
#define GDT_FLAG_TSSSEGMENT  0x09
#define GDT_FLAG_SEGMENT     0x10
#define GDT_FLAG_RING0       0x00
#define GDT_FLAG_RING3       0x60
#define GDT_FLAG_PRESENT     0x80
#define GDT_FLAG_4K          0x800
#define GDT_FLAG_32_BIT      0x400


namespace kernel
{
    class GDT
    {
        
       public:
              virtual void SetEntry(unsigned int num, unsigned int base, unsigned int limit, unsigned char access, unsigned char gran);
              virtual void Init();

    };

    
}

#endif
