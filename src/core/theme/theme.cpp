#include "theme.hpp"

namespace theme
{
    Theme Theme::Nightlify()
    {
        return Theme(terminal::Color::FromHex("#011627"),
                     terminal::Color::FromHex("#bdc1c6"),
                     terminal::Color::FromHex("#eeeeee"),
                     terminal::Color::FromHex("#9ca1aa"),
                     terminal::Color::FromHex("#080808"),
                     terminal::Color::FromHex("#b2ceee"),
                     terminal::Color::FromHex("#080808"),
                     terminal::Color::FromHex("#1d3b53"),
                     terminal::Color::FromHex("#fc514e"),
                     terminal::Color::FromHex("#a1cd5e"),
                     terminal::Color::FromHex("#e3d18a"),
                     terminal::Color::FromHex("#82aaff"),
                     terminal::Color::FromHex("#c792ea"),
                     terminal::Color::FromHex("#7fdbca"),
                     terminal::Color::FromHex("#a1aab8"),
                     terminal::Color::FromHex("#7c8f8f"),
                     terminal::Color::FromHex("#ff5874"),
                     terminal::Color::FromHex("#21c7a8"),
                     terminal::Color::FromHex("#ecc48d"),
                     terminal::Color::FromHex("#82aaff"),
                     terminal::Color::FromHex("#ae81ff"),
                     terminal::Color::FromHex("#7fdbca"),
                     terminal::Color::FromHex("#d6deeb"));
    }
}