#include "text_buffer.hpp"


namespace ui {
    void TextBuffer::SetText(std::string text) {
        this->text = text;
    }

    void TextBuffer::SetXRange(int x_start, int x_end) {
        this->x_start = x_start;
        this->x_end = x_end;
    }

    void TextBuffer::SetYRange(int y_start, int y_end) {
        this->y_start = y_start;
        this->y_end = y_end;
    }

    void TextBuffer::Draw(screen::ScreenBuffer* buffer, theme::Theme* theme) {
        for (int y = this->y_start; y < this->y_end; y++) {
            for (int x = this->x_start; x < this->x_end; x++) {
                if (x == this->x_start) {
                    buffer->SetCell(x, y, screen::Cell('~', theme->color1, theme->background));
                    continue;
                }
                buffer->SetCell(x, y, screen::Cell(' ', theme->foreground, theme->background));
            }
        }
    }
}