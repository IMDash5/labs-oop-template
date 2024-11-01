#pragma once

#include "Figure.h"

#include <iostream>

class Octagon : public Figure
{
    friend std::ostream& operator << (std::ostream& os, const Octagon& octagon);
    friend std::istream& operator >> (std::istream& is, Octagon& octagon);

    public:
        Octagon();
        Octagon(Point& p1, Point& p2, Point& p3, Point& p4, Point& p5, Point& p6, Point& p7, Point& p8);
        Octagon(const Octagon &other);

        Octagon& operator = (const Octagon &other);
        Octagon& operator = (Octagon &&other);
        bool operator == (const Octagon &other);

        operator double() const;
        double area() const override;
        Point center() const;

        std::ostream& print(std::ostream& os)const override;
        std::istream& input(std::istream& is)override;

    private:
        Point a;
        Point b;
        Point c;
        Point d;
        Point e;
        Point f;
        Point g;
        Point h;
};