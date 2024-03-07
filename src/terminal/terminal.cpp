#include "terminal.hpp"

void disableRawMode()
{
   tcsetattr(STDIN_FILENO, TCSAFLUSH, &old_tio);
}

void Terminal::enableRawMode()
{
    tcgetattr(STDIN_FILENO, &old_tio);
    atexit(disableRawMode);
    struct termios raw = old_tio;
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void Terminal::clearScreen()
{
    write(STDOUT_FILENO, "\x1b[2J", 4);
}

Input Terminal::waitForInput()
{
    Input input;
    read(STDIN_FILENO, &input.raw, 1);
    return input;
}

Terminal::Terminal()
{
    enableRawMode();
}


