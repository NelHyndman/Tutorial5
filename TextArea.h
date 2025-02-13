#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <iostream>
#include <iomanip>
#include <string>
#include "RGB.h"
#include "defs.h"
#include <X11/Xlib.h>

class TextArea {
private:
    int x, y, width, height;
    std::string text;
    std::string id;
    RGB fill;
    RGB border;

public:
    TextArea(int x, int y, int width, int height, std::string id, std::string label);

    // constructior declarations
    TextArea(); 
    TextArea(const TextArea& other);  
    TextArea(const Rectangle& rect, const std::string& id, const std::string& text); // New constructor

    // getters
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    std::string getText() const;
    std::string getId() const;
    RGB getFill() const;
    RGB getBorder() const;

    // setters
    void setX(int newX);
    void setY(int newY);
    void setWidth(int newWidth);
    void setHeight(int newHeight);
    void setText(const std::string& newText);
    void setId(const std::string& newId);
    void setFill(const RGB& newFill);
    void setBorder(const RGB& newBorder);

    void draw(Display* display, Window win, GC gc, int drawX, int drawY);

    bool overlaps(const TextArea& ta) const;

    void print() const;
};

#endif 
