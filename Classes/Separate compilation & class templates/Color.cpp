#include "Color.h"

// Constructor
Color::Color(unsigned char red, unsigned char green, unsigned char blue)
    : red_(red), green_(green), blue_(blue) {}

// Copy constructor
Color::Color(const Color& c)
    : red_(c.red_), green_(c.green_), blue_(c.blue_) {}

// Accessors
unsigned char Color::red() const {
    return red_;
}

unsigned char Color::green() const {
    return green_;
}

unsigned char Color::blue() const {
    return blue_;
}

// Equality test
bool Color::equal_to(const Color& other) const {
    return red_ == other.red_ && green_ == other.green_ && blue_ == other.blue_;
}

// Invert color
void Color::invert() {
    red_ = 255 - red_;
    green_ = 255 - green_;
    blue_ = 255 - blue_;
}

// Static constant definitions
const Color Color::RED   = Color(255, 0, 0);
const Color Color::GREEN = Color(0, 255, 0);
const Color Color::BLUE  = Color(0, 0, 255);
const Color Color::BLACK = Color(0, 0, 0);
const Color Color::WHITE = Color(255, 255, 255);
