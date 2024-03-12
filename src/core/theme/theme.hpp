#pragma once

#include "../terminal/terminal.hpp"

namespace theme
{
    struct Theme
    {
        terminal::Color background;
        terminal::Color foreground;

        terminal::Color bold;
        terminal::Color cursor;
        terminal::Color cursor_text;

        terminal::Color selection;
        terminal::Color selection_text;

        terminal::Color color1;
        terminal::Color color2;
        terminal::Color color3;
        terminal::Color color4;
        terminal::Color color5;
        terminal::Color color6;
        terminal::Color color7;
        terminal::Color color8;
        terminal::Color color9;
        terminal::Color color10;
        terminal::Color color11;
        terminal::Color color12;
        terminal::Color color13;
        terminal::Color color14;
        terminal::Color color15;
        terminal::Color color16;

        Theme(terminal::Color background,
              terminal::Color foreground,
              terminal::Color bold,
              terminal::Color cursor,
              terminal::Color cursor_text,
              terminal::Color selection,
              terminal::Color selection_text,
              terminal::Color color1,
              terminal::Color color2,
              terminal::Color color3,
              terminal::Color color4,
              terminal::Color color5,
              terminal::Color color6,
              terminal::Color color7,
              terminal::Color color8,
              terminal::Color color9,
              terminal::Color color10,
              terminal::Color color11,
              terminal::Color color12,
              terminal::Color color13,
              terminal::Color color14,
              terminal::Color color15,
              terminal::Color color16) : background(background),
                                         foreground(foreground), bold(bold),
                                         cursor(cursor),
                                         cursor_text(cursor_text),
                                         selection(selection),
                                         selection_text(selection_text),
                                         color1(color1),
                                         color2(color2),
                                         color3(color3),
                                         color4(color4),
                                         color5(color5),
                                         color6(color6),
                                         color7(color7),
                                         color8(color8),
                                         color9(color9),
                                         color10(color10),
                                         color11(color11),
                                         color12(color12),
                                         color13(color13),
                                         color14(color14),
                                         color15(color15),
                                         color16(color16) {}

        static Theme Nightlify();
    };
}