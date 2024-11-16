#pragma once

#include "Figure.h"

#include <iostream>
#include <memory>

template <isScalar T>
class Octagon : public Figure<T>
{
    friend std::ostream& operator<<(std::ostream& os, const Octagon<T>& octagon) {
        os << "Вершины восьмиугольника: ";
        for (int i = 0; i < 8; ++i) {
            os << octagon.points[i] << " ";
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Octagon<T>& octagon) {
        std::cout << "Введите координаты для вершин (x, y):\n";
        for (int i = 0; i < 8; ++i) {
            std::cout << "Вершина " << i + 1 << ": ";
            is >> octagon.points[i];
        }
        return is;
    }

    public:
        Octagon();
        Octagon(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4, const Point<T>& p5, const Point<T>& p6, const Point<T>& p7, const Point<T>& p8);
        Octagon(const Octagon &other);

        Octagon& operator = (const Octagon &other);
        Octagon& operator = (Octagon &&other);
        bool operator == (const Octagon &other);

        operator double() const;
        double area() const override;
        Point<T> center() const;

    private:
        std::unique_ptr<Point<T>[]> points;
};