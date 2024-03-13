#include "command_bar.hpp"

namespace ui
{

    void CommandBar::SetXRange(int x_start, int x_end)
    {
        this->x_start = x_start;
        this->x_end = x_end;
    }

    void CommandBar::SetYRange(int y_start, int y_end)
    {
        this->y_start = y_start;
        this->y_end = y_end;
    }

    void CommandBar::SetCommandBuffer(std::string command_buffer)
    {
        this->command_buffer = command_buffer;
    }

    void CommandBar::Draw(screen::ScreenBuffer *buffer, theme::Theme *theme)
    {

        for (int x = this->x_start; x < this->command_buffer.size() + this->x_start && this->command_buffer.size() < this->x_end; x++)
        {
            buffer->SetCell(x, y_start, screen::Cell(std::string(1, this->command_buffer[x]), theme->foreground, theme->background));
        }

        for (int x = this->command_buffer.size(); x < this->x_end; x++)
        {
            buffer->SetCell(x, y_start, screen::Cell(" ", theme->foreground, theme->background));
        }
    }
}