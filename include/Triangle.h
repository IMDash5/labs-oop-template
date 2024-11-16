#pragma once

#include "Figure.h"

#include <iostream>
#include <memory>

template <isScalar T>
class Triangle : public Figure<T>
{
    friend std::ostream& operator<<(std::ostream& os, const Triangle& triangle) {
        os << "Вершины треугольника: ";
        for (int i = 0; i < 3; ++i) {
            os << triangle.points[i] << " ";
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Triangle& triangle) {
        for (int i = 0; i < 3; ++i) {
            std::cout << "Введите координаты для вершины " << char('A' + i) << " (x, y): ";
            is >> triangle.points[i];
        }
        return is;
    }

    public:
        Triangle();
        Triangle(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3);
        Triangle(const Triangle &other);

        Triangle& operator = (const Triangle &other);
        Triangle& operator = (Triangle &&other) noexcept;
        bool operator == (const Triangle &other);

        operator double() const;
        double area() const;
        Point<T> center() const;

    private:
        std::unique_ptr<Point<T>[]> points;
};