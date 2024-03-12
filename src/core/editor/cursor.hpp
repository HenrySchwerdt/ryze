#pragma once
#include "../terminal/terminal.hpp"
namespace editor
{
    class Cursor
    {
    enum class Mode {
        BLOCK,
        BLINKING_BLOCK,
        BLINKING_LINE,
    };
    private:
        int x;
        int y;
        int min_x, min_y;
        int max_x, max_y;
        Mode mode;

    public:
        Cursor();
        void SetXRanges(int min_x, int max_x);
        void SetYRanges(int min_y, int max_y);
        void MoveUp(int delta = 1);
        void MoveDown(int delta = 1);
        void MoveLeft(int delta = 1);
        void MoveRight(int delta = 1);
        void MoveTo(int x, int y);
        void Hide();
        void Show();
        void Zero();
        void SilentMove(int x, int y);
    };
}