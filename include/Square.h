#pragma once

#include "Figure.h"

#include <iostream>
#include <memory>

template <isScalar T>
class Square : public Figure<T>
{
    friend std::ostream& operator<<(std::ostream& os, const Square& square) {
        os << "Вершины квадрата: ";
        for (int i = 0; i < 4; ++i) {
            os << square.points[i] << " ";
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Square& square) {
        for (int i = 0; i < 4; ++i) {
            std::cout << "Введите координаты для вершины " << char('A' + i) << " (x, y): ";
            is >> square.points[i];
        }
        return is;
    }

    public:
        Square();
        Square(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4);
        Square(const Square &other);

        Square& operator = (const Square &other);
        Square& operator = (Square &&other);
        bool operator == (const Square &other);

        operator double() const;
        double area() const override;
        Point<T> center() const;

    private:
        std::unique_ptr<Point<T>[]> points;
};