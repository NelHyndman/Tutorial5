#ifndef RGB_H
#define RGB_H

class RGB {
public:
    //the cosntructor
    RGB(int r = 0, int g = 0, int b = 0);

    //getters
    int getR() const;
    int getG() const;
    int getB() const;

    //setters
    void setRed(int r);
    void setGreen(int g);
    void setBlue(int b);

    // functions for commonly used colors
    static RGB WHITE();
    static RGB BLACK();
    static RGB RED();
    static RGB GREEN();
    static RGB BLUE();

private:
    int red, green, blue;
};

#endif 
