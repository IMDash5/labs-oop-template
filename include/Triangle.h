#pragma once

#include "Figure.h"

#include <iostream>

class Triangle : public Figure
{
    friend std::ostream& operator << (std::ostream& os, const Triangle& triangle);
    friend std::istream& operator >> (std::istream& is, Triangle& triangle);

    public:
        Triangle();
        Triangle(Point& p1, Point& p2, Point& p3);
        Triangle(const Triangle &other);

        Triangle& operator = (const Triangle &other);
        Triangle& operator = (Triangle &&other)noexcept;
        bool operator == (const Triangle &other);

        operator double() const;
        double area() const;
        Point center() const;

        std::ostream& print(std::ostream& os)const override;
        std::istream& input(std::istream& is)override;

    private:
        Point a;
        Point b;
        Point c;
};