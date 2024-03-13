#include "raw.hpp"

namespace terminal
{
    std::tuple<uint16_t, uint16_t> RawTerminal::GetSize()
    {
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        return std::make_tuple(w.ws_col, w.ws_row);
    }

    RawTerminal::RawTerminal()
    {
        tcgetattr(STDIN_FILENO, &oldTermios);
        termios newTermios = oldTermios;
        newTermios.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
        newTermios.c_oflag &= ~(OPOST);
        newTermios.c_cflag |= (CS8);
        newTermios.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
        newTermios.c_cc[VMIN] = 0;
        newTermios.c_cc[VTIME] = 1;
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &newTermios);
        initialized = true;
    }

    RawTerminal::~RawTerminal()
    {
        if (initialized)
        {
            tcsetattr(STDIN_FILENO, TCSAFLUSH, &oldTermios);
        }
    }

    void RawTerminal::ClearScreen()
    {
        std::cout << "\033]1337;ClearScrollback\007";
        std::cout << "\033[2J" << std::flush;
    }

    void RawTerminal::ClearLine()
    {
        std::cout << "\033[2K" << std::flush;
    }

    void RawTerminal::SetCursorPos(uint16_t x, uint16_t y)
    {
        std::cout << "\033[" << y << ";" << x << "H" << std::flush;
    }

    void RawTerminal::HideCursor()
    {
        std::cout << "\033[?25l" << std::flush;
    }

    void RawTerminal::ShowCursor()
    {
        std::cout << "\033[?25h" << std::flush;
    }

    char RawTerminal::WaitForInput()
    {
        int nread;
        char c;
        while ((nread = read(STDIN_FILENO, &c, 1)) != 1)
        {
            if (nread == -1 && errno != EAGAIN)
                exit(1);
        }
        return c;
    }
} // namespace terminal
