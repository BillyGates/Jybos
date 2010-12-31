#include <screen.h>

extern "C" void init()
{
    cout.InitScreen();
      
    cout.puts("Hello World");
    
    while(1);
}
