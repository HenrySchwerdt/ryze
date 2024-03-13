#include "cursor.hpp"

namespace editor
{
    Cursor::Cursor()
    {
        this->x = 1;
        this->y = 1;
        this->mode = Mode::BLOCK;
    }

    void Cursor::SetXRanges(int min_x, int max_x)
    {
        this->min_x = min_x;
        this->max_x = max_x;
    }

    void Cursor::SetYRanges(int min_y, int max_y)
    {
        this->min_y = min_y;
        this->max_y = max_y;
    }

    void Cursor::MoveUp(int delta)
    {
        this->y -= delta;
        if (this->y < this->min_y)
        {
            this->y = this->min_y;
        }
        terminal::RawTerminal::SetCursorPos(this->x, this->y);
    }

    void Cursor::MoveDown(int delta)
    {
        this->y += delta;
        if (this->y > this->max_y)
        {
            this->y = this->max_y;
        }
        terminal::RawTerminal::SetCursorPos(this->x, this->y);
    }

    void Cursor::MoveLeft(int delta)
    {
        this->x -= delta;
        if (this->x < this->min_x)
        {
            this->x = this->min_x;
        }
        terminal::RawTerminal::SetCursorPos(this->x, this->y);
    }

    void Cursor::MoveRight(int delta)
    {
        this->x += delta;
        if (this->x > this->max_x)
        {
            this->x = this->max_x;
        }
        terminal::RawTerminal::SetCursorPos(this->x, this->y);
    }

    void Cursor::MoveTo(int x, int y)
    {
        this->x = x;
        this->y = y;
        terminal::RawTerminal::SetCursorPos(this->x, this->y);
    }

    void Cursor::Hide()
    {
        terminal::RawTerminal::HideCursor();
    }

    void Cursor::Show()
    {
        terminal::RawTerminal::ShowCursor();
        terminal::RawTerminal::SetCursorPos(this->x, this->y);
    }

    void Cursor::Zero() {
        terminal::RawTerminal::SetCursorPos(1, 1);
    }

    void Cursor::SilentMove(int x, int y)
    {
        terminal::RawTerminal::SetCursorPos(x, y);
    }
}