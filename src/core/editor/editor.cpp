#include "editor.hpp"
#include <thread>
#include <chrono>
namespace editor
{
    std::string toString(Mode mode)
    {
        switch (mode)
        {
        case Mode::NORMAL:
            return "NORMAL";
        case Mode::INSERT:
            return "INSERT";
        case Mode::VISUAL:
            return "VISUAL";
        case Mode::COMMAND:
            return "COMMAND";
        default:
            return "UNKNOWN";
        }
    }
    Editor::Editor(theme::Theme *theme)
    {
        this->mode = Mode::NORMAL;
        this->command_buffer = new std::string();
        this->terminal = new terminal::RawTerminal();
        this->cursor = new Cursor();
        this->command_bar = new ui::CommandBar(0, 0, 0, 0);
        this->status_bar = new ui::StatusBar(0, 0, 0, 0);
        this->text_buffer = new ui::TextBuffer(0, 0, 0, 0);
        this->editor_theme = theme;
    }

    Editor::~Editor()
    {
        delete this->terminal;
        delete this->command_buffer;
        delete this->cursor;
        delete this->command_bar;
        delete this->status_bar;
        delete this->text_buffer;
    }

    void Editor::SwitchToCommandMode()
    {
        this->mode = Mode::COMMAND;
        this->command_buffer->clear();
        this->command_buffer->push_back(':');
        // TODO make this better
        const auto [x, y] = this->terminal->GetSize();
        this->cursor->MoveTo(this->command_buffer->size() + 1, y);
        this->cursor->SetXRanges(this->command_buffer->size() + 1, x);
        this->cursor->SetYRanges(y, y);
    }

    void Editor::HandleNormalMode(char c)
    {
        if (c == 'i')
        {
            this->mode = Mode::INSERT;
        }
        if (c == 'v')
        {
            this->mode = Mode::VISUAL;
        }
        if (c == ':')
        {
            this->SwitchToCommandMode();
        }

        if (c == 'h')
        {
            this->cursor->MoveLeft();
        }
        if (c == 'j')
        {
            this->cursor->MoveDown();
        }
        if (c == 'k')
        {
            this->cursor->MoveUp();
        }
        if (c == 'l')
        {
            this->cursor->MoveRight();
        }
    }

    void Editor::HandleInsertMode(char c)
    {
        if (c == 'b')
        {
            this->mode = Mode::NORMAL;
        }
    }

    void Editor::HandleVisualMode(char c)
    {
        if (c == 'b')
        {
            this->mode = Mode::NORMAL;
        }
    }

    void Editor::HandleCommandMode(char c)
    {
        if (c == '\r')
        {
            this->mode = Mode::NORMAL;
            this->command_buffer->clear();
        }
        else if (c == CTRL_KEY('c'))
        {
            this->mode = Mode::NORMAL;
            this->command_buffer->clear();
        }
        else
        {
            this->command_buffer->push_back(c);
            this->cursor->MoveRight();
        }
    }

    void Editor::Run()
    {
        const auto [x, y] = this->terminal->GetSize();
        std::cout << "\033]1337;ClearScrollback\007";
        screen::ScreenBuffer buffer = screen::ScreenBuffer(x, y);
        this->cursor->SetXRanges(0, x);
        this->cursor->SetYRanges(0, y - 2);
        this->cursor->MoveTo(0, 0);
        while (1)
        {
            this->cursor->Hide();
            this->cursor->Zero();
            this->terminal->ClearScreen();
            
            this->status_bar->SetXRange(0, x);
            this->status_bar->SetYRange(y - 2, y - 2);
            this->command_bar->SetXRange(0, x);
            this->command_bar->SetYRange(y -1, y-1);
            this->text_buffer->SetXRange(0, x);
            this->text_buffer->SetYRange(0, y - 2);

            this->command_bar->SetCommandBuffer(*command_buffer);
            this->status_bar->SetMode(toString(this->mode));

            this->text_buffer->Draw(&buffer, editor_theme);
            this->status_bar->Draw(&buffer, editor_theme);
            this->command_bar->Draw(&buffer, editor_theme);
            buffer.Draw();
            this->cursor->Show();

            char input = terminal->WaitForInput();
            if (input == CTRL_KEY('c'))
            {
                cursor->Zero();
                terminal->ClearScreen();
                break;
            }
            else
            {
                switch (this->mode)
                {
                case Mode::NORMAL:
                    HandleNormalMode(input);
                    break;
                case Mode::INSERT:
                    HandleInsertMode(input);
                    break;
                case Mode::VISUAL:
                    HandleVisualMode(input);
                    break;
                case Mode::COMMAND:
                    HandleCommandMode(input);
                    break;
                }
            }
        }
    }
}