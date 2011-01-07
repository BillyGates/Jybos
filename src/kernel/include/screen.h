#ifndef SCREEN_H
#define SCREEN_H

namespace driver
{
    namespace std_screen
    {

        enum color
        {
            black = 0,
            blue = 1,
            green = 2,
            cyan = 3,
            red = 4,
            magenta = 5,
            brown = 6,
            light_grey = 7,
            dark_grey = 8,
            light_blue = 9,
            light_green = 10,
            light_cyan = 11,
            light_red = 12,
            light_magenta = 13,
            light_brown = 14,
            white = 15
        };

        class scrn_color
        {
            unsigned char foreground, background;

        public:
            scrn_color();
            scrn_color(int fore, int back);
            void SetForeground(unsigned char fore);
            void SetBackground(unsigned char back);

            unsigned char GetForeground();
            unsigned char GetBackground();


        };

    }
    
    class screen
    {
        char* addr;
        char attrib;
        int x;
        int y;
        bool isHex;

    public:
    
        void InitScreen();
        void putch(char s);
        void puts(const char* s);
        void puts(int i);
        void clear();
        void SetColors(std_screen::scrn_color farbe);	
        void SetHex(bool k);
     };

    
}

extern driver::screen cout;

#endif

