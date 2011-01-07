#include <screen.h>

extern "C" void init()
{
    cout.InitScreen();
    
    cout.SetHex(true);  
    cout.puts(123123);
    
    while(1);
}
