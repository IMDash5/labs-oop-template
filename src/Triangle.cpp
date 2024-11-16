#include <iostream>
#include <cmath>
#include <memory>

#include "../include/Triangle.h"

template <isScalar T>
Triangle<T>::Triangle() : points(std::make_unique<Point<T>[]>(3)) {}

template <isScalar T>
Triangle<T>::Triangle(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3) : points(std::make_unique<Point<T>[]>(3)) {
    points[0] = p1; 
    points[1] = p2; 
    points[2] = p3; 
}

template <isScalar T>
Triangle<T>::Triangle(const Triangle<T> &other) : points(std::make_unique<Point<T>[]>(3)) {
    for (int i = 0; i < 3; ++i) {
        points[i] = other.points[i];
    }
}

template <isScalar T>
Triangle<T>& Triangle<T>::operator=(const Triangle<T> &other) {
    if (this != &other) {
        points = std::make_unique<Point<T>[]>(3);
        for (int i = 0; i < 3; ++i) {
            points[i] = other.points[i];
        }
    }
    return *this;
}

template <isScalar T>
Triangle<T>& Triangle<T>::operator=(Triangle<T> &&other) noexcept {
    if (this != &other) {
        points = std::move(other.points);
    }
    return *this;
}

template <isScalar T>
bool Triangle<T>::operator==(const Triangle<T> &other) {
    for (int i = 0; i < 3; ++i) {
        if (points[i] != other.points[i]) {
            return false;
        }
    }
    return true;
}

template <isScalar T>
double Triangle<T>::area() const {
    double ab = std::sqrt(std::pow(points[1].x - points[0].x, 2) + std::pow(points[1].y - points[0].y, 2));
    double ac = std::sqrt(std::pow(points[2].x - points[0].x, 2) + std::pow(points[2].y - points[0].y, 2));
    double bc = std::sqrt(std::pow(points[2].x - points[1].x, 2) + std::pow(points[2].y - points[1].y, 2));
    
    double s = (ab + ac + bc) / 2;
    return std::sqrt(s * (s - ab) * (s - ac) * (s - bc));
}

template <isScalar T>
Triangle<T>::operator double() const {
    return area(); 
}

template <isScalar T>
Point<T> Triangle<T>::center() const {
    T centerX = (points[0].x + points[1].x + points[2].x) / 3;
    T centerY = (points[0].y + points[1].y + points[2].y) / 3;
    return Point<T>(centerX, centerY);
}
