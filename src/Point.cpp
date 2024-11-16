#include "../include/Point.h"

template <isScalar T>
Point<T>::Point() : x{0}, y{0} {}

template <isScalar T>
Point<T>::Point(T x, T y): x{x}, y{y} {}

template <isScalar T>
Point<T>::Point(const Point &other) : x(other.x), y(other.y) {}

template <isScalar T>
Point<T>& Point<T>::operator=(const Point& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

template <isScalar T>
Point<T>& Point<T>::operator=(Point&& other) {
    x = other.x;
    y = other.y;

    return *this;
}

template <isScalar T>
Point<T> Point<T>::operator + (const Point &other) const{
    return Point(x + other.x, y + other.y);
}

template <isScalar T>
Point<T> Point<T>::operator - (const Point &other) const{
    return Point(x - other.x, y - other.y);
}

template <isScalar T>
bool Point<T>::operator == (const Point &other) const{
    return (x == other.x) && (y == other.y);
}


