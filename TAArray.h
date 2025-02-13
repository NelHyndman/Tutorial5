// TAArray.h
#ifndef TAARRAY_H
#define TAARRAY_H

#include "TextArea.h"
#include <string>

class TAArray {
private:
    TextArea** array; // Dynamically allocated array of TextArea pointers
    int capacity;
    int size;

public:
    //construc
    TAArray(); // Default constructor
    TAArray(int cap);
    
    //destruct
    ~TAArray();

    // adds TextArea to the back of our array
    void add(TextArea* textArea);

    // adds TextArea at a wanted index
    bool add(TextArea* textArea, int index);

    TextArea* get(int index) const;
    TextArea* get(const std::string& id) const;

    // remioval function
    TextArea* remove(int index);
    TextArea* remove(const std::string& id);


    // current size of array
    int getSize() const;
};

#endif
