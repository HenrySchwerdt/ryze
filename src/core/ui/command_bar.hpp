#pragma once
#include <string>
#include <iostream>
#include "../screen/screen.hpp"
#include "../theme/theme.hpp"
namespace ui
{
    class CommandBar
    {
    private:
        int x_start, x_end, y_start, y_end;
        std::string command_buffer;
    public:
        CommandBar(int x_start, int x_end, int y_start, int y_end) : x_start(x_start), x_end(x_end), y_start(y_start), y_end(y_end), command_buffer("") {};
        void SetCommandBuffer(std::string command_buffer);
        void SetXRange(int x_start, int x_end);
        void SetYRange(int y_start, int y_end);
        void Draw(screen::ScreenBuffer* buffer, theme::Theme* theme);
    };
}