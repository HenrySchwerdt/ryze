#include "core/terminal/terminal.hpp"

#include <iostream>
#include <string>
#include <stdio.h>
#define CTRL_KEY(k) ((k) & 0x1f)

void drawLines(int height) {
    for (int i = 0; i < height - 2; i++) {
        std::cout << "~\r\n";
    }
}

void drawStatusBar(int width) {
    std::cout << NAVY.ToBgAnsi();
    for (int i = 0; i < width; i++) {
        std::cout << " ";
    }
    std::cout << RESET_BG << "\r\n\r\n";
}

int main()
{

    terminal::RawTerminal terminal;
   
    int cursorx = 0;
    while (1)
    {
        const auto [x,y] = terminal.GetSize();
        terminal.HideCursor();
        terminal.SetCursorPos(0, 0);
        terminal.ClearScreen();
        drawLines(y);
        drawStatusBar(x);
        char input = terminal.WaitForInput();
        if (input == CTRL_KEY('c'))
        {
            terminal.ClearScreen();
            break;
        } else {
            cursorx++;
        }
    }
    terminal.~RawTerminal();
    return 0;
}
