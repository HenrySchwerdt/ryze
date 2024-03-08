#pragma once

namespace terminal
{
    enum class KeyModifier : unsigned char
    {
        None = 0,
        Ctrl = 1 << 0,
        Alt = 1 << 1,
        Shift = 1 << 2
    };

    enum class KeyType : unsigned char {
        None = 0,
        Enter = 1,
        Backspace = 2,
        Tab = 3,
        Escape = 4,
        Space = 5,
        F1 = 6,
        F2 = 7,
        F3 = 8,
        F4 = 9,
        F5 = 10,
        F6 = 11,
        F7 = 12,
        F8 = 13,
        F9 = 14,
        F10 = 15,
        F11 = 16,
        F12 = 17,
        Up = 18,
        Down = 19,
        Right = 20,
        Left = 21,
        Insert = 22,
        Delete = 23,
        Home = 24,
        End = 25,
        PageUp = 26,
        PageDown = 27,
        PrintScreen = 28,
        ScrollLock = 29,
        Pause = 30,
        NumLock = 31,
        CapsLock = 32,
        Menu = 33,
        NumPad0 = 34,
        NumPad1 = 35,
        NumPad2 = 36,
        NumPad3 = 37,
        NumPad4 = 38,
        NumPad5 = 39,
        NumPad6 = 40,
        NumPad7 = 41,
        NumPad8 = 42,
        NumPad9 = 43,
        NumPadAdd = 44,
        NumPadSubtract = 45,
        NumPadMultiply = 46,
        NumPadDivide = 47,
        NumPadEnter = 48,
        NumPadDecimal = 49,
        NumPadEqual = 50,
        NumPadComma = 51,
        NumPadParenthesisLeft = 52,
        NumPadParenthesisRight = 53,
        NumPadSpace = 54,
        NumPadTab = 55,
        NumPadF1 = 56,
        NumPadF2 = 57,
        NumPadF3 = 58,
        NumPadF4 = 59,
        NumPadHome = 60,
        NumPadEnd = 61,
        NumPadPageUp = 62,
        NumPadPageDown = 63,
        NumPadInsert = 64,
        NumPadDelete = 65,
        NumPadUp = 66,
        Char = 67
    };
    
    
    class KeyEvent 
    {
        private: 
            unsigned char m_code;
            KeyModifier m_modifier;
            KeyType m_keytype;
        public:
            KeyEvent(unsigned char code, KeyModifier modifier, KeyType keytype) : m_code(code), m_modifier(modifier), m_keytype(keytype) {}
            unsigned char GetCode() { return m_code; }
            KeyModifier GetModifier() { return m_modifier; }
            KeyType GetKeyType() { return m_keytype; }
    };
}
