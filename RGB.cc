#include "RGB.h"

//constructor definition
RGB::RGB(int r, int g, int b) : red(r), green(g), blue(b) {}

// getter 
int RGB::getR() const { return red; }
int RGB::getG() const { return green; }
int RGB::getB() const { return blue; }

// setter 
void RGB::setRed(int r) { red = r; }
void RGB::setGreen(int g) { green = g; }
void RGB::setBlue(int b) { blue = b; }

// statuic function 
RGB RGB::WHITE() {
    return RGB(255, 255, 255);  // white 
}

RGB RGB::BLACK() {
    return RGB(0, 0, 0);  // black 
}

RGB RGB::RED() {
    return RGB(255, 0, 0);  // red 
}

RGB RGB::GREEN() {
    return RGB(0, 255, 0);  // green 
}

RGB RGB::BLUE() {
    return RGB(0, 0, 255);  // blue 
}
