#pragma once
#include <cstdint>
#include <vector>
#include <string>
#include <iostream>
#include "../terminal/terminal.hpp"

namespace screen {
    class Cell {
    private:
        char character;
        terminal::Color fg_color;
        terminal::Color bg_color;

    public:
        Cell(char character, terminal::Color fg_color, terminal::Color bg_color) : character(character), fg_color(fg_color), bg_color(bg_color) {};
        char GetCharacter() const;
        terminal::Color GetFgColor() const;
        terminal::Color GetBgColor() const;
        void Print() const;
    };
    class ScreenBuffer {
    private:
        int width;
        int height;
        std::vector<Cell> buffer;
    public:
        ScreenBuffer(int width, int height);
        ~ScreenBuffer();
        void SetCell(int x, int y, const Cell& cell);
        const Cell& GetCell(int x, int y);
        void Draw() const;
    };
};