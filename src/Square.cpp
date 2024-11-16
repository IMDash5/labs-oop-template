#include <iostream>
#include <cmath>

#include "../include/Square.h"

template <isScalar T>
Square<T>::Square() : points(std::make_unique<Point<T>[]>(4)) {}

template <isScalar T>
Square<T>::Square(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4) : points(std::make_unique<Point<T>[]>(4)) {
    points[0] = p1; 
    points[1] = p2; 
    points[2] = p3; 
    points[3] = p4;
}

template <isScalar T>
Square<T>::Square(const Square<T> &other) : points(std::make_unique<Point<T>[]>(4)) {
    for (int i = 0; i < 4; ++i) {
        points[i] = other.points[i];
    }
}

template <isScalar T>
Square<T>& Square<T>::operator=(const Square<T> &other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            points[i] = other.points[i];
        }
    }
    return *this;
}

template <isScalar T>
Square<T>& Square<T>::operator=(Square<T> &&other) {
    if (this != &other) {
        points = std::move(other.points);
    }
    return *this;
}

template <isScalar T>
bool Square<T>::operator==(const Square<T> &other) {
    for (int i = 0; i < 4; ++i) {
        if (points[i] != other.points[i]) {
            return false;
        }
    }
    return true;
}

template <isScalar T>
double Square<T>::area() const {
    double side = std::sqrt(std::pow(points[1].x - points[0].x, 2) + std::pow(points[1].y - points[0].y, 2));
    return side * side;
}

template <isScalar T>
Square<T>::operator double() const {
    return area(); 
}

template <isScalar T>
Point<T> Square<T>::center() const {
    T centerX = (points[0].x + points[1].x + points[2].x + points[3].x) / 4;
    T centerY = (points[0].y + points[1].y + points[2].y + points[3].y) / 4;
    return Point<T>(centerX, centerY);
}