/*Diese Datei enthält die Hauptfunktion des Kernels.
  In ihr werden Multitasking, GDT, IDT und die 
  nötigsten Treiber initialisiert.
*/

#include <screen.h>
#include <protect.h>

kernel::GDT gdt;

extern "C" void init()
{
    cout.InitScreen();
    gdt.Init();    

    cout.SetHex(true);  
    cout.puts(123123);
    
    while(1);
}
