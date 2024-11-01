#pragma once

#include "Figure.h"

#include <iostream>

class Square : public Figure
{
    friend std::ostream& operator << (std::ostream& os, const Square& square);
    friend std::istream& operator >> (std::istream& is, Square& square);

    public:
        Square();
        Square(Point& p1, Point& p2, Point& p3, Point& p4);
        Square(const Square &other);

        Square& operator = (const Square &other);
        Square& operator = (Square &&other);
        bool operator == (const Square &other);

        operator double() const;
        double area() const override;
        Point center() const;

    protected:
        std::ostream& print(std::ostream& os)const override;
        std::istream& input(std::istream& is)override;

    private:
        Point a, b, c, d;
};