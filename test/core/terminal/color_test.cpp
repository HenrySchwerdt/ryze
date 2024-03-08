#include "../../src/core/terminal/terminal.hpp"
#include <gtest/gtest.h>

class ColorTest : public ::testing::Test {
protected:
    void SetUp() override {
    }
    void TearDown() override {
    }
};

// Test case for ToFgAnsi method
TEST_F(ColorTest, ToFgAnsiTest) {
    // Create a color object
    terminal::Color color = terminal::Color::FromRgb(255, 0, 0);

    // Check if ToFgAnsi generates correct ANSI escape sequence
    EXPECT_EQ(color.ToFgAnsi(), "\033[38;2;255;0;0m");
}

// Test case for ToBgAnsi method
TEST_F(ColorTest, ToBgAnsiTest) {
    // Create a color object
    terminal::Color color = terminal::Color::FromRgb(0, 255, 0);

    // Check if ToBgAnsi generates correct ANSI escape sequence
    EXPECT_EQ(color.ToBgAnsi(), "\033[48;2;0;255;0m");
}

// Test case for FromHex method
TEST_F(ColorTest, FromHexTest) {
    // Create a color object from hex string
    terminal::Color color = terminal::Color::FromHex("#00FF00");

    // Check if the color components are correctly set
    EXPECT_EQ(color.getR(), 0);
    EXPECT_EQ(color.getG(), 255);
    EXPECT_EQ(color.getB(), 0);
}

// Test case for FromRgb method
TEST_F(ColorTest, FromRgbTest) {
    // Create a color object from RGB components
    terminal::Color color = terminal::Color::FromRgb(0, 0, 255);

    // Check if the color components are correctly set
    EXPECT_EQ(color.getR(), 0);
    EXPECT_EQ(color.getG(), 0);
    EXPECT_EQ(color.getB(), 255);
}