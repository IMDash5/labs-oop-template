#include "figureArray.h"

#include <iostream>

Array::Array(int initialCapacity) : size(0), capacity(initialCapacity) {
    figures = new Figure*[capacity];
}

Array::~Array() {
    for (int i = 0; i < size; i++) {
        delete figures[i]; 
    }
    delete[] figures;
}

void Array::resize(int newCapacity) {
    Figure** newFigures = new Figure*[newCapacity];
    for (int i = 0; i < size; i++) {
        newFigures[i] = figures[i];
    }
    delete[] figures;
    figures = newFigures;
    capacity = newCapacity;
}

void Array::addFigure(Figure* figure) {
    if (size >= capacity) {
        resize(capacity * 2);
    }
    figures[size++] = figure;
}

void Array::printFigures() const {
    for (int i = 0; i < size; i++) {
        std::cout << "Фигура " << (i + 1) << ": Центр = (" 
                  << figures[i]->center().x << ", " 
                  << figures[i]->center().y << "), Площадь = " 
                  << figures[i]->area() << std::endl;
    }
}

double Array::totalArea() const {
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += figures[i]->area();
    }
    return total;
}

void Array::removeFigure(int index) {
    if (index < 0 || index >= size) {
        std::cerr << "Ошибка: индекс вне диапазона." << std::endl;
        return;
    }
    delete figures[index];
    for (int i = index; i < size - 1; i++) {
        figures[i] = figures[i + 1];
    }
    size--;
}