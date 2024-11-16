#include <iostream>
#include <cmath>

#include "../include/Octagon.h"

template <isScalar T>
Octagon<T>::Octagon() : points(std::make_unique<Point<T>[]>(8)) {}

template <isScalar T>
Octagon<T>::Octagon(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4, const Point<T>& p5, const Point<T>& p6, const Point<T>& p7, const Point<T>& p8)
    : points(std::make_unique<Point<T>[]>(8)) {
    points[0] = p1; 
    points[1] = p2; 
    points[2] = p3; 
    points[3] = p4;
    points[4] = p5; 
    points[5] = p6; 
    points[6] = p7; 
    points[7] = p8;
}


template <isScalar T>
Octagon<T>::Octagon(const Octagon& other) : points(std::make_unique<Point<T>[]>(8)) {
    for (int i = 0; i < 8; ++i) {
        points[i] = other.points[i];
    }
}

template <isScalar T>
Octagon<T>& Octagon<T>::operator=(const Octagon<T>& other) {
    if (this != &other) {
        for (int i = 0; i < 8; ++i) {
            points[i] = other.points[i];
        }
    }
    return *this;
}

template <isScalar T>
Octagon<T>& Octagon<T>::operator=(Octagon<T>&& other) {
    if (this != &other) {
        points = std::move(other.points);
    }
    return *this;
}

template <isScalar T>
bool Octagon<T>::operator==(const Octagon<T>& other) {
    for (int i = 0; i < 8; ++i) {
        if (points[i] != other.points[i]) {
            return false;
        }
    }
    return true;
}

template <isScalar T>
double Octagon<T>::area() const {
    double area = 0.0;
    for (int i = 0; i < 8; ++i) {
        int j = (i + 1) % 8;
        area += points[i].x * points[j].y;
        area -= points[i].y * points[j].x;
    }
    return std::fabs(area) / 2.0;
}

template <isScalar T>
Octagon<T>::operator double() const {
    return area();
}

template <isScalar T>
Point<T> Octagon<T>::center() const {
    double centerX = 0.0;
    double centerY = 0.0;
    for (int i = 0; i < 8; ++i) {
        centerX += points[i].x;
        centerY += points[i].y;
    }
    centerX /= 8.0;
    centerY /= 8.0;
    return Point<T>(centerX, centerY);
}