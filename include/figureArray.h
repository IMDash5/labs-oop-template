#include "Figure.h"

#include <iostream>

class Array {
    private:
        Figure** figures;
        int size;
        int capacity;

        void resize(int newCapacity);

    public:
        Array(int initialCapacity = 3); 

        void addFigure(Figure* figure); 
        void printFigures() const;
        double totalArea() const;
        void removeFigure(int index);

        ~Array();
};
