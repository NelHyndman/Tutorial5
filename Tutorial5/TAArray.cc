#include "TAArray.h"
#include <iostream>

TAArray::TAArray() : TAArray(10) {} // Default capacity of 10
TAArray::TAArray(int cap) : capacity(cap), size(0) {
    array = new TextArea*[capacity];
}

//destructor
TAArray::~TAArray() {
    for (int i = 0; i < size; i++) {
        delete array[i];
    }
    delete[] array;
}

// the add function to add TextArea to the back 
void TAArray::add(TextArea* textArea) {
    if (size < capacity) {
        array[size++] = textArea;
    } else {
        std::cerr << "Array is full, cannot add more TextAreas." << std::endl;
    }
}

//add function to add TextArea at a specific index we want
bool TAArray::add(TextArea* textArea, int index) {
    if (index < 0 || index > size || size >= capacity) {
        return false; // if invalid or full array
    }
    // shifting to make space
    for (int i = size; i > index; --i) {
        array[i] = array[i - 1];
    }
    array[index] = textArea;
    size++;
    return true;
}

// get function for testing 
TextArea* TAArray::get(int index) const {
    if (index < 0 || index >= size) {
        return nullptr;
    }
    return array[index];
}

// getting by ID
TextArea* TAArray::get(const std::string& id) const {
    for (int i = 0; i < size; i++) {
        if (array[i] && array[i]->getId() == id) {
            return array[i];
        }
    }
    return nullptr;
}

// removing by index
TextArea* TAArray::remove(int index) {
    if (index < 0 || index >= size) {
        return nullptr;
    }
    TextArea* removed = array[index]; // Save pointer to return
    for (int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
    return removed;
}

TextArea* TAArray::remove(const std::string& id) {
    for (int i = 0; i < size; i++) {
        if (array[i] && array[i]->getId() == id) {
            return remove(i);
        }
    }
    return nullptr;
}


// find the current size of the array
int TAArray::getSize() const {
    return size;
}
