#include <screen.h>

using namespace driver;

screen cout;

void screen::InitScreen()
{
    addr = (char*) 0xb8000;
    attrib = (char) 0x07;
    clear();
}

void screen::putch(char s)
{
    addr[2 * (y * 80 + x)] = s;
    addr[2 * (y * 80 + x) + 1] = attrib;
    
    x++;
    
    if(x>80)
    {
        x=0;
        y++;
    }
    
    if (y > 24)
    {
        int i;
        for (i = 0; i < 2 * 24 * 80; i++)
        {
            addr[i] = addr[i + 160];
        }

        for (; i < 2 * 25 * 80; i++)
        {
            addr[i] = 0;
        }
        y--;
    }

}

void screen::puts(const char* s)
{
    while(*s)
    {
        putch(*s++);
    }
}

void screen::clear()
{
    int i;
    for (i = 0; i < 2 * 25 * 80; i++)
    {
        addr[i] = 0;
    }

    x = y = 0;
}

void screen::SetColors(std_screen::scrn_color farbe)
{
    attrib = (farbe.GetBackground() << 4) | (farbe.GetForeground() & 0x0F);    
}


using namespace std_screen;

scrn_color::scrn_color()
{

}

scrn_color::scrn_color(int fore, int back)
{
    SetForeground((unsigned char) fore);
    SetBackground((unsigned char) back);
}

void scrn_color::SetForeground(unsigned char fore)
{
    foreground = fore;
}

void scrn_color::SetBackground(unsigned char back)
{
    background = back;
}

unsigned char scrn_color::GetForeground()
{
    return foreground;
}
            
unsigned char scrn_color::GetBackground()
{
    return background;
}          

