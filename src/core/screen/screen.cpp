#include "screen.hpp"

namespace screen
{

    terminal::Color Cell::GetBgColor() const
    {
        return bg_color;
    }

    terminal::Color Cell::GetFgColor() const
    {
        return fg_color;
    }

    std::string Cell::GetCharacter() const
    {
        return character;
    }

    void Cell::Print() const
    {
        std::cout << fg_color.ToFgAnsi();
        std::cout << bg_color.ToBgAnsi();
        std::cout << character;
        std::cout << RESET_FG;
        std::cout << RESET_BG;
        std::cout.flush();
    }

    ScreenBuffer::ScreenBuffer(int width, int height)
    {
        this->width = width;
        this->height = height;
        buffer.resize(height * width, Cell(" ", WHITE, YELLOW));
    }

    ScreenBuffer::~ScreenBuffer()
    {
    }

    void ScreenBuffer::SetCell(int x, int y, const Cell &cell)
    {
        if (x >= 0 && x < width && y >= 0 && y < height)
        {
            buffer.at(y * width + x) = cell;
        }
    }

    void ScreenBuffer::Draw() const
    {
        terminal::RawTerminal::SetCursorPos(1,1);
        for (int y = 0; y < height; y++)
        {
            std::string line;
            terminal::Color current_bg_color = buffer.at(y * width).GetBgColor();
            terminal::Color current_fg_color = buffer.at(y * width).GetFgColor();
            line += current_bg_color.ToBgAnsi() + current_fg_color.ToFgAnsi() + buffer.at(y * width).GetCharacter();

            for (int x = 1; x < width; x++)
            {
                const terminal::Color &bg_color = buffer.at(y * width + x).GetBgColor();
                const terminal::Color &fg_color = buffer.at(y * width + x).GetFgColor();

                if (bg_color != current_bg_color || fg_color != current_fg_color)
                {
                    line += RESET_FG + RESET_BG + bg_color.ToBgAnsi() + fg_color.ToFgAnsi();
                    current_bg_color = bg_color;
                    current_fg_color = fg_color;
                }
                line += buffer.at(y * width + x).GetCharacter();
            }

            if (y != height - 1)
                line += "\r\n";
            std::cout << line;
        }
       
    }

    const Cell &ScreenBuffer::GetCell(int x, int y)
    {
        return buffer.at(y * width + x);
    }
}