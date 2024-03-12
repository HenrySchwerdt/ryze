#pragma once

#include <termios.h>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <cstdint>
#include <tuple>
#include <fcntl.h> 
#include "event.hpp"

namespace terminal
{
    class RawTerminal
    {
        private:
            termios oldTermios;
            bool initialized;
        public:
            static std::tuple<uint16_t, uint16_t> GetSize();
            void ClearScreen();
            void ClearLine();
            static void SetCursorPos(uint16_t x, uint16_t y);
            static void HideCursor();
            RawTerminal();
            static void ShowCursor();
            char WaitForInput();
            ~RawTerminal();
    };
}

