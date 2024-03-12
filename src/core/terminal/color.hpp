#pragma once
#include <string>
namespace terminal
{

    class Color
    {
    private:
        unsigned char r;
        unsigned char g;
        unsigned char b;
        Color(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {}

    public:
        static Color FromHex(std::string hex);
        static Color FromRgb(unsigned char r, unsigned char g, unsigned char b);
        unsigned char getR() const { return r; }
        unsigned char getG() const { return g; }
        unsigned char getB() const { return b; }
        std::string ToFgAnsi() const;
        std::string ToBgAnsi() const;
        bool operator==(const Color &other) const
        {
            return (r == other.getR()) && (g == other.getG()) && (b == other.getB());
        }
        bool operator!=(const Color &other) const
        {
            return !(operator==(other));
        }
    };

#define BLACK terminal::Color::FromRgb(0, 0, 0)
#define WHITE terminal::Color::FromRgb(255, 255, 255)
#define RED terminal::Color::FromRgb(255, 0, 0)
#define GREEN terminal::Color::FromRgb(0, 255, 0)
#define BLUE terminal::Color::FromRgb(0, 0, 255)
#define YELLOW terminal::Color::FromRgb(255, 255, 0)
#define MAGENTA terminal::Color::FromRgb(255, 0, 255)
#define CYAN terminal::Color::FromRgb(0, 255, 255)
#define GRAY terminal::Color::FromRgb(128, 128, 128)
#define LIGHT_GRAY terminal::Color::FromRgb(192, 192, 192)
#define LIGHT_RED terminal::Color::FromRgb(255, 128, 128)
#define LIGHT_GREEN terminal::Color::FromRgb(128, 255, 128)
#define LIGHT_BLUE terminal::Color::FromRgb(128, 128, 255)
#define LIGHT_YELLOW terminal::Color::FromRgb(255, 255, 128)
#define LIGHT_MAGENTA terminal::Color::FromRgb(255, 128, 255)
#define LIGHT_CYAN terminal::Color::FromRgb(128, 255, 255)
#define DARK_GRAY terminal::Color::FromRgb(64, 64, 64)
#define DARK_RED terminal::Color::FromRgb(128, 0, 0)
#define DARK_GREEN terminal::Color::FromRgb(0, 128, 0)
#define DARK_BLUE terminal::Color::FromRgb(0, 0, 128)
#define DARK_YELLOW terminal::Color::FromRgb(128, 128, 0)
#define DARK_MAGENTA terminal::Color::FromRgb(128, 0, 128)
#define DARK_CYAN terminal::Color::FromRgb(0, 128, 128)
#define ORANGE terminal::Color::FromRgb(255, 165, 0)
#define PINK terminal::Color::FromRgb(255, 192, 203)
#define PURPLE terminal::Color::FromRgb(128, 0, 128)
#define BROWN terminal::Color::FromRgb(165, 42, 42)
#define OLIVE terminal::Color::FromRgb(128, 128, 0)
#define TEAL terminal::Color::FromRgb(0, 128, 128)
#define NAVY terminal::Color::FromRgb(0, 0, 128)
#define MAROON terminal::Color::FromRgb(128, 0, 0)
#define LIME terminal::Color::FromRgb(0, 255, 0)
#define AQUA terminal::Color::FromRgb(0, 255, 255)
#define SILVER terminal::Color::FromRgb(192, 192, 192)

#define RESET_FG std::string("\033[39m")
#define RESET_BG std::string("\033[49m")
}
