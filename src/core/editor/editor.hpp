#pragma once
#include "../terminal/terminal.hpp"
#include "cursor.hpp"
#include "../ui/ui.hpp"
#include "../theme/theme.hpp"
#include "../screen/screen.hpp"
#include <string>
#include <iostream>
#define CTRL_KEY(k) ((k) & 0x1f)
namespace editor
{
    enum class Mode : char {
        NORMAL = 0,
        INSERT,
        VISUAL,
        COMMAND
    };
    class Editor
    {
    private:
        Mode mode;
        Cursor* cursor;
        terminal::RawTerminal* terminal;
        ui::StatusBar* status_bar;
        ui::CommandBar* command_bar;
        ui::TextBuffer* text_buffer;
        std::string* command_buffer;
        theme::Theme* editor_theme;
        void SwitchToCommandMode();
        void HandleNormalMode(char c);
        void HandleInsertMode(char c);
        void HandleVisualMode(char c);
        void HandleCommandMode(char c);
    public:
        Editor(theme::Theme* theme);
        ~Editor();
        void Run();
    };
}
