#include "Figure.h"

#include <iostream>
#include <memory>

template <typename T>
class Array {
    private:
        std::unique_ptr<std::shared_ptr<T>[]>figures;
        int size;
        int capacity;

        void resize(int newCapacity);

    public:
        Array(int initialCapacity = 3); 

        void addFigure(std::shared_ptr<T> figure); 
        void printFigures() const;
        double totalArea() const;
        void removeFigure(int index);

        ~Array();
};
