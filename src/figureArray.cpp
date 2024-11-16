#include "figureArray.h"

#include <iostream>
#include <memory>

template <typename T>
Array<T>::Array(int initialCapacity) : size(0), capacity(initialCapacity) {
    figures = std::make_unique<std::shared_ptr<T>[]>(capacity);
}
template <typename T>
Array<T>::~Array() = default;

template <typename T>
void Array<T>::resize(int newCapacity) {
    auto newFigures = std::make_unique<std::shared_ptr<T>[]>(newCapacity);
    for (int i = 0; i < size; ++i) {
        newFigures[i] = std::move(figures[i]);
    }
    capacity = newCapacity;
    figures = std::move(newFigures);
}

template <typename T>
void Array<T>::addFigure(std::shared_ptr<T> figure) {
    if (size >= capacity) {
        resize(capacity * 2);
    }
    figures[size++] = std::move(figure);
}

template <typename T>
void Array<T>::printFigures() const {
    for (int i = 0; i < size; i++) {
        std::cout << "Фигура " << (i + 1) << ": Центр = (" 
                  << figures[i]->center().x << ", " 
                  << figures[i]->center().y << "), Площадь = " 
                  << figures[i]->area() << std::endl;
    }
}

template <typename T>
double Array<T>::totalArea() const {
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += figures[i]->area();
    }
    return total;
}
template <typename T>
void Array<T>::removeFigure(int index) {
    if (index < 0 || index >= size) {
        std::cerr << "Ошибка: индекс вне диапазона." << std::endl;
        return;
    }
    figures[index].reset();
    for (int i = index; i < size - 1; ++i) {
        figures[i] = std::move(figures[i + 1]);
    }
    --size;
}