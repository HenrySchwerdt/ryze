#include "status_bar.hpp"

namespace ui
{
    StatusBar::StatusBar(int x_start, int x_end, int y_start, int y_end)
    {
        this->x_start = x_start;
        this->x_end = x_end;
        this->y_start = y_start;
        this->y_end = y_end;
        this->highlight_width = 10;
        this->mode = "NORMAL";
        this->file_x = 1;
        this->file_y = 1;
    }

    void StatusBar::SetXRange(int x_start, int x_end)
    {
        this->x_start = x_start;
        this->x_end = x_end;
    }

    void StatusBar::SetYRange(int y_start, int y_end)
    {
        this->y_start = y_start;
        this->y_end = y_end;
    }

    void StatusBar::SetFilePos(int x, int y)
    {
        this->file_x = x;
        this->file_y = y;
    }

    void StatusBar::SetMode(std::string mode)
    {
        this->mode = mode;
    }

    void StatusBar::Draw(screen::ScreenBuffer *buffer, theme::Theme *theme)
    {

        buffer->SetCell(0, y_start, screen::Cell(" ", theme->foreground, theme->color5));
        for (int x = 1; x < this->mode.size() + 1; x++)
        {
            buffer->SetCell(x, y_start, screen::Cell(std::string(1, this->mode.at(x - 1)), theme->color1, theme->color5));
        }
        buffer->SetCell(this->mode.size() + 1, y_start, screen::Cell(" ", theme->foreground, theme->color5));
        buffer->SetCell(this->mode.size() + 2, y_start, screen::Cell(TRIANGLE_RIGHT, theme->color5, theme->color1));
        for (int x = this->mode.size() + 3; x < this->x_end - this->highlight_width; x++)
        {
            buffer->SetCell(x, y_start, screen::Cell(" ", theme->color1, theme->color1));
        }
        buffer->SetCell(this->x_end - this->highlight_width, y_start, screen::Cell(TRIANGLE_LEFT, theme->color5, theme->color1));
        buffer->SetCell(this->x_end - this->highlight_width + 1, y_start, screen::Cell(" ", theme->foreground, theme->color5));
        buffer->SetCell(this->x_end - this->highlight_width + 2, y_start, screen::Cell(std::string(1, this->file_x + '0'), theme->color1, theme->color5));
        buffer->SetCell(this->x_end - this->highlight_width + 3, y_start, screen::Cell(":", theme->foreground, theme->color5));
        buffer->SetCell(this->x_end - this->highlight_width + 4, y_start, screen::Cell(std::string(1, this->file_y + '0'), theme->color1, theme->color5));
        for (int x = this->x_end - this->highlight_width + 5; x < this->x_end; x++)
        {
            buffer->SetCell(x, y_start, screen::Cell(" ", theme->foreground, theme->color5));
        }
    }

}
