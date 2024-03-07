#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
static struct termios old_tio;

typedef struct Input {
    char raw;
} Input;

class Terminal 
{
private: 
    void enableRawMode(); 
public:
    Terminal();
    Input waitForInput();
    void clearScreen();

};





#endif
