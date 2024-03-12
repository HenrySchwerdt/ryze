#pragma once
#include <string>
#include <iostream>
#include "../terminal/terminal.hpp"
#include "../screen/screen.hpp"
#include "../theme/theme.hpp"
namespace ui
{
    class StatusBar
    {
    private:
        int x_start, x_end, y_start, y_end;
        int highlight_width;
        std::string mode;
        int file_x, file_y;
    public:
        StatusBar(int x_start, int x_end, int y_start, int y_end);
        void SetXRange(int x_start, int x_end);
        void SetYRange(int y_start, int y_end);
        void SetFilePos(int x, int y);
        void SetMode(std::string mode);
        void Draw(screen::ScreenBuffer* buffer, theme::Theme* theme);
    };
}