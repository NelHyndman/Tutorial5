#include "TextArea.h"
#include <X11/Xlib.h>
#include <iostream>
#include "defs.h"


// no argument constructor
TextArea::TextArea()
    : x(0), y(0), width(100), height(50), text("Default"), id("default"), 
      fill(RGB::WHITE()), border(RGB::BLACK()) {}

TextArea::TextArea(int x, int y, int width, int height, std::string id, std::string label)
    : x(x), y(y), width(width), height(height), text(label), id(id),
      fill(RGB::BLACK()), border(RGB::BLACK()) {}  // Default fill and border

TextArea::TextArea(const Rectangle& rect, const std::string& id, const std::string& text)
    : x(rect.x), y(rect.y), width(rect.width), height(rect.height),
      text(text), id(id), fill(RGB::BLACK()), border(RGB::BLACK()) {}


// copy constructor
TextArea::TextArea(const TextArea& other)
    : x(other.x), y(other.y), width(other.width), height(other.height),
      text("DUPLICATE"), id(other.id), fill(other.fill), border(other.border) {}

// getters
int TextArea::getX() const { return x; }
int TextArea::getY() const { return y; }
int TextArea::getWidth() const { return width; }
int TextArea::getHeight() const { return height; }
std::string TextArea::getText() const { return text; }
std::string TextArea::getId() const { return id; }
RGB TextArea::getFill() const { return fill; }
RGB TextArea::getBorder() const { return border; }

// setters
void TextArea::setX(int newX) { x = newX; }
void TextArea::setY(int newY) { y = newY; }
void TextArea::setWidth(int newWidth) { width = newWidth; }
void TextArea::setHeight(int newHeight) { height = newHeight; }
void TextArea::setText(const std::string& newText) { text = newText; }
void TextArea::setId(const std::string& newId) { id = newId; }
void TextArea::setFill(const RGB& newFill) { fill = newFill; }
void TextArea::setBorder(const RGB& newBorder) { border = newBorder; }

// darw function using X11
void TextArea::draw(Display* display, Window win, GC gc, int drawX, int drawY) {
    XSetForeground(display, gc, fill.getR() << 16 | fill.getG() << 8 | fill.getB());
    XFillRectangle(display, win, gc, drawX, drawY, width, height);
    
    XSetForeground(display, gc, border.getR() << 16 | border.getG() << 8 | border.getB());
    XDrawRectangle(display, win, gc, drawX, drawY, width, height);
    
    XDrawString(display, win, gc, drawX + 5, drawY + 15, text.c_str(), text.length());
}

// checking if two textareas overlap
bool TextArea::overlaps(const TextArea& ta) const {
    
    Rectangle r1;
    r1.x = x;
    r1.y = y;
    r1.width = width;
    r1.height = height;

    Rectangle r2;
    r2.x = ta.x;
    r2.y = ta.y;
    r2.width = ta.width;
    r2.height = ta.height;

    return r1.overlaps(r2);
}



// printing function
void TextArea::print() const {
    std::cout << "TextArea id: " << id << "\n"
              << "Preferred location: " << x << ", " << y << "\n"
              << "Size: " << width << " x " << height << "\n"
              << "Text: " << text << "\n" << std::endl;
}
