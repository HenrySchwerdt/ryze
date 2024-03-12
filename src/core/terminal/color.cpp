#include "color.hpp"

namespace terminal
{
    std::string Color::ToFgAnsi() const
    {
        return "\033[38;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m";
    }

    std::string Color::ToBgAnsi() const
    {
        return "\033[48;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m";
    }

    Color Color::FromHex(std::string hex)
    {
        if (hex[0] == '#')
        {
            hex = hex.substr(1);
        }
        unsigned char r = std::stoi(hex.substr(0, 2), nullptr, 16);
        unsigned char g = std::stoi(hex.substr(2, 2), nullptr, 16);
        unsigned char b = std::stoi(hex.substr(4, 2), nullptr, 16);
        return Color(r, g, b);
    }

    
    Color Color::FromRgb(unsigned char r, unsigned char g, unsigned char b)
    {
        return Color(r, g, b);
    }
}