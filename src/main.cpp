#include "terminal/terminal.hpp"

#include <iostream>

int main() {
    Terminal terminal;
    terminal.clearScreen();
    Input input;
    while((input = terminal.waitForInput()).raw != 'q') {
        std::cout << input.raw;
    }
    return 0;
}
